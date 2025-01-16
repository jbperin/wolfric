
// [ref texture_file2buffer]
// #include "texture_christmas.h"
// #include "texture_bluestone.h"
// #include "texture_redbrick.h"
// #include "texture_logo.h"
// #include "textures/texture_bigbricks.h"
// #include "textures/texture_bigleaves.h"
// #include "textures/texture_bigsquares.h"
// #include "textures/texture_dentwall.h"

extern unsigned char bluewall[];
extern unsigned char metalwall[];
extern unsigned char stone_wall[];
extern unsigned char sculpture[];
extern unsigned char flag[];
extern unsigned char wood_wall[];
extern unsigned char gridwall[];
extern unsigned char portrait[];
extern unsigned char door_1[];
extern unsigned char soldier_front[];
extern unsigned char soldier_back[];
extern unsigned char soldier_left[];
extern unsigned char soldier_right[];
#include "textures/hurt_soldier.h"
#include "textures/ammo_1.h"
unsigned char wallTexture_high[NB_MAX_WALL] ;
unsigned char wallTexture_low[NB_MAX_WALL] ;

// [ref scene_describe]
signed char scene_00[] = {
    /* nbPoints = */ 72, /* nbWall = */ 65,
        -3, 39 , 	// P0
        -9, 39 , 	// P1
        -9, 33 , 	// P2
        -9, 27 , 	// P3
        -9, 3 , 	// P4
        -9, -3 , 	// P5
        -9, -15 , 	// P6
        -15, -15 , 	// P7
        -39, -15 , 	// P8
        -39, -33 , 	// P9
        -33, -33 , 	// P10
        -15, -33 , 	// P11
        -9, -33 , 	// P12
         9, -33 , 	// P13
        15, -33 , 	// P14
        33, -33 , 	// P15
        39, -33 , 	// P16
        39, -15 , 	// P17
        15, -15 , 	// P18
        9, -15 , 	// P19
        9, -3 , 	// P20
        9, 3 , 	// P21
        9, 27 , 	// P22
        9, 33 , 	// P23
        9, 39 , 	// P24
        3, 39 , 	// P25
        3, 45 , 	// P26
        -3, 45 , 	// P27
        -3, 42 , 	// P28
        3, 42 , 	// P29
        -15, 33 , 	// P30
        -15, 27 , 	// P31
        -12, 27 , 	// P32
        -12, 33 , 	// P33
        -15, 3 , 	// P34
        -15, -3 , 	// P35
        -12, 3 , 	// P36
        -12, -3 , 	// P37
        15, 3 , 	// P38
        15, -3 , 	// P39
        12, -3 , 	// P40
        12, 3 , 	// P41
        15, 27 , 	// P42
        15, 33 , 	// P43
        12, 33 , 	// P44
        12, 27 , 	// P45

        -9, 45 , 	// P46
        -9, 69 , 	// P47
        -3, 69 , 	// P48
         3, 69 , 	// P49
         9, 69 , 	// P50
         9, 45 , 	// P51
        -3, 75 , 	// P52
         3, 75 , 	// P53
         3, 72 , 	// P54
        -3, 72 , 	// P55

        -15, -9 , 	// P56
        -39, -9 , 	// P57
        -39, 9  , 	// P58
        -15, 9 , 	// P59

        -15, 15 , 	// P60
        -39, 15 , 	// P61
        -39, 39  , 	// P62
        -15, 39 , 	// P63

        15, 39 , 	// P64
        39, 39 , 	// P65
        39, 15  , 	// P66
        15, 15 , 	// P67

        15, 9 , 	// P68
        39, 9 , 	// P69
        39, -9  , 	// P70
        15, -9 , 	// P71

    0, 1, //	S0 
    1, 2, //	S1
    3, 4, //    S2
    5, 6, //    S3
    6, 7, //    S4
    7, 8, //    S5
    8, 9, //    S6
    9, 10, //   S7
    10, 11, //   S8
    11, 12, //   S9
    12, 13, //   S10
    13, 14, //   S11
    14, 15, //   S12
    15, 16, //   S13
    16, 17, //   S14
    17, 18, //   S15
    18, 19, //   S16
    19, 20, //   S17
    21, 22, //   S18
    23, 24, //   S19
    24, 25, //   S20
    25, 26, //   S21
     0, 27, //   S22
    28, 29, //   S23 door_0_0 
    2, 30,  //   S24
     3, 31, //   S25
    32, 33, //   S26 door_0_1 
    4, 34,  //   S27
     5, 35, //   S28
    36, 37, //   S29 door_0_2 
    21, 38,  //   S30
    20, 39, //   S31
    40, 41, //   S32 door_0_3
    22, 42,  //   S33
    23, 43, //   S34
    44, 45, //   S35 door_0_4

    27, 46, //   S36
    46, 47, //   S37
    47, 48, //   S38
    49, 50, //   S39
    50, 51, //   S40
    51, 26, //   S41
    48, 52, //   S42
    49, 53, //   S43
    55, 54, //   S44

    35, 56, //   S45
    56, 57, //   S46
    57, 58, //   S47
    58, 59, //   S48
    59, 34, //   S49

    31, 60, //   S50
    60, 61, //   S51
    61, 62, //   S52
    62, 63, //   S53
    63, 30, //   S54

    43, 64, //   S55
    64, 65, //   S56
    65, 66, //   S57
    66, 67, //   S58
    67, 42, //   S59

    38, 68, //   S60
    68, 69, //   S61
    69, 70, //   S62
    70, 71, //   S63
    71, 39, //   S64

};

