
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

unsigned char gunInHand; // 0 = knife, 1= gun
extern unsigned char foreground_patched; // 0 = not patched, 1= patched

unsigned char currentScene;
unsigned char previousScene;
signed char *ptrCurrentScene;
unsigned char openDoorRequest;
unsigned char shootRequest;
unsigned char sceneUpdateRequest;


signed  char door_0_0_data[] = {
        0,      // state 0 : close,  1..6 : opening, 7: opened ,
        // Points to animate are indexes in scene data of coordinate to change
        58,     
        60,
        1,  // Direction to animate: 1 or -1
        0,  // Place holder for temporisation
        };    // 26 = 12(point n12)*2 (2 coord/point) + 2 (header nbPoints + nbWall)

signed  char door_0_1_data[] = {
        0,      // state 0 : close,  1..6 : opening, 7: opened ,
        // Points to animate are indexes in scene data of coordinate to change
        67,     
        69,
        1,  // Direction to animate: 1 or -1
        0,  // Place holder for temporisation
        };    // 86 = 42(point n42)*2 (2 coord/point) + 2 (header nbPoints + nbWall)

signed  char door_0_2_data[] = {
        0,      // state 0 : close,  1..6 : opening, 7: opened ,
        // Points to animate are indexes in scene data of coordinate to change
        75,     
        77,
        -1,  // Direction to animate: 1 or -1
        0,  // Place holder for temporisation
        };    // 94 = 46(point n46)*2 (2 coord/point) + 2 (header nbPoints + nbWall)

signed  char door_0_3_data[] = {
        0,      // state 0 : close,  1..6 : opening, 7: opened ,
        // Points to animate are indexes in scene data of coordinate to change
        83,     
        85,
        -1,  // Direction to animate: 1 or -1
        0,  // Place holder for temporisation
        };    // 94 = 46(point n46)*2 (2 coord/point) + 2 (header nbPoints + nbWall)

signed  char door_0_4_data[] = {
        0,      // state 0 : close,  1..6 : opening, 7: opened ,
        // Points to animate are indexes in scene data of coordinate to change
        91,     
        93,
        -1,  // Direction to animate: 1 or -1
        0,  // Place holder for temporisation
        };    // 94 = 46(point n46)*2 (2 coord/point) + 2 (header nbPoints + nbWall)




signed  char door_1_0_data[] = {
        0,      // state 0 : close,  1..6 : opening, 7: opened ,
        // Points to animate are indexes in scene data of coordinate to change
        78,     
        80,
        1,  // Direction to animate: 1 or -1
        0,  // Place holder for temporisation
        };    // 26 = 12(point n12)*2 (2 coord/point) + 2 (header nbPoints + nbWall)

signed  char door_1_1_data[] = {
        0,      // state 0 : close,  1..6 : opening, 7: opened ,
        // Points to animate are indexes in scene data of coordinate to change
        87,     
        89,
        1,  // Direction to animate: 1 or -1
        0,  // Place holder for temporisation
        };    // 86 = 42(point n42)*2 (2 coord/point) + 2 (header nbPoints + nbWall)

signed  char door_1_2_data[] = {
        0,      // state 0 : close,  1..6 : opening, 7: opened ,
        // Points to animate are indexes in scene data of coordinate to change
        94,     
        96,
        -1,  // Direction to animate: 1 or -1
        0,  // Place holder for temporisation
        };    // 94 = 46(point n46)*2 (2 coord/point) + 2 (header nbPoints + nbWall)


signed  char door_2_1_data[] = {
        0,      // state 0 : close,  1..6 : opening, 7: opened ,
        // Points to animate are indexes in scene data of coordinate to change
        65,     
        67,
        -1,  // Direction to animate: 1 or -1
        0,  // Place holder for temporisation
        };    // 64 = 31(point n42)*2 (2 coord/point) + 2 (header nbPoints + nbWall)

signed  char door_2_2_data[] = {
        0,      // state 0 : close,  1..6 : opening, 7: opened ,
        // Points to animate are indexes in scene data of coordinate to change
        73,     
        75,
        1,  // Direction to animate: 1 or -1
        0,  // Place holder for temporisation
        };    // 72 = 35(point n46)*2 (2 coord/point) + 2 (header nbPoints + nbWall)


signed char soldier1Data [] = {
    1,          // [0] state: 0=dead, 1=walking, 
    0,          // [1] direction
    4,          // [2] health
    0,          // [3] placeholder for xDeathPos
    0,          // [4] placeholder for yDeathPos
    -12,        // [5] min excursion
    12          // [6] max excursion
    };

