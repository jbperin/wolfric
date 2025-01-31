signed char scene_03[] = {
    /* nbPoints = */ 68, /* nbWall = */ 61,
        0,  0, 	// P0
        -3,  -15, 	// P1
        -9,  -15, 	// P2
        -9,  -9, 	// P3
        -15, -9 , 	// P4
        -21, -9 , 	// P5
        -27, -9 , 	// P6
        -27, -3 , 	// P7
        -27,  3, 	// P8
        -27,  9, 	// P9
        -21,  9, 	// P10
        -15,  9, 	// P11
        -9,  9, 	// P12
        -9,  15, 	// P13
        -3,  15, 	// P14
        3,  15, 	// P15
        9,  15, 	// P16
        9,  9, 	// P17
        15,  9, 	// P18
        21,  9, 	// P19
        27,  9, 	// P20
        27, 3 , 	// P21
        27, -3 , 	// P22
        27, -9 , 	// P23
        21, -9 , 	// P24
        15, -9 , 	// P25
        9,  -9, 	// P26
        9, -15 , 	// P27
        3, -15 , 	// P28

        // South door
        3, -18 , 	// P29
        -3, -18, 	// P30
        -3, -21 , 	// P31
        3, -21 , 	// P32

        // North door
        -3, 18 , 	// P33
        3,  18, 	// P34
        3, 21 , 	// P35
        -3, 21 , 	// P36

        // East door
        30, 3 , 	// P37
        30, -3, 	// P38
        33, -3 , 	// P39
        33, 3 , 	// P40


        -9, -21 , 	// P41
        -9, -45 , 	// P42
        -3, -45 , 	// P43
         3, -45 , 	// P44
         9, -45 , 	// P45
         9, -21 , 	// P46
        
        -9, 21 , 	// P47
        -9, 33 , 	// P48
        -21, 39 , 	// P49
        -9, 39 , 	// P50
        -9, 51 , 	// P51
        -3, 51 , 	// P52
        3, 51 , 	// P53
        9, 51 , 	// P54
        9, 39 , 	// P55
        21, 39 , 	// P56
        9, 33 , 	// P57
        9, 21 , 	// P58

        33, -9 , 	// P59
        45, -9 , 	// P60
        57, -33 , 	// P61
        57, -9 , 	// P62
        63, -9 , 	// P63
        63, -3 , 	// P64
        63, 3 , 	// P65
        63, 9 , 	// P66
        33, 9 , 	// P67


    1, 2, //	S0 
    2, 3, //	S1 
    3, 4, //	S2 
    4, 5, //	S3
    5, 6, //	S4
    6, 7, //	S5
    7, 8, //	S6
    8, 9, //	S7
    9, 10,  //  S8
    10, 11, //	S9
    11, 12, //	S10
    12, 13, //	S11
    13, 14, //	S12
    15, 16, //  S13
    16, 17, //	S14
    17, 18, //	S15
    18, 19, //	S16
    19, 20, //	S17
    20, 21, //	S18
    22, 23, //	S19
    23, 24, //	S20
    24, 25, //	S21
    25, 26, //	S22
    26, 27, //	S23    
    27, 28, //	S24

    1, 31, //  S25
    28, 32,  //  S26
    30, 29, //  S27 door_x_x
    21, 40, //  S28
    22, 39, //  S29
    37, 38, //  S30 door_x_x
    14, 36, //  S31
    15, 35, //  S32
    33, 34, //  S33 door_x_x

    31, 41, //	S34
    41, 42, //	S35
    42, 43, //	S36
    43, 44, //	S37 door
    44, 45, //	S38
    45, 46, //	S39
    46, 32, //	S40


    36, 47, //	S41
    47, 48, //	S42
    49, 50, //	S43
    50, 51, //	S44
    51, 52, //	S45
    52, 53, //	S46 door
    53, 54, //	S47
    54, 55, //	S48
    55, 56, //	S49
    57, 58, //	S50
    58, 35, //	S51

    39, 59, //	S52
    59, 60, //	S53
    61, 62, //	S54
    62, 63, //	S55
    63, 64, //	S56
    64, 65, //	S57 door
    65, 66, //	S58
    66, 67, //	S59
    67, 40, //	S60

};

unsigned char *texture_03[]= {
	  bluewall      // W0
	, bluewall      // W1
	, stone_wall    // W2
	, portrait      // W3
	, stone_wall    // W4
	, stone_wall    // W5
	, sculpture     // W6
	, stone_wall    // W7
	, stone_wall     // W8
	, flag          // W9
	, stone_wall    // W10
	, wood_wall     // W11
	, wood_wall     // W12
	, wood_wall     // W13
	, wood_wall     // W14
	, stone_wall    // W15
	, flag          // W16
	, stone_wall    // W17
	, sculpture     // W18
	, sculpture     // W19
	, stone_wall    // W20
	, portrait      // W21
	, stone_wall    // W22
	, bluewall      // W23
	, bluewall      // W24

    , metalwall     // W25
    , metalwall     // W26
    , door_1        // W27

    , metalwall     // W28
    , metalwall     // W29
    , door_1        // W30

    , metalwall     // W31
    , metalwall     // W32
    , door_1        // W33

    , bluewall      // W34
	, bluewall      // W35
	, bluewall      // W36
	, door_1      // W37
	, bluewall      // W38
	, bluewall      // W39
	, bluewall      // W40
	, wood_wall     // W41
	, wood_wall     // W42
	, wood_wall     // W43
	, wood_wall     // W44
	, wood_wall     // W45
	, door_1     // W46
	, wood_wall     // W47
	, wood_wall     // W48
	, wood_wall     // W49
	, wood_wall     // W50
	, wood_wall     // W51
	, bluewall      // W52
	, bluewall      // W53
	, bluewall      // W54
	, bluewall      // W55
	, bluewall      // W56
	, door_1      // W57
	, bluewall      // W58
	, bluewall      // W59
	, bluewall      // W60

};