unsigned char *texture_00[]= {
	bluewall        // W0
	, bluewall // W1
	, bluewall // W2
	, bluewall // W3
	, bluewall // W4
	, bluewall // W5
	, bluewall // W6
	, gridwall // W7
	, bluewall // W8
	, gridwall // W9
	, bluewall // W10
	, gridwall // W11
	, bluewall // W12
	, gridwall // W13
	, bluewall // W14
	, bluewall // W15
	, bluewall // W16
	, bluewall // W17
	, bluewall // W18
	, bluewall // W19
	, bluewall // W20
	, metalwall // W21
	, metalwall // W22
	, door_1 // W23 
	, metalwall // W24
	, metalwall // W25
	, door_1 // W26 
	, metalwall // W27
	, metalwall // W28
	, door_1 // W29 
	, metalwall // W30
	, metalwall // W31
	, door_1 // W32 
	, metalwall // W34
	, metalwall // W34
	, door_1 // W35 

    , bluewall  //   W36
    , bluewall  //   W37
    , bluewall  //   W38
    , bluewall  //   W39
    , bluewall  //   W40
    , bluewall  //   W41
    , metalwall //   W42
    , metalwall //   W43
    , door_1    //   W44  door

    , bluewall  //   W45
    , bluewall  //   W46
    , bluewall  //   W47
    , bluewall  //   W48
    , bluewall  //   W49

    , bluewall  //   W50
    , bluewall  //   W51
    , bluewall  //   W52
    , bluewall  //   W53
    , bluewall  //   W54

    , bluewall  //   W55
    , bluewall  //   W56
    , bluewall  //   W57
    , bluewall  //   W58
    , bluewall  //   W59

    , bluewall  //   W60
    , bluewall  //   W61
    , bluewall  //   W62
    , bluewall  //   W63
    , bluewall  //   W64

};

