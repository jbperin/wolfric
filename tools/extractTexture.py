
from PIL import Image
import os
import argparse
import codegen

def main (arguments):
        
    parser = argparse.ArgumentParser(
        prog='extractTexture'
        , description='Picture texture extracter for Castoric'
        , epilog = '''For exemple:
            extractTexture imgfile
        '''
        )

    parser.add_argument('--single'
                        , action=argparse.BooleanOptionalAction
                        , default=False
                        , help="Initialise printer_out.txt"
                        )
    parser.add_argument("imagefile", help="file path and name of the texture (png or bmp) ")

    args = parser.parse_args(arguments)
    
    print("// texture buffer generated from file : " + args.imagefile)

    base=os.path.basename(args.imagefile)

    namerad = os.path.splitext(base)[0]


    
    im = Image.open(args.imagefile)

    SOURCE_SQUARE_SIZE = 128
    DESTINATION_SQUARE_SIZE = 32
    POS_X, POS_Y = 4,11
    im1 = im.crop((POS_X * SOURCE_SQUARE_SIZE+1, POS_Y * SOURCE_SQUARE_SIZE +1, (POS_X+1) * SOURCE_SQUARE_SIZE, (POS_Y+1) * SOURCE_SQUARE_SIZE)).resize((DESTINATION_SQUARE_SIZE, DESTINATION_SQUARE_SIZE))
    #newsize = (300, 300)
    im1.save(f"{namerad}_{POS_X}_{POS_Y}.bmp")

    rgb_im = im1.convert('RGB')


    bufimgtranslat = []
    imw, imh = im1.width, im1.height
    for ii in range (imw):
        for jj in range (imh):    
            ## [ref texel_codec]
            r, g, b = rgb_im.getpixel((ii, jj))
            texel_value = (r//85)*16 + (g//85)*4 + (b//85)
            bufimgtranslat.append(texel_value)

    cCode = codegen.buffer2cCode("texture_"+f"{namerad}_{POS_X}_{POS_Y}", "unsigned char", bufimgtranslat)
    with open ("texture_"+f"{namerad}_{POS_X}_{POS_Y}.c", "w") as ficout:
        ficout.write (cCode)
        
    print (cCode)

    
##
##    imw, imh = im.width, im.height
##
##    bufimgtranslat = []
##
##    for ii in range (imw):
##        for jj in range (imh):    
##            pass

if __name__ == '__main__':
    main('C:\\Perso\\myCode\\wolfric\\art\\sprites03.png'.split())
    #main (sys.argv[1:])

