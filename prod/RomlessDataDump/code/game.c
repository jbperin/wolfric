
#include "loader/loader_api.h"
#include "rom/myRom.h"

void onKey(unsigned char c){;}
void onIT(){;}

void gameInit(void){

	LoadFileAt(BASIC_SCREEN, 0xBB80);
    LoadFileAt(LOADER_CHARSET_STANDARD, 0xb400);

}

void gamePulse(void){

}
