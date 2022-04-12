// Author : Jean-Baptiste PERIN
// Date : 2021
//
// Build with OSDK: osdk_build.bat && osdk_execute.bat
//

#undef DEBUG

#include "lib.h"
#include "config.h"
#include "oric.h"

#include "raycast.c"
#include "scene.c"

#include "game.c"
#include "collision.c"
#ifndef PROFILER_ENABLE
#include "player.c"
#endif // PROFILER_ENABLE
#include "texel.c"
#include "keyboard_c.c"
#include "viewport.c"
#include "vertcolbuf.c"
#include "drawWalls.c"

#ifdef USE_SPRITE
#include "texture_soldier_front.h"
#include "texture_soldier_back.h"
#include "texture_soldier_left.h"
#include "texture_soldier_right.h"
#endif // USE_SPRITE
#include "dichobuf.c"
#include "engine.c"
#ifdef USE_SPRITE
#include "dist.c"
#include "sprite.c"
#include "sprite_lamp.h"

#endif // USE_SPRITE

#define CHANGE_INK_TO_RED	            1		
#define CHANGE_INK_TO_GREEN	            2		
#define CHANGE_INK_TO_BLUE	            4		

// extern unsigned char 	kernel_cs;
// extern unsigned char 	kernel_s;

// extern unsigned char 	kernel_fraction;
// extern unsigned char 	kernel_beat;
// extern unsigned char 	kernel_tempo;

extern unsigned char 	nbE_keybuf;

void prepareRGB(){
    int ii;

    // parcours de lignes de 3 en 3
    for (ii=0; ii < (TEXT_SCREEN_HEIGHT - NB_LESS_LINES_4_COLOR)*8;  ii+=3){
        poke (HIRES_SCREEN_ADDRESS+((ii)*NEXT_SCANLINE_INCREMENT),CHANGE_INK_TO_RED);
        poke (HIRES_SCREEN_ADDRESS+((ii+1)*NEXT_SCANLINE_INCREMENT),CHANGE_INK_TO_GREEN);
        poke (HIRES_SCREEN_ADDRESS+((ii+2)*NEXT_SCANLINE_INCREMENT),CHANGE_INK_TO_BLUE);
    }
}


void keyPressed(unsigned char c){
	// printf ("kp: %x, ", c);
    if (c == keyForward) {
            forward(); 
            refreshNeeded   = 1;
    } else if (c == keyBackward) {
            backward();
            refreshNeeded   = 1;
    } else if (c == keyTurnLeft) {
            rayCamRotZ      += ROT_ANGLE_STEP;
            RayLeftAlpha    = rayCamRotZ + HALF_FOV_FIX_ANGLE;
            refreshNeeded   = 1;
    } else if (c == keyTurnRight) {
            rayCamRotZ      -= ROT_ANGLE_STEP; 
            RayLeftAlpha    = rayCamRotZ + HALF_FOV_FIX_ANGLE;
            refreshNeeded   = 1;
    } else if (c == keyStraffeRight) {
            refreshNeeded           = 1;
            shiftRight();
    } else if (c == keyStraffeLeft) {
            refreshNeeded           = 1;
            shiftLeft();
    } else if (c == keyQuit) {
            running = 0;
    } else if (c ==  0x20) {
        // space bar pressed => trigger door opening if player is close to the door and it is closed
        if ((abs(rayCamPosX) <= 3) && (abs(rayCamPosY-12) <= 3) && (doorData[0] == 0)){
            doorData[0]=1;
        }
    }
}

void keyReleased(unsigned char c){
	// printf ("kr: %x, ", c);
}

void lsys(){
	unsigned char c;
	while (nbE_keybuf != 0) {
		if ((c=get_keyevent()) & 0x80){
			keyReleased (c & 0x7F);
		} else {
			keyPressed (c);
		}
	}
}
#define BORDER_COLOR 3
void borderViewport(){
    int ii;
        for (ii = -2; ii <= VIEWPORT_HEIGHT; ii++) {
            drawTexelOnScreen (ii+VIEWPORT_START_LINE, VIEWPORT_START_COLUMN -2, BORDER_COLOR);
            drawTexelOnScreen (ii+VIEWPORT_START_LINE, VIEWPORT_START_COLUMN+VIEWPORT_WIDTH-2, BORDER_COLOR);
        }
        for (ii=0 ; ii < VIEWPORT_WIDTH; ii++){
            drawTexelOnScreen (VIEWPORT_START_LINE-2, VIEWPORT_START_COLUMN+ii, BORDER_COLOR);
            drawTexelOnScreen (VIEWPORT_START_LINE + VIEWPORT_HEIGHT+1, VIEWPORT_START_COLUMN+ii, BORDER_COLOR);
        }
}

void gameLoop() {


    borderViewport();


    engInitObjects();

    engAddObject(OBJ_DOOR, 5, 10, doorData);
    idObjDoor = engCurrentObjectIdx;

    engAddObject(OBJ_LAMP, 0, 27, 0);
    objTexture[engCurrentObjectIdx] = texture_sprite_lamp;

    engAddObject(OBJ_LAMP, -24, 27, 0);
    objTexture[engCurrentObjectIdx] = texture_sprite_lamp;

    engAddObject(OBJ_SOLDIER, 24, 60, soldierData);
    objTexture[engCurrentObjectIdx] = texture_soldier_back;

	kernelInit();
	osmeInit();

    while (running) {
        
        doke(630,0);

        lsys();

        dichoInit();
        engPulse();

        if (refreshNeeded) {
            rayInitCasting();

            rayProcessPoints();
            rayProcessWalls();

            drawWalls();
            refreshNeeded = 0;
// #ifndef PROFILER_ENABLE            
//             printf("\n(X=%d Y=%d) [a=%d] [t=%d]\n\n", rayCamPosX, rayCamPosY, rayCamRotZ, 65535-deek(630));
//             if (hasKey) printf ("Key");
// #endif
        }
    }  
    kernelEnd();
}

unsigned char mode0;


void waitkey () {
    // sprintf (0xBF70, "Press a key ...");
    get();
}


void main(){

    // Deactivate cursor and keyclick
    mode0 = *((unsigned char *)0x26A);
    *((unsigned char *)0x26A) = (mode0 | 0x08) & 0xFE;

    waitkey();

    rayCamPosX               = 0;
    rayCamPosY               = 0; 
    rayCamRotZ               = 64;
    RayLeftAlpha            = rayCamRotZ + HALF_FOV_FIX_ANGLE;

    
    // [ref scene_load]
    initScene (scene_00, texture_00);

    memset(0xa000, 64 , 8000);
    prepareRGB();
    running = 1;
    refreshNeeded           = 1;
    gameLoop();



    // Reactivate cursor and keyclick
    *((unsigned char *)0x26A) = mode0;

}