signed char soldier2Data [] = {
    1,          // [0] state: 0=dead, 1=walking, 
    0,          // [1] direction
    4,          // [2] health
    0,          // [3] placeholder for xDeathPos
    0,          // [4] placeholder for yDeathPos
    48,        // [5] min excursion
    72          // [6] max excursion
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
    rayCamPosX               = 0;
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

void engScene_00(){
        engObjType = OBJ_DOOR;
        engObjX     = 0;
        engObjY     = 42;
        engObjData  = door_0_0_data;
        engAddObjectASM();
        objTexture[0] = 0;

        engObjType = OBJ_DOOR;
        engObjX     = -12;
        engObjY     = 30;
        engObjData  = door_0_1_data;
        engAddObjectASM();
        objTexture[1] = 0;

        engObjType = OBJ_DOOR;
        engObjX     = -12;
        engObjY     = 0;
        engObjData  = door_0_2_data;
        engAddObjectASM();
        objTexture[2] = 0;

        engObjType = OBJ_DOOR;
        engObjX     = 12;
        engObjY     = 0;
        engObjData  = door_0_3_data;
        engAddObjectASM();
        objTexture[3] = 0;

        engObjType = OBJ_DOOR;
        engObjX     = 12;
        engObjY     = 30;
        engObjData  = door_0_4_data;
        engAddObjectASM();
        objTexture[4] = 0;

        engObjType = OBJ_SOLDIER;
        engObjX     = 0; // 2; // 
        engObjY     = -24; // 0; // 
        engObjData  = soldier1Data;
        engAddObjectASM();
        objTexture[5] = soldier_front;

        engObjType = OBJ_LAMP;
        engObjX     = 0;
        engObjY     = 30;
        engObjData  = 0;
        engAddObjectASM();
        objTexture[6] = lamp_1;

        engObjType = OBJ_LAMP;
        engObjX     = 0;
        engObjY     = 0;
        engObjData  = 0;
        engAddObjectASM();
        objTexture[7] = lamp_1;

        engObjType = OBJ_AMMO; //
        engObjX     = 36;
        engObjY     = -24;
        engObjData  = 0;
        engAddObjectASM();
        objTexture[8] = texture_ammo_1;//

        engObjType = OBJ_LAMP;
        engObjX     = -30;
        engObjY     = -24;
        engObjData  = 0;
        engAddObjectASM();
        objTexture[9] = lamp_1;

        engObjType = OBJ_LAMP;
        engObjX     = 30;
        engObjY     = -24;
        engObjData  = 0;
        engAddObjectASM();
        objTexture[10] = lamp_1;
        
        engObjType = OBJ_DEAD_SOLDIER;
        engObjX     = -18;
        engObjY     = 0;
        engObjData  = 0;
        engAddObjectASM();
        objTexture[11] = sprite_deadsoldier;


        engObjType = OBJ_PIECE_OF_MEAT;
        engObjX     = 0;
        engObjY     = -27;
        engObjData  = 0;
        engAddObjectASM();
        objTexture[12] = pieceofmeat;

        // #TODO Why can we add more objects?
        // engObjType  = OBJ_LAMP;
        // engObjX     = 0;
        // engObjY     = -24;
        // engObjData  = 0;
        // engAddObjectASM();
        // objTexture[8] = lamp_1;

}
void engScene_01(){
        engObjType = OBJ_DOOR;
        engObjX     = 54;
        engObjY     = 0;
        engObjData  = door_1_1_data;
        engAddObjectASM();
        objTexture[0] = 0;

        engObjType = OBJ_DOOR;
        engObjX     = 0;
        engObjY     = -30;
        engObjData  = door_1_0_data;
        engAddObjectASM();
        objTexture[1] = 0;

        engObjType = OBJ_DOOR;
        engObjX     = 0;
        engObjY     = 30;
        engObjData  = door_1_2_data;
        engAddObjectASM();
        objTexture[2] = 0;

        engObjType = OBJ_PLANT;
        engObjX     = -42;
        engObjY     = -18;
        engObjData  = 0;
        engAddObjectASM();
        objTexture[3] = plant_1;

        engObjType = OBJ_PLANT;
        engObjX     = -42;
        engObjY     = 18;
        engObjData  = 0;
        engAddObjectASM();
        objTexture[4] = plant_1;

        engObjType = OBJ_PLANT;
        engObjX     = 42;
        engObjY     = 18;
        engObjData  = 0;
        engAddObjectASM();
        objTexture[5] = plant_1;

        engObjType = OBJ_PLANT;
        engObjX     = 42;
        engObjY     = -18;
        engObjData  = 0;
        engAddObjectASM();
        objTexture[6] = plant_1;

        engObjType = OBJ_LUSTRE;
        engObjX     = -30;
        engObjY     = 0;
        engObjData  = 0;
        engAddObjectASM();
        objTexture[7] = lustre;

        engObjType = OBJ_LUSTRE;
        engObjX     = 0;
        engObjY     = 0;
        engObjData  = 0;
        engAddObjectASM();
        objTexture[8] = lustre;

        engObjType = OBJ_LUSTRE;
        engObjX     = 30;
        engObjY     = 0;
        engObjData  = 0;
        engAddObjectASM();
        objTexture[9] = lustre;
}

void engScene_02(){
        engObjType = OBJ_DOOR;
        engObjX     = 15;
        engObjY     = -66;
        engObjData  = door_2_1_data;
        engAddObjectASM();
        objTexture[0] = 0;

        engObjType = OBJ_DOOR;
        engObjX     = 33;
        engObjY     = 0;
        engObjData  = door_2_2_data;
        engAddObjectASM();
        objTexture[1] = 0;

        engObjType = OBJ_PLANT;
        engObjX     = 72;
        engObjY     = 21;
        engObjData  = 0;
        engAddObjectASM();
        objTexture[2] = barrel;

        engObjType = OBJ_PLANT;
        engObjX     = 60;
        engObjY     = 9;
        engObjData  = 0;
        engAddObjectASM();
        objTexture[3] = table;

        engObjType = OBJ_PLANT;
        engObjX     = 51;
        engObjY     = -30;
        engObjData  = 0;
        engAddObjectASM();
        objTexture[4] = well;

        engObjType = OBJ_PLANT;
        engObjX     = 69;
        engObjY     = -30;
        engObjData  = 0;
        engAddObjectASM();
        objTexture[5] = well;

        engObjType = OBJ_PLANT;
        engObjX     = 60;
        engObjY     = 21;
        engObjData  = 0;
        engAddObjectASM();
        objTexture[6] = barrel;

        engObjType = OBJ_SOLDIER;
        engObjX     = 60; // 2; // 
        engObjY     = 0; // 0; // 
        engObjData  = soldier2Data;
        engAddObjectASM();
        objTexture[7] = soldier_front;

}

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
    currentScene            = 2;
    previousScene            = 2;


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

    // LoadFileAt(LOADER_TEXTURES, 0xc000);

    // ptrCurrentScene = scene_00;       
    // initScene (scene_00, texture_00);

    // engInitObjects();
    // engScene_00();

            LoadFileAt(LOADER_TEXTURES_021, 0xc000);
            ptrCurrentScene = scene_02;       
            initScene (scene_02, texture_02);
            engInitObjects();
            engScene_02();


}

