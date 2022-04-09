// Author : Jean-Baptiste PERIN
// Date : 2021
//
// Build with OSDK: osdk_build.bat && osdk_execute.bat
//
// Save wm $9C00 896 altchar.bin
// Save wm $bf68 120 botpan.bin

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
    // sprintf (0xBF70, "Press a key ...");
    get();
}

#define LORES_SCREEN_ADDRESS 0xBB80
// #define HIRES_SCREEN_ADDRESS 0xA000

#define LORES_SCREEN_WIDTH 40
#define LORES_SCREEN_HEIGHT 26

#define HIRES_SCREEN_WIDTH 240
#define HIRES_SCREEN_HEIGHT 200


#define INK_BLACK	0
#define INK_RED		1
#define INK_GREEN	2
#define INK_YELLOW	3
#define INK_BLUE	4
#define INK_MAGENTA	5
#define INK_CYAN	6
#define INK_WHITE	7

// Character Set modifier	
#define STANDARD_CHARSET 8 //		Use Standard Charset	
#define ALTERNATE_CHARSET 9 //		Use Alternate Charset	
#define DOUBLE_STANDARD_CHARSET  10	//	Use Double Size Standard Charset	
#define DOUBLE_ALTERNATE_CHARSET 11 //		Use Double Size Alternate Charset	
#define BLINKING_STANDARD_CHARSET 12 //		Use Blinking Standard Charset	
#define BLINKING_ALTERNATE_CHARSET 13 //		Use Blinking Alternate Charset	
#define DOUBLE_BLINK_STANDARD_CHARSET 14	//	Use Double Size Blinking Standard Charset	
#define DOUBLE_BLINK_ALTERNATE_CHARSET 15	//	Use Double Size Blinking Alternate Charset

// Change Paper (background) color	
#define PAPER_BLACK	16
#define PAPER_RED	17
#define PAPER_GREEN	18
#define PAPER_YELLOW	19
#define PAPER_BLUE	20
#define PAPER_MAGENTA	21
#define PAPER_CYAN	22
#define PAPER_WHITE	23

// Video control attributes	
#define TEXT_60Hz	24
#define TEXT_50Hz	26
#define HIRES_60Hz	28
#define HIRES_50Hz	30

void change_char(char c, unsigned char patt01, unsigned char patt02, unsigned char patt03, unsigned char patt04, unsigned char patt05, unsigned char patt06, unsigned char patt07, unsigned char patt08) {
    unsigned char* adr;
    adr      = (unsigned char*)(0x9C00 + c * 8);
    *(adr++) = patt01;
    *(adr++) = patt02;
    *(adr++) = patt03;
    *(adr++) = patt04;
    *(adr++) = patt05;
    *(adr++) = patt06;
    *(adr++) = patt07;
    *(adr++) = patt08;
}

