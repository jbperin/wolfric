// Author : Jean-Baptiste PERIN
// Date : 2021
//
// Build with OSDK: osdk_build.bat && osdk_execute.bat
//

#undef DEBUG

#include "lib.h"

#include "config.h"

// #include "raycast.c"
// #include "scene.c"

// #include "game.c"

// #include "player.c"

// #include "texel.c"

// #include "drawWalls.c"


// extern unsigned char 	kernel_cs;
// extern unsigned char 	kernel_s;

// extern unsigned char 	kernel_fraction;
// extern unsigned char 	kernel_beat;
// extern unsigned char 	kernel_tempo;
// extern unsigned char 	nbE_keybuf;

// char message [40];
// unsigned char refreshNeeded;
// unsigned char running ;
unsigned char mode0;

// #define CHANGE_INK_TO_BLACK             0
// #define CHANGE_INK_TO_RED	            1		
// #define CHANGE_INK_TO_GREEN	            2		
// #define CHANGE_INK_TO_BLUE	            4		
// #define CHANGE_PAPER_TO_WHITE	        23


// void prepareRGB(){
//     int ii;

//     // parcours de lignes de 3 en 3
//     for (ii=0; ii < (TEXT_SCREEN_HEIGHT - NB_LESS_LINES_4_COLOR)*8;  ii+=3){
//         poke (HIRES_SCREEN_ADDRESS+((ii)*NEXT_SCANLINE_INCREMENT),CHANGE_INK_TO_RED);
//         poke (HIRES_SCREEN_ADDRESS+((ii+1)*NEXT_SCANLINE_INCREMENT),CHANGE_INK_TO_GREEN);
//         poke (HIRES_SCREEN_ADDRESS+((ii+2)*NEXT_SCANLINE_INCREMENT),CHANGE_INK_TO_BLUE);
//     }
// }


// // [ref camera_situation]
// void initCamera(signed char init[] ){
//     rayCamPosX               = init[0]; // 25; // 12;
//     rayCamPosY               = init[1]; // 25; // 46; 
//     rayCamRotZ               = init[2]; //-128; // 32;
//     RayLeftAlpha            = rayCamRotZ + HALF_FOV_FIX_ANGLE;
// }


// void keyPressed(unsigned char c){
// 	// printf ("kp: %x, ", c);
//     if (c == keyForward) {
//             forward(); 
//             refreshNeeded   = 1;
//     } else if (c == keyBackward) {
//             backward();
//             refreshNeeded   = 1;
//     } else if (c == keyTurnLeft) {
//             rayCamRotZ      += ROT_ANGLE_STEP;
//             RayLeftAlpha    = rayCamRotZ + HALF_FOV_FIX_ANGLE;
//             refreshNeeded   = 1;
//     } else if (c == keyTurnRight) {
//             rayCamRotZ      -= ROT_ANGLE_STEP; 
//             RayLeftAlpha    = rayCamRotZ + HALF_FOV_FIX_ANGLE;
//             refreshNeeded   = 1;
//     } else if (c == keyStraffeRight) {
//             refreshNeeded           = 1;
//             shiftRight();
//     } else if (c == keyStraffeLeft) {
//             refreshNeeded           = 1;
//             shiftLeft();
//     } else if (c == keyQuit) {
//             running = 0;
//     }

// }

// void keyReleased(unsigned char c){
// 	// printf ("kr: %x, ", c);
// }

// void lsys(){
// 	unsigned char c;
// 	while (nbE_keybuf != 0) {
// 		if ((c=get_keyevent()) & 0x80){
// 			keyReleased (c & 0x7F);
// 		} else {
// 			keyPressed (c);
// 		}
// 	}
// }

void waitkey () {
    sprintf (0xBF70, "Press a key ...");
    get();
}

void main(){

//     paper(0); ink(7);

    // Deactivate cursor and keyclick
    mode0 = *((unsigned char *)0x26A);
    *((unsigned char *)0x26A) = (mode0 | 0x08) & 0xFE;

//     myHires();
//     poke(0xBF68, 16); poke(0xBF69, 7);
//     poke(0xBF90, 16); poke(0xBF91, 7);
//     poke(0xBFB8, 16); poke(0xBFB9, 7);
//     poke(0x26A, (mode0 | 0x08) & 0xFE);
    waitkey();
//     text();
    

    // Reactivate cursor and keyclick
    *((unsigned char *)0x26A) = mode0;

}


