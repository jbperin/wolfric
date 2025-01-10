
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

unsigned char openDoorRequest;
unsigned char shootRequest;
unsigned char sceneUpdateRequest;

signed  char door1Data[] = {
        0,      // state 0 : close,  1..6 : opening, 7: opened ,
        // Points to animate are indexes in scene data of coordinate to change
        26,     
        28,
        1,  // Direction to animate: 1 or -1
        0,  // Place holder for temporisation
        };    // 26 = 12(point n12)*2 (2 coord/point) + 2 (header nbPoints + nbWall)
signed  char door2Data[] = {
        0,      // state 0 : close,  1..6 : opening, 7: opened ,
        // Points to animate are indexes in scene data of coordinate to change
        38,     
        40,
        1,  // Direction to animate: 1 or -1
        0,  // Place holder for temporisation
        };    // 38 = 18(point n18)*2 (2 coord/point) + 2 (header nbPoints + nbWall)
signed  char door3Data[] = {
        0,      // state 0 : close,  1..6 : opening, 7: opened ,
        // Points to animate are indexes in scene data of coordinate to change
        48,     
        50,
        1,  // Direction to animate: 1 or -1
        0,  // Place holder for temporisation
        };    // 26 = 12(point n12)*2 (2 coord/point) + 2 (header nbPoints + nbWall)
signed  char door4Data[] = {
        0,      // state 0 : close,  1..6 : opening, 7: opened ,
        // Points to animate are indexes in scene data of coordinate to change
        58,     
        60,
        1,  // Direction to animate: 1 or -1
        0,  // Place holder for temporisation
        };    // 26 = 12(point n12)*2 (2 coord/point) + 2 (header nbPoints + nbWall)
signed  char door5Data[] = {
        0,      // state 0 : close,  1..6 : opening, 7: opened ,
        // Points to animate are indexes in scene data of coordinate to change
        68,     
        70,
        1,  // Direction to animate: 1 or -1
        0,  // Place holder for temporisation
        };    // 26 = 12(point n12)*2 (2 coord/point) + 2 (header nbPoints + nbWall)






signed char soldier1Data [] = {
    1,          // state: 0=dead, 1=walking, 
    0,          // direction
    4,          // health
    };

extern unsigned char texture_gun[];
extern unsigned char texture_ammo_1[];
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
        openDoorRequest = 1;
    } else if (c == KEY_E) {
        if (ammo !=0) {
            ammo--;
            shootRequest = 1;
        }
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

    health              = 100;
    score               = 0;
    level               = 1;
    lives               = 3;
    ammo                = 8;

    openDoorRequest     = 0;
    sceneUpdateRequest  = 0;
    shootRequest        = 0;

    engInitObjects();

    engObjType = OBJ_DEAD_SOLDIER;
    engObjX     = 0;
    engObjY     = 10;
    engObjData  = 0;
    engAddObjectASM();
    objTexture[0] = sprite_deadsoldier;

    engObjType = OBJ_LAMP;
    engObjX     = 0;
    engObjY     = 27;
    engObjData  = 0;
    engAddObjectASM();
    objTexture[1] = lamp_1;

    engObjType = OBJ_PIECE_OF_MEAT;
    engObjX     = 28;
    engObjY     = 27;
    engObjData  = 0;
    engAddObjectASM();
    objTexture[2] = pieceofmeat;

    engObjType = OBJ_SOLDIER;
    engObjX     = -10; // 2; // 
    engObjY     = 27; // 0; // 
    engObjData  = soldier1Data;
    engAddObjectASM();
    objTexture[3] = soldier_front;

    engObjType = OBJ_DOOR;
    engObjX     = 0;
    engObjY     = 15;
    engObjData  = door1Data;
    engAddObjectASM();
    objTexture[4] = 0;

    engObjType = OBJ_DOOR;
    engObjX     = -24;
    engObjY     = 15;
    engObjData  = door2Data;
    engAddObjectASM();
    objTexture[5] = 0;

    engObjType = OBJ_DOOR;
    engObjX     = -36;
    engObjY     = 27;
    engObjData  = door3Data;
    engAddObjectASM();
    objTexture[6] = 0;

    engObjType = OBJ_DOOR;
    engObjX     = -24;
    engObjY     = 39;
    engObjData  = door4Data;
    engAddObjectASM();
    objTexture[7] = 0;

    engObjType = OBJ_DOOR;
    engObjX     = 0;
    engObjY     = 39;
    engObjData  = door5Data;
    engAddObjectASM();
    objTexture[8] = 0;

    engObjType = OBJ_LAMP;
    engObjX     = -24;
    engObjY     = 27;
    engObjData  = 0;
    engAddObjectASM();
    objTexture[9] = lamp_1;

    engObjType = OBJ_AMMO;
    engObjX     = 28;
    engObjY     = 54;
    engObjData  = 0;
    engAddObjectASM();
    objTexture[10] = texture_ammo_1;

}

void gamePulse(void){

    dichoInit();
    engPulse();

    if (openDoorRequest == 1) {
        openDoorRequest=0;
    }
    if (sceneUpdateRequest !=0) {
        initScene (scene_00, texture_00);
        sceneUpdateRequest = 0;
    }
    shootRequest = 0;


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
