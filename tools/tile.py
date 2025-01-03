import argparse
from PIL import Image, ImageSequence
import os
import math

# Couleur de remplacement par défaut
REPLACEMENT_COLOR = (152, 0, 136)

def color_distance(c1, c2):
    """Calcule la distance Euclidienne entre deux couleurs RGB."""
    return math.sqrt((c1[0] - c2[0]) ** 2 + (c1[1] - c2[1]) ** 2 + (c1[2] - c2[2]) ** 2)

def replace_transparency_or_colors(image, target_colors_with_tolerance=None):
    # Convertir en mode RGBA si l'image n'a pas de canal alpha
    if image.mode != 'RGBA':
        image = image.convert('RGBA')
    
    pixels = image.load()
    width, height = image.size

    for y in range(height):
        for x in range(width):
            r, g, b, a = pixels[x, y]

            # Remplacer la transparence par la couleur cible
            if a == 0:
                pixels[x, y] = REPLACEMENT_COLOR + (255,)
            elif target_colors_with_tolerance:
                # Remplacer chaque couleur cible spécifiée par l'utilisateur en vérifiant la tolérance
                for target_color, tolerance in target_colors_with_tolerance:
                    if color_distance((r, g, b), target_color) <= tolerance:
                        pixels[x, y] = REPLACEMENT_COLOR + (255,)
                        break
    
    return image

def decoupe_image(image_path, rows, cols, target_colors_with_tolerance=None, skipgrid=1):
    # Charger l'image
    image = Image.open(image_path)
    
    # Vérifier si c'est une animation GIF
    is_animated = getattr(image, "is_animated", False)

    if is_animated:
        decoupe_gif(image, rows, cols, target_colors_with_tolerance, skipgrid)
    else:
        # Traiter une image statique
        image = replace_transparency_or_colors(image, target_colors_with_tolerance)

        img_width, img_height = image.size
        tile_width = (img_width - (cols - 1) * skipgrid) // cols
        tile_height = (img_height - (rows - 1) * skipgrid) // rows

        # Créer un dossier pour stocker les sous-images
        output_dir = f"{os.path.splitext(image_path)[0]}_tiles"
        os.makedirs(output_dir, exist_ok=True)

        # Découper l'image en sous-images
        for row in range(rows):
            for col in range(cols):
                left = col * (tile_width + skipgrid)
                upper = row * (tile_height + skipgrid)
                right = left + tile_width
                lower = upper + tile_height

                tile = image.crop((left, upper, right, lower))
                tile_filename = os.path.join(output_dir, f"tile_{row}_{col}.png")
                tile.save(tile_filename)
                print(f"Enregistré {tile_filename}")

        print("Découpage terminé pour l'image statique !")

def decoupe_gif(image, rows, cols, target_colors_with_tolerance=None, skipgrid=1):
    frames = [replace_transparency_or_colors(frame.convert("RGBA"), target_colors_with_tolerance) for frame in ImageSequence.Iterator(image)]
    
    img_width, img_height = frames[0].size
    tile_width = (img_width - (cols - 1) * skipgrid) // cols
    tile_height = (img_height - (rows - 1) * skipgrid) // rows

    # Créer un dossier pour stocker les GIFs découpés
    output_dir = f"{os.path.splitext(image.filename)[0]}_tiles"
    os.makedirs(output_dir, exist_ok=True)

    # Découper chaque frame pour chaque case de la grille
    for row in range(rows):
        for col in range(cols):
            # Créer une liste de frames pour la sous-GIF
            tile_frames = []
            for frame in frames:
                left = col * (tile_width + skipgrid)
                upper = row * (tile_height + skipgrid)
                right = left + tile_width
                lower = upper + tile_height
                tile_frame = frame.crop((left, upper, right, lower))
                tile_frames.append(tile_frame)

            # Enregistrer les frames comme une GIF animée
            tile_filename = os.path.join(output_dir, f"tile_{row}_{col}.gif")
            tile_frames[0].save(
                tile_filename,
                save_all=True,
                append_images=tile_frames[1:],
                duration=image.info['duration'],
                loop=image.info.get('loop', 0)
            )
            print(f"Enregistré {tile_filename}")

    print("Découpage terminé pour l'animation GIF !")

if __name__ == "__main__":
    # Utilisation de argparse pour capturer les arguments
    parser = argparse.ArgumentParser(description="Découper une image en une grille de sous-images.")
    parser.add_argument("image_path", type=str, help="Chemin vers l'image à découper")
    parser.add_argument("rows", type=int, help="Nombre de lignes dans la grille")
    parser.add_argument("cols", type=int, help="Nombre de colonnes dans la grille")
    parser.add_argument("--replace_color", type=int, nargs=4, action="append", metavar=("R", "G", "B", "TOLERANCE"),
                        help="Couleur à remplacer (sous forme de triplet RGB) suivie d'une tolérance. Peut être spécifiée plusieurs fois pour plusieurs couleurs.")
    parser.add_argument("-skipgrid", type=int, nargs="?", const=1, default=1,
                        help="Nombre de pixels à sauter entre les tuiles (par défaut : 1).")

    args = parser.parse_args()

    # Extraire les couleurs cibles et leurs tolérances
    target_colors_with_tolerance = [(tuple(color[:3]), color[3]) for color in args.replace_color] if args.replace_color else None

    # Exécuter la fonction de découpage
    decoupe_image(args.image_path, args.rows, args.cols, target_colors_with_tolerance, args.skipgrid)
