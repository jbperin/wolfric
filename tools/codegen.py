
import struct

def buffer2asmCode(theName, theType, theBuffer):
    theCode = ""
    first = True
    nline = False
    for ii in range(len(theBuffer)):
        if nline == True:
            theCode += f"\n\t.byt "
            nline = False
        elif first:
            theCode += f"_{theName}\n\t.byt "
            first = False
        else:
            theCode += ", "
        if (theBuffer[ii] < 0):
            intv = struct.unpack('B',struct.pack("b", theBuffer[ii]))[0]
        else:
            intv = theBuffer[ii]
        theCode += f"{intv}"
        if ((ii+1) %16 == 0) and (ii != 0):
            # theCode += "\n\t.byt "
            nline = True

    return theCode



def buffer2cCode(theName, theType, theBuffer):
    theCode = ""
    first = True
    for ii in range(len(theBuffer)):
        if first:
            theCode += f"{theType} {theName}[] = {{\n\t"
            first = False
        else:
            theCode += ", "
        theCode += f"{theBuffer[ii]}"
        if ((ii+1) %16 == 0) and (ii != 0):
            theCode += "\n\t"
    theCode += "};\n"
    return theCode

def buffer2pyCode(theName, theBuffer):
    theCode = ""
    first = True
    for ii in range(len(theBuffer)):
        if first:
            theCode += f"{theName} = [\n\t"
            first = False
        else:
            theCode += ", "
        theCode += f"{theBuffer[ii]}"
        if ((ii+1) %16 == 0) and (ii != 0):
            theCode += "\n\t"
    theCode += "]\n"
    return theCode


def main ():
    pass

if __name__ == "__main__":
    # execute only if run as a script
    main()    
