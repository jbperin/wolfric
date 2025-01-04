
#include "loader/loader_api.h"
#include "rom/myRom.h"
#include "rom/keyboard.h"
#include "constants.h"
#include "scene/scene.h"
#include "util.h"
#include "raycast/raycast.h"

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
    rayCamPosX               = 71;
    rayCamPosY               = 9; 
    rayCamRotZ               = 0x80;
    RayLeftAlpha            = rayCamRotZ + HALF_FOV_FIX_ANGLE;

}


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
}

void gamePulse(void){

    dichoInit();
    engPulse();

    rayInitCasting();

    rayProcessPoints();
    rayProcessWalls();
    drawWalls();

}