void bottom_panel() {

        int ii, jj;

        // *((unsigned char *)0x26A)= 10;

    // *((unsigned char *)48960)= 0x14;
		// for (jj = 0; jj < 8; jj++) {
		// 	// poke (HIRES_SCREEN_ADDRESS+((ii*8+jj)*LORES_SCREEN_WIDTH)+1, tab_color[jj]);
		// 	poke (HIRES_SCREEN_ADDRESS+((ii*8+jj)*LORES_SCREEN_WIDTH)+2, TEXT_50Hz);
		// }

    // sprintf (0xBF70, "Press a key ...");

    *((unsigned char *)0xbf68+0*40+0)= PAPER_BLUE;
    *((unsigned char *)0xbf68+1*40+0)= PAPER_BLUE;
    *((unsigned char *)0xbf68+2*40+0)= PAPER_BLUE;
    *((unsigned char *)0xbf68+0*40+1)= INK_WHITE;
    *((unsigned char *)0xbf68+1*40+1)= INK_WHITE;
    *((unsigned char *)0xbf68+2*40+1)= INK_WHITE;
    *((unsigned char *)0xbf68+0*40+2)= ALTERNATE_CHARSET;
    *((unsigned char *)0xbf68+1*40+2)= ALTERNATE_CHARSET;
    *((unsigned char *)0xbf68+2*40+2)= ALTERNATE_CHARSET;
*((unsigned char *)0xbf68+0*40+3)= 33;
*((unsigned char *)0xbf68+0*40+4)= 34;
*((unsigned char *)0xbf68+0*40+5)= 35;
*((unsigned char *)0xbf68+0*40+6)= 36;
*((unsigned char *)0xbf68+0*40+7)= 37;
*((unsigned char *)0xbf68+0*40+8)= 38;
*((unsigned char *)0xbf68+0*40+9)= 39;
*((unsigned char *)0xbf68+0*40+10)= 40;
*((unsigned char *)0xbf68+0*40+11)= 41;
*((unsigned char *)0xbf68+0*40+12)= 42;
*((unsigned char *)0xbf68+0*40+13)= 43;
*((unsigned char *)0xbf68+0*40+14)= 44;
*((unsigned char *)0xbf68+0*40+15)= 45;
*((unsigned char *)0xbf68+0*40+16)= 46;
*((unsigned char *)0xbf68+0*40+17)= 47;
*((unsigned char *)0xbf68+0*40+18)= 48;
*((unsigned char *)0xbf68+0*40+19)= 49;
*((unsigned char *)0xbf68+0*40+20)= 50;
*((unsigned char *)0xbf68+0*40+21)= 51;
*((unsigned char *)0xbf68+0*40+22)= 52;
*((unsigned char *)0xbf68+0*40+23)= 53;
*((unsigned char *)0xbf68+0*40+24)= 54;
*((unsigned char *)0xbf68+0*40+25)= 55;
*((unsigned char *)0xbf68+0*40+26)= 56;
*((unsigned char *)0xbf68+0*40+27)= 57;
*((unsigned char *)0xbf68+0*40+28)= 58;
*((unsigned char *)0xbf68+0*40+29)= 59;
*((unsigned char *)0xbf68+0*40+30)= 60;
*((unsigned char *)0xbf68+0*40+31)= 61;
*((unsigned char *)0xbf68+0*40+32)= 62;
*((unsigned char *)0xbf68+0*40+33)= 63;
*((unsigned char *)0xbf68+0*40+34)= 64;
*((unsigned char *)0xbf68+0*40+35)= 65;
*((unsigned char *)0xbf68+0*40+36)= 66;
*((unsigned char *)0xbf68+0*40+37)= 67;
*((unsigned char *)0xbf68+0*40+38)= 68;
*((unsigned char *)0xbf68+0*40+39)= 69;
// bas visage
    *((unsigned char *)0xbf68+1*40+18)= 70;
    *((unsigned char *)0xbf68+1*40+19)= 71;
    *((unsigned char *)0xbf68+1*40+20)= 72;
    *((unsigned char *)0xbf68+1*40+21)= 73;

    *((unsigned char *)0xbf68+2*40+18)= 74;
    *((unsigned char *)0xbf68+2*40+19)= 75;
    *((unsigned char *)0xbf68+2*40+20)= 76;
    *((unsigned char *)0xbf68+2*40+21)= 77;

    
// bsa gun
    *((unsigned char *)0xbf68+1*40+35)= 78;
    *((unsigned char *)0xbf68+1*40+36)= 79;
    *((unsigned char *)0xbf68+1*40+37)= 80;
    *((unsigned char *)0xbf68+1*40+38)= 81;
    *((unsigned char *)0xbf68+1*40+39)= 82;

    *((unsigned char *)0xbf68+2*40+35)= 83;
    *((unsigned char *)0xbf68+2*40+36)= 84;
    *((unsigned char *)0xbf68+2*40+37)= 85;
    *((unsigned char *)0xbf68+2*40+38)= 86;
    *((unsigned char *)0xbf68+2*40+39)= 87;

// colonne 1
    *((unsigned char *)0xbf68+1*40+7)= 88;
    *((unsigned char *)0xbf68+2*40+7)= 89;
    *((unsigned char *)0xbf68+1*40+8)= DOUBLE_STANDARD_CHARSET;
    *((unsigned char *)0xbf68+2*40+8)= DOUBLE_STANDARD_CHARSET;

    *((unsigned char *)0xbf68+1*40+9) = '9';
    *((unsigned char *)0xbf68+2*40+9) = '9';
    *((unsigned char *)0xbf68+1*40+10) = '9';
    *((unsigned char *)0xbf68+2*40+10) = '9';
    *((unsigned char *)0xbf68+1*40+11) = '9';
    *((unsigned char *)0xbf68+2*40+11) = '9';

// colonne 2
    *((unsigned char *)0xbf68+1*40+13)= ALTERNATE_CHARSET;
    *((unsigned char *)0xbf68+2*40+13)= ALTERNATE_CHARSET;
    *((unsigned char *)0xbf68+1*40+14)= 90;
    *((unsigned char *)0xbf68+2*40+14)= 91;

    *((unsigned char *)0xbf68+1*40+15)= DOUBLE_STANDARD_CHARSET;
    *((unsigned char *)0xbf68+2*40+15)= DOUBLE_STANDARD_CHARSET;
    *((unsigned char *)0xbf68+1*40+16) = '9';
    *((unsigned char *)0xbf68+2*40+16) = '9';
    *((unsigned char *)0xbf68+1*40+17)= ALTERNATE_CHARSET;
    *((unsigned char *)0xbf68+2*40+17)= ALTERNATE_CHARSET;


// colonne 3
    *((unsigned char *)0xbf68+1*40+22)= 92;
    *((unsigned char *)0xbf68+2*40+22)= 93;
    *((unsigned char *)0xbf68+1*40+23)= DOUBLE_STANDARD_CHARSET;
    *((unsigned char *)0xbf68+2*40+23)= DOUBLE_STANDARD_CHARSET;
    *((unsigned char *)0xbf68+1*40+24) = '1';
    *((unsigned char *)0xbf68+2*40+24) = '1';
    *((unsigned char *)0xbf68+1*40+25) = '0';
    *((unsigned char *)0xbf68+2*40+25) = '0';
    *((unsigned char *)0xbf68+1*40+26) = '0';
    *((unsigned char *)0xbf68+2*40+26) = '0';

    // *((unsigned char *)0xbf68+1*40+27) = '%';
    // *((unsigned char *)0xbf68+2*40+27) = '%';



// colonne 4
    *((unsigned char *)0xbf68+1*40+27)= ALTERNATE_CHARSET;
    *((unsigned char *)0xbf68+2*40+27)= ALTERNATE_CHARSET;
    *((unsigned char *)0xbf68+1*40+28)= 94;
    *((unsigned char *)0xbf68+2*40+28)= 95;
    *((unsigned char *)0xbf68+1*40+29)= DOUBLE_STANDARD_CHARSET;
    *((unsigned char *)0xbf68+2*40+29)= DOUBLE_STANDARD_CHARSET;
    *((unsigned char *)0xbf68+1*40+30) = '9';
    *((unsigned char *)0xbf68+2*40+30) = '9';

    *((unsigned char *)0xbf68+1*40+31) = '9';
    *((unsigned char *)0xbf68+2*40+31) = '9';


    *((unsigned char *)0xbf68+1*40+32)= ALTERNATE_CHARSET;
    *((unsigned char *)0xbf68+2*40+32)= ALTERNATE_CHARSET;


    // *((unsigned char *)0xbf68+0*40+21)= STANDARD_CHARSET;
    // *((unsigned char *)0xbf68+1*40+21)= DOUBLE_STANDARD_CHARSET;
    // *((unsigned char *)0xbf68+2*40+21)= DOUBLE_STANDARD_CHARSET;
    // *((unsigned char *)49022)= 124;
    // *((unsigned char *)49062)= 124;
    // *((unsigned char *)49102)= 124;
    // *((unsigned char *)49023)= 65; // A
    // *((unsigned char *)49024)= 77; // M
    // *((unsigned char *)49025)= 77; // M
    // *((unsigned char *)49026)= 79; // O
    // *((unsigned char *)49065)= 48;
    // *((unsigned char *)49105)= 48;
    // *((unsigned char *)49066)= 48;
    // *((unsigned char *)49106)= 48;
    // *((unsigned char *)49028)= 124;
    // *((unsigned char *)49068)= 124;
    // *((unsigned char *)49108)= 124;
    // *((unsigned char *)49030)= 70;
    // *((unsigned char *)49031)= 76;
    // *((unsigned char *)49032)= 79;
    // *((unsigned char *)49033)= 87;
    // *((unsigned char *)49034)= 69;
    // *((unsigned char *)49035)= 82;
    // *((unsigned char *)49072)= 51;
    // *((unsigned char *)49112)= 51;
    // *((unsigned char *)49036)= 124;
    // *((unsigned char *)49076)= 124;
    // *((unsigned char *)49116)= 124;

}

void main(){

//     paper(0); ink(7);

    // Deactivate cursor and keyclick
    mode0 = *((unsigned char *)0x26A);
    *((unsigned char *)0x26A) = (mode0 | 0x08) & 0xFE;

    bottom_panel();

    waitkey();
 

    // Reactivate cursor and keyclick
    *((unsigned char *)0x26A) = mode0;

}


