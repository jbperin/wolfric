import os
import argparse
import math
from PIL import Image, ImageEnhance
import codegen

def image2TextureBuf(filepathname, name, frame_number):
    base = os.path.basename(filepathname)
    namerad = os.path.splitext(base)[0] if name is None else name
    im = Image.open(filepathname)
    rgb_im = im.convert('RGB')
    imw, imh = im.width, im.height
    bufimgtranslat = []

    for ii in range(imw):
        for jj in range(imh):    
            # Convertit chaque pixel en valeur texel
            r, g, b = rgb_im.getpixel((ii, jj))
            texel_value = (r // 64) * 16 + (g // 64) * 4 + (b // 64)
            bufimgtranslat.append(texel_value)

    # Génère le code C en incluant le numéro de la trame dans le nom
    cCode = codegen.buffer2cCode(f"texture_{namerad}_{frame_number}", "unsigned char", bufimgtranslat)
    return cCode

def color_distance(c1, c2):
    # Calcule la distance euclidienne entre deux couleurs RGB
    return math.sqrt((c1[0] - c2[0]) ** 2 + (c1[1] - c2[1]) ** 2 + (c1[2] - c2[2]) ** 2)

def process_animation(image_path, output_folder, replace_colors, name=None, frame_selection=None):
    # Crée le dossier de sortie si nécessaire
    if not os.path.exists(output_folder):
        os.makedirs(output_folder)
    
    # Récupère le nom de base du fichier d'entrée sans l'extension
    base_name = os.path.splitext(os.path.basename(image_path))[0] if name is None else name
    
    # Couleur de remplacement pour la transparence et les couleurs proches
    replacement_color = (152, 0, 136, 255)
    
    # Charge le fichier (GIF ou WebP) et initialise le compteur de trame
    with Image.open(image_path) as img:
        frame_count = img.n_frames
        selected_frames = []

        if isinstance(frame_selection, int):
            # Distribution équitable des frames pour le traitement
            selected_frames = [int(i * frame_count / frame_selection) for i in range(frame_selection)]
        elif isinstance(frame_selection, list):
            selected_frames = frame_selection
        else:
            selected_frames = range (frame_count)

        frame_number = 0
        try:
            while frame_number < frame_count:
                # Vérifie si la frame actuelle doit être traitée
                if frame_number in selected_frames:

                    # Charge la trame actuelle
                    frame = img.convert("RGBA")  # Convertir en RGBA pour gérer la transparence

                    # Appliquer l'ajustement de contraste (commenté selon les instructions)
                    # enhancer = ImageEnhance.Contrast(frame)
                    # frame = enhancer.enhance(1.5)  # Augmente le contraste par 1.5x (ajustable)

                    # Remplace la transparence et les couleurs proches par la couleur de remplacement
                    frame_data = frame.getdata()
                    new_frame_data = []
                    for (r, g, b, a) in frame_data:
                        # Remplacement de la transparence
                        if a == 0:
                            new_frame_data.append(replacement_color)
                        else:
                            # Remplacement des couleurs proches spécifiées
                            replaced = False
                            for target_color, tolerance in replace_colors:
                                if color_distance((r, g, b), target_color) <= tolerance:
                                    new_frame_data.append(replacement_color)
                                    replaced = True
                                    break
                            if not replaced:
                                new_frame_data.append((r, g, b, a))

                    # Crée une nouvelle image avec les couleurs modifiées
                    new_frame = Image.new("RGBA", frame.size)
                    new_frame.putdata(new_frame_data)

                    # Redimensionne en 32x32 pixels
                    new_frame = new_frame.resize((32, 32), Image.LANCZOS)

                    # Convertir en mode RGB avant de sauvegarder en BMP
                    bmp_frame = new_frame.convert("RGB")

                    # Sauvegarde la trame au format BMP en utilisant le nom de fichier d'entrée ou le nom personnalisé
                    output_path = os.path.join(output_folder, f"{base_name}_frame_{frame_number}.bmp")
                    bmp_frame.save(output_path)

                    # Traitement de l'image avec image2TextureBuf pour générer le code C
                    c_code = image2TextureBuf(output_path, name, frame_number)
                    
                    # Affiche uniquement le code C
                    print(c_code)

                # Passer à la trame suivante
                frame_number += 1
                img.seek(frame_number)

        except EOFError:
            # Fin de l'animation atteinte
            print(f"{frame_number} frames processed and saved in {output_folder}")

# Fonction principale pour gérer les arguments de la ligne de commande
if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Traitement d'images animées avec remplacement de couleur")
    parser.add_argument("image_path", help="Chemin du fichier GIF ou WebP d'entrée")
    parser.add_argument("output_folder", help="Dossier de sortie")
    parser.add_argument("--replace_color", type=int, nargs=4, metavar=("R", "G", "B", "tolerance"),
                        action="append", help="Code RGB et tolérance de la couleur à remplacer (ex: --replace_color 255 255 255 30)")
    parser.add_argument("--name", type=str, help="Nom personnalisé pour les fichiers de sortie et le code C")
    frame_group = parser.add_mutually_exclusive_group()
    frame_group.add_argument("--fnum", type=int, help="Nombre de frames équitablement réparties à traiter")
    frame_group.add_argument("--flist", type=int, nargs="+", help="Liste des numéros de frames à traiter")

    args = parser.parse_args()
    
    # Préparer les couleurs de remplacement
    replace_colors = []
    if args.replace_color:
        for color in args.replace_color:
            r, g, b, tolerance = color
            replace_colors.append(((r, g, b), tolerance))
    
    # Définit la sélection de frames
    frame_selection = args.fnum if args.fnum is not None else args.flist
    
    process_animation(args.image_path, args.output_folder, replace_colors, name=args.name, frame_selection=frame_selection)
