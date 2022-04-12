



from PIL import Image
import os
import argparse
import codegen


def pattern2value (pattern):
    powa, res = 32, 0
    for v in pattern:
        if (v > 5):
            res += powa
        powa = powa//2
    return res



class AltCharExtractor:

    def __init__(self,imagefile):

        # Image buffer 
        self.bufimgtranslat = None
        # list of characters pattern indexed by character coordinates on image
        self.characterlist = None
        # list of unique character pattern
        self.list_unique_char_pattern = []
        # list of index in list_unique_char_pattern indexed by character coordinates on image
        self.affectation = {}

        im1 = Image.open(imagefile)

        rgb_im = im1.convert('RGB')

        self.bufimgtranslat = []
        imw, imh = im1.width, im1.height
        for ii in range (imh):
            self.bufimgtranslat.append ([])
            for jj in range (imw): 
                r, g, b = rgb_im.getpixel((jj, ii))
                texel_value = (r//85)*16 + (g//85)*4 + (b//85)
                self.bufimgtranslat[-1].append (texel_value) 
        
        # for li in self.bufimgtranslat:
        #     print (li)


    def extractFromArea(self, lines, cols):
        pattlist = []
        self.characterlist = {}
        
        for idx_li in lines:
            for idx_col in cols:
                lin, col = idx_li*8, idx_col*6
                self.characterlist[(idx_li, idx_col)] = []
                for ii in range (8):
                    sixbits = self.bufimgtranslat[lin+ii][col:col+6]
                    pattlist.append ((idx_li, idx_col, sixbits))
                    self.characterlist[(idx_li, idx_col)].append(sixbits)
                if (self.characterlist[(idx_li, idx_col)] not in self.list_unique_char_pattern): 
                    self.list_unique_char_pattern.append (self.characterlist[(idx_li, idx_col)])
        print (self.characterlist)
        print (self.list_unique_char_pattern)

        for ke in self.characterlist.keys():
            self.affectation[ke] = self.list_unique_char_pattern.index(self.characterlist[ke])

    def export2C (self, st_num_char = 33):
        res = ""
        num_char = st_num_char
        for cha in self.list_unique_char_pattern:
            res += f"change_char({num_char} "
            for pat in cha:
                res += ", 0x%x"%(pattern2value(pat))
                # print (sixbits, )
            res += ");\n"
            num_char +=1
        # print (self.affectation)
        res += "\n\n"

        
        for k,v in self.affectation.items():
            res += f"*((unsigned char *)0xbf68+{k[0]}*40+{k[1]})={v+st_num_char};\n"
        return (res)

        # print (list(self.characterlist.values()))
        # list_unique_char_pattern=[]
        # for v in list(self.characterlist.values()):
        #     if v not in list_unique_char_pattern:
        #         list_unique_char_pattern.append (v)

        # print (list_unique_char_pattern)


def main (arguments):
        
    parser = argparse.ArgumentParser(
        prog='extractAltCharset'
        , description='Picture alternate character extractor for Castoric'
        , epilog = '''For exemple:
            extractAltCharset imgfile
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

    SOURCE_SQUARE_SIZE = 24
    # DESTINATION_SQUARE_SIZE = 32
    POS_X, POS_Y = 96,0
    im1 = im
    # .crop((POS_X , POS_Y , (POS_X+SOURCE_SQUARE_SIZE) , (POS_Y+SOURCE_SQUARE_SIZE)))
    # .resize((DESTINATION_SQUARE_SIZE, DESTINATION_SQUARE_SIZE))
    #newsize = (300, 300)
    # im1.save(f"{namerad}_{POS_X}_{POS_Y}.bmp")

    rgb_im = im1.convert('RGB')


    bufimgtranslat = []
    imw, imh = im1.width, im1.height
    for ii in range (imh):
        bufimgtranslat.append ([])
        for jj in range (imw): 
            r, g, b = rgb_im.getpixel((jj, ii))
            texel_value = (r//85)*16 + (g//85)*4 + (b//85)
            bufimgtranslat[-1].append (texel_value) 
    for li in bufimgtranslat:
        print (li)

    num_char = 33
    print ("// premiere ligne")
    for idx_li in [0]:
        for idx_col in range(1,38):
            lin, col, pattlist = idx_li*8, idx_col*6, f"change_char({num_char} "
            for ii in range (8):
                sixbits = bufimgtranslat[lin+ii][col:col+6]
                pattlist += ", 0x%x"%(pattern2value(sixbits))
                # print (sixbits, )
            pattlist += ");"

            print (pattlist)
            num_char +=1

    print ("// bas")
    for idx_li in [1, 2]:
        for idx_col in [16, 17, 18, 19]:
            lin, col, pattlist = idx_li*8, idx_col*6, f"change_char({num_char} "
            for ii in range (8):
                sixbits = bufimgtranslat[lin+ii][col:col+6]
                pattlist += ", 0x%x"%(pattern2value(sixbits))
                # print (sixbits, )
            pattlist += ");"

            print (pattlist)
            num_char +=1




    print ("// gun")
    for idx_li in [1, 2]:
        for idx_col in [33, 34, 35, 36, 37]:
            lin, col, pattlist = idx_li*8, idx_col*6, f"change_char({num_char} "
            for ii in range (8):
                sixbits = bufimgtranslat[lin+ii][col:col+6]
                pattlist += ", 0x%x"%(pattern2value(sixbits))
                # print (sixbits, )
            pattlist += ");"

            print (pattlist)
            num_char +=1


    print ("// colonne 1")
    for idx_li in [1, 2]:
        for idx_col in [5]:
            lin, col, pattlist = idx_li*8, idx_col*6, f"change_char({num_char} "
            for ii in range (8):
                sixbits = bufimgtranslat[lin+ii][col:col+6]
                pattlist += ", 0x%x"%(pattern2value(sixbits))
                # print (sixbits, )
            pattlist += ");"

            print (pattlist)
            num_char +=1

    print ("// colonne 2")
    for idx_li in [1, 2]:
        for idx_col in [12]:
            lin, col, pattlist = idx_li*8, idx_col*6, f"change_char({num_char} "
            for ii in range (8):
                sixbits = bufimgtranslat[lin+ii][col:col+6]
                pattlist += ", 0x%x"%(pattern2value(sixbits))
                # print (sixbits, )
            pattlist += ");"

            print (pattlist)
            num_char +=1

    print ("// colonne 3")
    for idx_li in [1, 2]:
        for idx_col in [20]:
            lin, col, pattlist = idx_li*8, idx_col*6, f"change_char({num_char} "
            for ii in range (8):
                sixbits = bufimgtranslat[lin+ii][col:col+6]
                pattlist += ", 0x%x"%(pattern2value(sixbits))
                # print (sixbits, )
            pattlist += ");"

            print (pattlist)
            num_char +=1

    print ("// colonne 4")
    for idx_li in [1, 2]:
        for idx_col in [26]:
            lin, col, pattlist = idx_li*8, idx_col*6, f"change_char({num_char} "
            for ii in range (8):
                sixbits = bufimgtranslat[lin+ii][col:col+6]
                pattlist += ", 0x%x"%(pattern2value(sixbits))
                # print (sixbits, )
            pattlist += ");"

            print (pattlist)
            num_char +=1



        # print (bufimgtranslat[lin+ii][col:col+6], "%x"%(pattern2value(bufimgtranslat[1][0:6])))
        # print (bufimgtranslat[lin+ii][col:col+6])
    # cCode = codegen.buffer2cCode("texture_"+f"{namerad}_{POS_X}_{POS_Y}", "unsigned char", bufimgtranslat)
    # with open ("texture_"+f"{namerad}_{POS_X}_{POS_Y}.c", "w") as ficout:
    #     ficout.write (cCode)
        
    # print (cCode)

    
##
##    imw, imh = im.width, im.height
##
##    bufimgtranslat = []
##
##    for ii in range (imw):
##        for jj in range (imh):    
##            pass

if __name__ == '__main__':
    # main('C:\\Perso\\myCode\\wolfric\\data\\bottom_panel.bmp'.split())

    ACE = AltCharExtractor('C:\\Perso\\myCode\\wolfric\\data\\bottom_panel.bmp')
    ACE.extractFromArea([0],list(range(3,40)))
    ACE.extractFromArea([0,1,2],[7])
    ACE.extractFromArea([0,1,2],[14])
    ACE.extractFromArea([0,1,2],[18, 19, 20, 21, 22])
    ACE.extractFromArea([0,1,2],[28])
    ACE.extractFromArea([0,1,2],[32, 33, 34, 35, 36, 37, 38, 39])
    print (ACE.export2C(33))
    #main (sys.argv[1:])

