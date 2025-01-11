# Script to generate patch as advised by ibisum 
# https://forum.defence-force.org/viewtopic.php?p=31823#p31823
import argparse
import img2forgrnd
import os
from collections import defaultdict
def diffTextureBuf(imagesrcfile, imagedestfile, replace_colors=None, output_name=None):
    result = f"{output_name}:\n"
    buf_img_src = img2forgrnd.ImgToBuf(imagesrcfile, replace_colors)
    buf_img_dest = img2forgrnd.ImgToBuf(imagedestfile, replace_colors)
    diff_couples  = [(i, buf_img_dest[i]) for i in range(len(buf_img_src)) if buf_img_src[i] != buf_img_dest[i]]
    # print (diff_couples)
    diff_dict = defaultdict(list)
    for i, val in diff_couples:
        diff_dict[val].append(i)
    diff_dict = dict(diff_dict)
    # print (diff_dict)
    for key, value in diff_dict.items():
        result += (f"\tlda #{key}\n")
        for v in value:
            result += (f"\tsta _texture_gun+{v}\n")
    result += "\trts"
    return result
def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("imagesrcfile", help="origin")
    parser.add_argument("imagedestfile", help="destination")
    parser.add_argument(
        "--replace_color", nargs=4, action='append', type=int,
        metavar=('R', 'G', 'B', 'TOL'),
        help="RGB color and tolerance for color replacement. Can be used multiple times for different colors."
    )
    parser.add_argument(
        "--name", type=str, help="Optional name for the output buffer array."
    )

    args = parser.parse_args()

    # Transforme les couleurs et tolérances en liste de tuples
    replace_colors = [(tuple(color[:3]), color[3]) for color in args.replace_color] if args.replace_color else []

    print("// CAUTION !! GENERATED FILE. DO NOT MODIFY BY HAND")
    print("// patch generated to change from file : " + args.imagesrcfile + " to file " + args.imagedestfile)
    print("// by script : " + os.path.basename(__file__))
    print("// [ref texture_file2buffer]")
    if args.name is None:
        basesrc = os.path.basename(args.imagesrcfile)
        nameradsrc = os.path.splitext(basesrc)[0] if args.name is None else args.name
        basedest = os.path.basename(args.imagedestfile)
        nameraddest = os.path.splitext(basedest)[0] if args.name is None else args.name
        theName = f'_patch_{nameradsrc}_into_{nameraddest}'
    else:
        theName = f'_{args.name}'
    print(diffTextureBuf(args.imagesrcfile, args.imagedestfile, replace_colors=replace_colors, output_name=theName))


if __name__ == "__main__":
    # execute only if run as a script
    main()