signed char scene_01[] = {
    /* nbPoints = */ 89, /* nbWall = */ 79,
        -3, -27 , 	// P0
        -15, -27 , 	// P1
        -15, -21 , 	// P2
        -33, -21 , 	// P3
        -39, -21 , // P4
        -45, -21 , // P5
        -45, -15 , // P6
        -45, -9 , // P7
        -45, 9 , // P8
        -45, 15 , // P9
        -45, 21 , // P10
        -27, 21 , // P11
        -21, 21 , // P12
        -15, 21 , // P13
        -15, 27 , // P14
        -3, 27 , // P15
         3, 27 , // P16
        15, 27 , // P17
        15, 21 , // P18
        21, 21 , // P19
        27, 21 , // P20
        45, 21 , // P21
        45, 15 , // P22
        45, 9 , // P23
        51, 9 , // P24
        51, 3 , // P25
        51, -3 , // P26
        51, -9 , // P27
        45, -9 , // P28
        45, -15 , // P29
        45, -21 , // P30
        33, -21 , // P31
        27, -21 , // P32
        15, -21 , // P33
        15, -27 , // P34
        3, -27 , // P35
        3, -33 , // P36   door_1_0
        -3, -33 , // P37
        -3, -30 , // P38
        3, -30 , // P39
        57, 3 , // P40   door_1_1
        57, -3 , // P41
        54, -3 , // P42
        54, 3 , // P43
        -3, 33 , // P44   door_1_2
        3, 33 , // P45
        3, 30 , // P46
        -3, 30 , // P47

        // transition to scene 00
        -9, -33 , // P48
        -9, -57 , // P49
        -3, -57 , // P50
         3, -57 , // P51
         9, -57 , // P52
         9, -33 , // P53
        -3, -63 , // P54
         3, -63 , // P55
         3, -60 , // P56
        -3, -60 , // P57

        // transition to scene 02
        57,  -9 , // P58
        69,  -9 , // P59
        69, -15 , // P60
        75, -15 , // P61
        87, -15 , // P62
        93, -15 , // P63
        93,  -9 , // P64
        111, -9 , // P65
        111, -3 , // P66
        111,  3 , // P67
        111,  9 , // P68
        87,  9 ,  // P69
        63,  9 ,  // P70
        57,  9 ,  // P71

        117,  3 , // P72
        117, -3 , // P73
        114, -3 , // P74
        114,  3 , // P75
        87, -39,  // P76

        -9,  33,  // P77
        -9,  57,  // P78
        -21, 63,  // P79
        -9,  63,  // P80
        -9, 87,  // P81
        -3, 87,  // P82
        3, 87,  // P83
        9,  87,  // P84
        9, 63,  // P85
        21, 63,  // P86
        9,  57,  // P87
        9, 33,  // P88


    0, 1, //	S0 
    1, 2, //	S1 
    2, 3, //	S2 
    3, 4, //	S3
    4, 5, //	S4
    5, 6, //	S5
    6, 7, //	S6
    7, 8, //	S7
    8, 9, //	S8
    9, 10, //	S9
    10, 11, //	S10
    11, 12, //	S11
    12, 13, //	S12
    13, 14, //	S13
    14, 15, //	S14
    16, 17, //	S15
    17, 18, //	S16
    18, 19, //	S17
    19, 20, //	S18
    20, 21, //	S19
    21, 22, //	S20
    22, 23, //	S21
    23, 24, //	S22
    24, 25, //	S23
    26, 27, //	S24
    27, 28, //	S25
    28, 29, //	S26
    29, 30, //	S27
    30, 31, //	S28
    31, 32, //	S29
    32, 33, //	S30
    33, 34, //	S31
    34, 35, //	S32
    35, 36, //  S33
    37, 0,  //  S34
    38, 39, //  S35 door_1_0
    25, 40, //  S36
    26, 41, //  S37
    42, 43, //  S38 door_1_1
    15, 44, //  S39
    16, 45, //  S40
    46, 47, //  S41 door_1_1

    37, 48, //  S42
    48, 49, //  S43
    49, 50, //  S44
    51, 52, //  S45
    52, 53, //  S46
    53, 36, //  S47
    50, 54, //  S48
    51, 55, //  S49
    56, 57, //  S50 door

    // transition to scene 02
    41, 58, //  S51
    58, 59, //  S52
    59, 60, //  S53
    60, 61, //  S54
    62, 63, //  S55
    63, 64, //  S56
    64, 65, //  S57
    65, 66, //  S58
    67, 68, //  S59
    68, 69, //  S60
    69, 70, //  S61
    70, 71, //  S62
    40, 71, //  S63

    67, 72, //  S64
    66, 73, //  S65
    74, 75, //  S66
    62, 76, //  S67

    44, 77, //  S68
    77, 78, //  S69
    79, 80, //  S70
    80, 81, //  S71
    81, 82, //  S72
    83, 84, //  S73
    84, 85, //  S74
    85, 86, //  S75
    87, 88, //  S76
    88, 45, //  S77
    
    82, 83, //  S78



};
unsigned char *texture_01[]= {
	  bluewall      // W0
	, bluewall      // W1
	, stone_wall    // W2
	, portrait      // W3
	, stone_wall    // W4
	, stone_wall    // W5
	, sculpture     // W6
	, stone_wall    // W7
	, sculpture     // W8
	, stone_wall    // W9
	, stone_wall    // W10
	, flag          // W11
	, stone_wall    // W12
	, stone_wall    // W13
	, wood_wall     // W14
	, wood_wall     // W15
	, stone_wall    // W16
	, stone_wall    // W17
	, flag          // W18
	, stone_wall    // W19
	, stone_wall    // W20
	, sculpture     // W21
	, sculpture     // W22
	, bluewall      // W23
	, bluewall      // W24
	, sculpture     // W25
	, sculpture     // W26
	, stone_wall    // W27
	, stone_wall    // W28
	, portrait      // W29
	, stone_wall    // W30
	, stone_wall    // W31
	, bluewall      // W32
	, metalwall     // W33
	, metalwall     // W34
	, door_1        // W35
	, metalwall     // W36
	, metalwall     // W37
	, door_1        // W38
	, metalwall     // W39
	, metalwall     // W40
	, door_1        // W41

    , bluewall //  W42
    , bluewall //  W43
    , bluewall //  W44
    , bluewall //  W45
    , bluewall //  W46
    , bluewall //  W47
    , bluewall //  W48
    , bluewall //  W49
    , door_1   //  W50 door

    , bluewall //  W51
    , bluewall //  W52
    , bluewall //  W53
    , bluewall //  W54
    , bluewall //  W55
    , bluewall //  W56
    , bluewall //  W57
    , bluewall //  W58
    , bluewall //  W59
    , bluewall //  W60
    , bluewall //  W61
    , bluewall //  W62
    , bluewall //  W63

    , metalwall //  S64
    , metalwall //  S65
    , door_1 //  S66
    , bluewall //  S67

    , wood_wall     //  W68
    , wood_wall     //  W69
    , wood_wall     //  W70
    , wood_wall     //  W71
    , wood_wall     //  W72
    , wood_wall     //  W73
    , wood_wall     //  W74
    , wood_wall     //  W75
    , wood_wall     //  W76
    , wood_wall     //  W77

    , door_1 //  S78
};


