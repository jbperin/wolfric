
#include "loader/loader_api.h"
#include "rom/myRom.h"
#include "rom/keyboard.h"
#include "constants.h"
#include "scene/scene.h"
#include "util.h"
#include "raycast/raycast.h"
#include "engine/engine.h"
#define ROT_ANGLE_STEP 16



void onKey(unsigned char c){
    if (c == KEY_UP) {
            forward(); 
    } else if (c == KEY_DOWN) {
            backward();
    } else if (c == KEY_LEFT) {
            rayCamRotZ      += ROT_ANGLE_STEP;
            RayLeftAlpha    = rayCamRotZ + HALF_FOV_FIX_ANGLE;
    } else if (c == KEY_RIGHT) {
            rayCamRotZ      -= ROT_ANGLE_STEP; 
            RayLeftAlpha    = rayCamRotZ + HALF_FOV_FIX_ANGLE;
    } else if (c == KEY_J) {
            shiftRight();
    } else if (c == KEY_H) {
            shiftLeft();
    } else if (c == KEY_SPACE) {
        ;
    } else if (c == KEY_E) {
        ;
    }
}

void onIT(){;}

void initCamera(){
    rayCamPosX               = 0;
    rayCamPosY               = 0; 
    rayCamRotZ               = 64;
    RayLeftAlpha            = rayCamRotZ + HALF_FOV_FIX_ANGLE;

}

extern unsigned char sprite_deadsoldier[];
extern unsigned char lamp_1[];
extern unsigned char soldier_back[];
extern unsigned char soldier_front[];
extern unsigned char soldier_left[];
extern unsigned char soldier_right[];
extern unsigned char pieceofmeat[];

signed  char doorData[] = {0, 36}; // state 0  36 = 17(point n17)*2 (2 coord/point) + 2 (header nbPoints + nbWall)
signed char soldierData [] = {0};


void gameInit(void){

    // LoadFileAt(LOADER_RAYTABLES, 0xED95);
	// LoadFileAt(BASIC_SCREEN, 0xBB80);
    //LoadFileAt(LOADER_CHARSET_STANDARD, 0xb400);
    LoadFileAt(LOADER_RAYTABLES, 0xEC00);
    // LoadFileAt(LOADER_TEXTURES_3, 0xc000);
    LoadFileAt(LOADER_TEXTURES, 0xc000);
    // LoadFileAt(LOADER_ANIM, 0xd800);
    LoadFileAt(LOADER_HRSCREEN, 0x9800);
	
    initCamera();

    initScene (scene_00, texture_00);

    engInitObjects();

    engObjType = OBJ_DEAD_SOLDIER;
    engObjX     = 0;
    engObjY     = 5;
    engObjData  = 0;
    engAddObjectASM();
    objTexture[0] = sprite_deadsoldier;

    engObjType = OBJ_LAMP;
    engObjX     = 0;
    engObjY     = 7;
    engObjData  = 0;
    engAddObjectASM();
    objTexture[1] = lamp_1;

    engObjType = OBJ_PIECE_OF_MEAT;
    engObjX     = 0;
    engObjY     = 9;
    engObjData  = 0;
    engAddObjectASM();
    objTexture[2] = pieceofmeat;

    engObjType = OBJ_SOLDIER;
    engObjX     = 2;
    engObjY     = 0;
    engObjData  = soldierData;
    engAddObjectASM();
    objTexture[3] = soldier_front;

    engObjType = OBJ_DOOR;
    engObjX     = 0;
    engObjY     = 21;
    engObjData  = doorData;
    engAddObjectASM();
    objTexture[4] = 0;


}

void gamePulse(void){

    dichoInit();
    engPulse();

    rayInitCasting();

    rayProcessPoints();
    rayProcessWalls();
    drawWalls();

}
