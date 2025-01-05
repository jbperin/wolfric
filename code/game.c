
#include "loader/loader_api.h"
#include "rom/myRom.h"
#include "rom/keyboard.h"
#include "constants.h"
#include "scene/scene.h"
#include "util.h"
#include "raycast/raycast.h"
#include "engine/engine.h"
#define ROT_ANGLE_STEP 16

unsigned char health          = 100;
unsigned char score           = 0;
unsigned char level           = 1;
unsigned char lives           = 3;
unsigned char ammo            = 8;

extern unsigned char texture_gun[];

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
    } else if (c == KEY_1) {
        LoadFileAt(LOADER_FG_KNIFE, texture_gun);
    } else if (c == KEY_2) {
        if (ammo != 0) {
            LoadFileAt(LOADER_FG_GUN, texture_gun);
        }
    } else if (c == KEY_SPACE) {
    } else if (c == KEY_E) {
        if (ammo !=0) ammo--;
        if (ammo == 0) {
            LoadFileAt(LOADER_FG_KNIFE, texture_gun);
        }
    } else if (c == KEY_LEFT_CONTROL) {
        if (ammo !=0) ammo--;
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

    health          = 100;
    score           = 0;
    level           = 1;
    lives           = 3;
    ammo            = 8;

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



    *((unsigned char*)0xBF95) = (unsigned char)0x30+level;
    *((unsigned char*)0xBFBD) = (unsigned char)0x30+level; // *((int*)0xBFA0);

    PRINTN(9,26,score);
    PRINTN(9,27,score);

    *((unsigned char*)0xBFA0) = (unsigned char)0x30+lives;
    *((unsigned char*)0xBFC8) = (unsigned char)0x30+lives; // *((int*)0xBFA0);

    PRINTN(24,26,health);
    PRINTN(24,27,health);


    PRINTN(29,26,ammo);
    PRINTN(29,27,ammo);
    *((unsigned char*)0xBFD5) = (unsigned char)0x0A;
    *((unsigned char*)0xBFAD) = (unsigned char)0x0A; // *((int*)0xBFA0);
    *((unsigned char*)0xBFD8) = (unsigned char)0x09;
    *((unsigned char*)0xBFB0) = (unsigned char)0x09; // *((int*)0xBFA0);
 
}