signed char scene_02[] = {
    /* nbPoints = */ 52, /* nbWall = */ 47,
        -24, -3 , 	// P0
        -24, -9 , 	// P1
        -12, -9 , 	// P2
        -12, -15 , 	// P3
        -6, -15 , 	// P4
        -6, -39 , 	// P5
        -6, -57 , 	// P6
        -6, -75 , 	// P7
        12, -75 , 	// P8
        12, -69 , 	// P9
        12, -63 , 	// P10
        12, -57 , 	// P11
        6, -57 , 	// P12
        6, -39 , 	// P13
        6, -15 , 	// P14
        12, -15 , 	// P15
        12, -9 , 	// P16
        30, -9 , 	// P17
        30, -3 , 	// P18
        30, 3 , 	// P19
        30, 9 , 	// P20
        6, 9 , 	// P21
        -18, 9 , 	// P22
        -24, 9 , 	// P23
        -24, 3 , 	// P24

        -30, 3 , 	// P25
        -30, -3 , 	// P26
        -27, -3 , 	// P27
        -27, 3 , 	// P28

        18, -69 , 	// P29
        18, -63 , 	// P30
        15, -63 , 	// P31
        15, -69 , 	// P32

        36, 3 , 	// P33
        36, -3 , 	// P34
        33, -3 , 	// P35
        33, 3 , 	// P36

        36 , -27, 	// P37
        48 , -27, 	// P38
        48, -33 , 	// P39
        54, -33 , 	// P40
        54 ,-27,  	// P41
        66 ,-27,  	// P42
        66, -33 , 	// P43
        72, -33 , 	// P44
        72, -27, 	// P45
        84, -27 , 	// P46
        84, -3 , 	// P47
        84, 3 , 	// P48
        84, 27 , 	// P49
        60, 27, 	// P50
        36, 27, 	// P51


    0, 1, //	S0 
    1, 2, //	S1 
    2, 3, //	S2 
    3, 4, //	S3
    4, 5, //	S4
    5, 6, //	S5
    6, 7, //	S6
    7, 8, //	S7
    8, 9, //	S8
    10, 11, //	S9
    11, 12, //	S10
    12, 13, //	S11
    13, 14, //	S12
    14, 15, //	S13
    15, 16, //  S14
    16, 17, //	S15
    17, 18, //	S16
    19, 20, //	S17
    20, 21, //	S18
    21, 22, //	S19
    22, 23, //	S20
    23, 24, //	S21

    24, 25, //	S22
     0, 26, //	S23
    27, 28, //	S24 door_02_00

     9, 29, //	S25
    10, 30, //	S26
    31, 32, //	S27 door_02_01

    18, 34, //	S28
    19, 33, //	S29
    35, 36, //	S30 door_02_02

    34  , 37 , // S31
    37  , 38 , // S32
    38  , 39 , // S33
    39  , 40 , // S34
    40  , 41 , // S35
    41  , 42 , // S36
    42  , 43 , // S37
    43  , 44 , // S38
    44  , 45 , // S39
    45  , 46 , // S40
    46  , 47 , // S41
    47  , 48 , // S42
    48  , 49 , // S43
    49  , 50 , // S44
    50  , 51 , // S45
    51  , 33 , // S46


};
unsigned char *texture_02[]= {
	  bluewall      // W0
	, bluewall      // W1
	, bluewall    // W2
	, bluewall      // W3
	, bluewall    // W4
	, bluewall    // W5
	, bluewall     // W6
	, bluewall    // W7
	, bluewall     // W8
	, bluewall    // W9
	, bluewall    // W10
	, bluewall          // W11
	, bluewall    // W12
	, bluewall    // W13
	, bluewall     // W14
	, bluewall     // W15
	, bluewall    // W16
	, bluewall    // W17
	, bluewall          // W18
	, bluewall    // W19
	, bluewall    // W20
	, bluewall     // W21
	, metalwall     // W22
	, metalwall     // W23
	, door_1        // W24
	, metalwall     // W25
	, metalwall     // W26
	, door_1        // W27
	, metalwall     // W28
	, metalwall     // W29
	, door_1        // W30

    , bluewall      // W31
    , bluewall      // W32
    , bluewall      // W33
    , bluewall      // W34
    , bluewall      // W35
    , bluewall      // W36
    , bluewall      // W37
    , bluewall      // W38
    , bluewall      // W39
    , bluewall      // W40
    , bluewall      // W41
    , bluewall      // W42
    , bluewall      // W43
    , bluewall      // W44
    , bluewall      // W45
    , bluewall      // W46

};
// [ref scene_load]
void precalculateWallsAngle() {
    unsigned char idxWall, idxPt1, idxPt2;
    signed char dX, dY, angle;

    for (idxWall = 0; idxWall < rayNbWalls; idxWall ++) { 

        idxPt1 = lWallsPt1[idxWall];
        idxPt2 = lWallsPt2[idxWall];

        dX = lPointsX[idxPt2]-lPointsX[idxPt1];
        dY = lPointsY[idxPt2]-lPointsY[idxPt1];

        if (dX == 0) {
            lWallsCosBeta[idxWall] = 0;
        } else if (dY == 0) {
            if (dX > 0) {
                lWallsCosBeta[idxWall] = 32;
            } else {
                lWallsCosBeta[idxWall] = -32;
            }
        } else {
            /* 
             *  Not aligned walls not handled
             */
        }
    }
}

// [ref scene_describe] [ref scene_load]
void initScene (signed char sceneData[], unsigned char *wallTexture[]){
	unsigned int ii;
	unsigned char jj;

	ii=0;
	rayNbPoints = (unsigned char)sceneData[ii++];
	rayNbWalls = (unsigned char)sceneData[ii++];
	for (jj=0; jj < rayNbPoints; jj++){
		lPointsX[jj]= sceneData[ii++] ; lPointsY[jj] = sceneData[ii++];  // points 0
	}
	for (jj=0; jj < rayNbWalls; jj++){
		lWallsPt1[jj]= (unsigned char)(sceneData[ii++]) ; lWallsPt2[jj] = (unsigned char)(sceneData[ii++]);// points 0
#ifndef __GNUC__
        wallTexture_high[jj]    = (unsigned char)((((int)(wallTexture[jj])&0xFF00) >> 8) & 0x00FF);
        wallTexture_low[jj]     = (unsigned char)(((int)(wallTexture[jj])&0x00FF));
#endif		
	}
    precalculateWallsAngle();
}