void gamePulse(void){



    previousScene           = currentScene;

    if ((currentScene == 0) && (rayCamPosY >= 57)) {
        currentScene = 1;
        rayCamPosY  = -44;
    } else if (currentScene == 1){
        if (rayCamPosY <= -45) {
            currentScene = 0;
            rayCamPosY  = 56;
        } else if (rayCamPosX > 60) {
            currentScene = 2;
            rayCamPosX  = -20;
        }
    } else if (currentScene == 2){
        if (rayCamPosX < -20) {
            currentScene = 1;
            rayCamPosX = 59;
        }

    }

    if (currentScene != previousScene) {
        engInitObjects();
        switch (currentScene)
        {
        case 0:
            LoadFileAt(LOADER_TEXTURES, 0xc000);
            ptrCurrentScene = scene_00;       
            initScene (scene_00, texture_00);
            engScene_00();
            break;
        case 1:
            LoadFileAt(LOADER_TEXTURES_01, 0xc000);
            ptrCurrentScene = scene_01;       
            initScene (scene_01, texture_01);
            engScene_01();
            break;
        case 2:
            LoadFileAt(LOADER_TEXTURES_021, 0xc000);
            ptrCurrentScene = scene_02;       
            initScene (scene_02, texture_02);
            engScene_02();
            break;
        
        default:
            LoadFileAt(LOADER_TEXTURES, 0xc000);
            initScene (scene_00, texture_00);
            break;
        }
    }

    dichoInit();
    engPulse();

    if (openDoorRequest == 1) {
        openDoorRequest=0;
    }
    if (sceneUpdateRequest !=0) {
        if (currentScene == 0) {
            initScene (scene_00, texture_00);
        } if (currentScene == 1) {
            initScene (scene_01, texture_01);
        } if (currentScene == 2){
            initScene (scene_02, texture_02);
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
