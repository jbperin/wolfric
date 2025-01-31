
#include "loader/loader_api.h"
#include "rom/myRom.h"
#include "rom/keyboard.h"
#include "constants.h"
#include "scene/scene.h"
#include "util.h"
#include "raycast/raycast.h"
#include "engine/engine.h"
#define ROT_ANGLE_STEP 16

unsigned char running         ;

unsigned char health          = 100;
unsigned char score           = 0;
unsigned char level           = 1;
unsigned char lives           = 3;
unsigned char ammo            = 8;

unsigned char gunInHand; // 0 = knife, 1= gun
extern unsigned char foreground_patched; // 0 = not patched, 1= patched

unsigned char currentScene;
unsigned char previousScene;
signed char *ptrCurrentScene;
unsigned char openDoorRequest;
unsigned char shootRequest;
unsigned char sceneUpdateRequest;



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
        gunInHand = 0;
    } else if (c == KEY_2) {
        if (ammo != 0) {
            LoadFileAt(LOADER_FG_GUN, texture_gun);
            gunInHand = 1;
        }
    } else if (c == KEY_SPACE) {
        openDoorRequest = 1;
    } else if (c == KEY_E) {
        // If player holds a knife
        if (gunInHand == 0){
            patch_basic_knife_into_knife_shoot();
            foreground_patched = 1;
        // If player holds a knife
        } else {
            
            if (ammo !=0) {
                SHOOT();
                ammo--;
                shootRequest = 1;
                if (ammo == 0) {
                    LoadFileAt(LOADER_FG_KNIFE, texture_gun);
                } else {
                    patch_basic_gun_into_gun_shoot();
                    foreground_patched = 1;
                }

        }
        }
        
    } else if (c == KEY_LEFT_CONTROL) {
        if (ammo !=0) ammo--;
    }
}

void onIT(){;}

void initCamera(){
    rayCamPosX               = -33;
    rayCamPosY               = 0; 
    rayCamRotZ               = 0;
    RayLeftAlpha            = rayCamRotZ + HALF_FOV_FIX_ANGLE;

}

extern unsigned char sprite_deadsoldier[];
extern unsigned char lamp_1[];
extern unsigned char soldier_back[];
extern unsigned char soldier_front[];
extern unsigned char soldier_left[];
extern unsigned char soldier_right[];
extern unsigned char pieceofmeat[];
extern unsigned char lamp[];
extern unsigned char lustre[];
extern unsigned char plant_1[];

extern unsigned char barrel[];
extern unsigned char table[];
extern unsigned char well[];
// extern unsigned char puddle[];


#include "engScene3.c"
#include "engScene4.c"
#include "engScene5.c"
#include "engScene6.c"

void gameInit(void){

    // LoadFileAt(LOADER_RAYTABLES, 0xED95);
	// LoadFileAt(BASIC_SCREEN, 0xBB80);
    //LoadFileAt(LOADER_CHARSET_STANDARD, 0xb400);
    LoadFileAt(LOADER_RAYTABLES, 0xEC00);
    // LoadFileAt(LOADER_TEXTURES_3, 0xc000);
    // LoadFileAt(LOADER_ANIM, 0xd800);
    LoadFileAt(LOADER_HRSCREEN, 0x9800);
	
    initCamera();

    // currentScene            = 0;
    currentScene            = 4;
    previousScene            = 0;


    health              = 100;
    score               = 0;
    level               = 1;
    lives               = 3;
    ammo                = 8;

    gunInHand           = 1;
    foreground_patched  = 0;
    openDoorRequest     = 0;
    sceneUpdateRequest  = 0;
    shootRequest        = 0;

    LoadFileAt(LOADER_TEXTURES, 0xc000);

    ptrCurrentScene = scene_04;       
    initScene (scene_04, texture_04);

    engInitObjects();
    engScene_04();

            // LoadFileAt(LOADER_TEXTURES_01, 0xc000);
            // ptrCurrentScene = scene_06;       
            // initScene (scene_06, texture_06);
            // engInitObjects();
            // engScene_06();


}

void gamePulse(void){



    previousScene           = currentScene;

    if ((currentScene == 4) && (rayCamPosY >= 54)) {
        currentScene = 3;
        rayCamPosY  -= 78;
    } else if (currentScene == 3){
        if (rayCamPosY <= -24) {
            currentScene = 4;
            rayCamPosY  += 78;
        } else if (rayCamPosX > 36) {
            currentScene = 5;
            rayCamPosX  -= 48;
        } else if (rayCamPosY >= 24) {
            currentScene = 6;
            rayCamPosY  -= 66;

        }
    } else if (currentScene == 5){
        if (rayCamPosX < -6) {
            currentScene = 3;
            rayCamPosX += 48;
        }
    }  if (currentScene == 6){
        if (rayCamPosY <= -42) {
            currentScene = 3;
            rayCamPosY  += 66;
            // running = 0;
        } else if (rayCamPosX <= -39){
            running = 0;
        }
    }

    if (currentScene != previousScene) {
        engInitObjects();
        switch (currentScene)
        {
        case 4:
            LoadFileAt(LOADER_TEXTURES, 0xc000);
            ptrCurrentScene = scene_04;       
            initScene (scene_04, texture_04);
            engScene_04();
            break;
        case 3:
            LoadFileAt(LOADER_TEXTURES_01, 0xc000);
            ptrCurrentScene = scene_03;       
            initScene (scene_03, texture_03);
            engScene_03();
            break;
        case 5:
            LoadFileAt(LOADER_TEXTURES_021, 0xc000);
            ptrCurrentScene = scene_05;       
            initScene (scene_05, texture_05);
            engScene_05();
            break;
        case 6:
            LoadFileAt(LOADER_TEXTURES_01, 0xc000);
            ptrCurrentScene = scene_06;       
            initScene (scene_06, texture_06);
            engScene_06();
            break;
        }
    }

    dichoInit();
    engPulse();

    if (openDoorRequest == 1) {
        openDoorRequest=0;
    }
    if (sceneUpdateRequest !=0) {
        if (currentScene == 4) {
            initScene (scene_04, texture_04);
        } if (currentScene == 3) {
            initScene (scene_03, texture_03);
        } if (currentScene == 5){
            initScene (scene_05, texture_05);
        } if (currentScene == 6){
            initScene (scene_06, texture_06);
        }
        sceneUpdateRequest = 0;
    }
    shootRequest = 0;


    rayInitCasting();

    rayProcessPoints();
    rayProcessWalls();
    drawWalls();
    
    if (foreground_patched != 0) {
        if (gunInHand == 1) {
            patch_gun_shoot_into_basic_gun();
        } else {
            patch_knife_shoot_into_basic_knife();
        }
    }



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
