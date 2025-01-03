
#include "loader/loader_api.h"
#include "rom/myRom.h"
#include "rom/keyboard.h"
#include "constants.h"
#include "scene/scene.h"
#include "util.h"
#include "raycast/raycast.h"

#define ROT_ANGLE_STEP 16


void onKey(unsigned char c){

}



void onIT(){;}

void initCamera(){
    rayCamPosX               = 71;
    rayCamPosY               = 9; 
    rayCamRotZ               = 0x80;
    RayLeftAlpha            = rayCamRotZ + HALF_FOV_FIX_ANGLE;

    // glCamPosX   = rayCamPosX;
    // glCamPosY   = rayCamPosY;
    // glCamPosZ   = 0;
    // glCamRotZ   = rayCamRotZ;


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
	
    // PRINTS(3,17,"Salud: ");
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
