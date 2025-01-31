signed char scene_04[] = {
    /* nbPoints = */ 63, /* nbWall = */ 59,
        0,  0, 	// P0
        -3,  27, 	// P1
        -9,  27, 	// P2
        -9,  21, 	// P3
        -9, 15 , 	// P4
        -9, 3 , 	// P5
        -9, -3 , 	// P6
        -9, -9 , 	// P7
        -33, -9, 	// P8
        -33,  -27, 	// P9
        -21,  -27, 	// P10
        -15,  -27, 	// P11
        -3,  -27, 	// P12
        3,  -27, 	// P13
        15,  -27, 	// P14
        21,  -27, 	// P15
        33,  -27, 	// P16
        33,  -9, 	// P17
        9,  -9, 	// P18
        9,  -3, 	// P19
        9,  3, 	    // P20
        9, 15 , 	// P21
        9, 21 , 	// P22
        9, 27 , 	// P23
        3, 27 , 	// P24

        // North door
        3, 33 , 	// P25
        -3,  33, 	// P26
        -3, 30, 	// P27
        3, 30 , 	// P28

        // North West door
        -15, 15 , 	// P29
        -15, 21, 	// P30
        -12, 21 , 	// P31
        -12, 15 , 	// P32

        // South West door
        -15, 3 , 	// P33
        -15, -3, 	// P34
        -12, -3 , 	// P35
        -12, 3 , 	// P36

        //  South East door
        15, -3 , 	// P37
        15, 3, 	// P38
        12, -3 , 	// P39
        12, 3 , 	// P40

        //  North East door
        15, 15 , 	// P41
        15, 21 , 	// P42
        12, 21 , 	// P43
        12, 15 , 	// P44

        
        -9, 33 , 	// P45
        -9, 57 , 	// P46
        -3, 57 , 	// P47
        -3, 60 , 	// P48
        3, 60 , 	// P49
        3, 57 , 	// P50
        9, 57 , 	// P51
        9, 33 , 	// P52

        -15, 27, 	// P53
        -33, 27 , 	// P54
        -33, 9 , 	// P55
        -15, 9 ,    // P56

        -15, -9 , 	// P57

        15, -9 , 	// P58

        15, 9 , 	// P59
        33, 9 , 	// P60
        33, 27 , 	// P61
        15, 27 , 	// P62

        // 57, -9 , 	// P63
        // 57, -3 , 	// P64
        // 57, 3 , 	// P65
        // 57, 9 , 	// P66
        // 33, 9 , 	// P67


    26, 45, //	S0 
    1, 2, //	S1 
    2, 3, //	S2 
    4, 5, //	S3
    6, 7, //	S4
    7, 8, //	S5
    8, 9, //	S6
    9, 10,  //  S7
    10, 11, //	S8
    11, 12, //	S9
    12, 13, //	S10
    13, 14, //	S11
    14, 15, //  S12
    15, 16, //	S13
    16, 17, //	S14
    17, 18, //	S15
    18, 19, //	S16
    20, 21, //	S17
    22, 23, //	S18
    23, 24, //	S19

    1, 26,  //	S20
    24, 25, //	S21
    27, 28, //	S22 // North door
    3, 30, //	S23    
    4, 29, //	S24
    32, 31,  //  S25 // North West door
    5, 33, //  S26
    6, 34, //  S27 
    35, 36, //  S28 // South West door
    19, 37, //  S29
    38, 20, //  S30 
    40, 39, //  S31 //  South East door
    21, 41, //  S32
    22, 42, //  S33 
    43, 44, //	S34 //  North East door

    45, 46, //	S35
    46, 47, //	S36
    47, 48, //	S37
    48, 49, //	S38 door
    49, 50, //	S39
    50, 51, //	S40
    51, 52, //	S41
    52, 25, //	S42

    30, 53, //	S43
    53, 54, //	S44
    54, 55, //	S45
    55, 56, //	S46
    56, 29, //	S47
    8, 55,  //	S48
    57, 34, //	S49
    33, 56, //	S50

    58, 37, //	S51
    17, 60, //	S52
    59, 60, //	S53
    38, 59, //	S54
    59, 41, //	S55
    60, 61, //	S56
    61, 62, //	S57
    62, 42, //	S58
    // 66, 67, //	S59
    // 67, 40, //	S60

};

unsigned char *texture_04[]= {
	  bluewall      // W0
	, bluewall      // W1
	, bluewall      // W2
	, bluewall      // W3
	, bluewall      // W4
	, bluewall      // W5
	, bluewall      // W6
	, bluewall      // W7
	, gridwall      // W8
	, bluewall      // W9
	, gridwall      // W10
	, bluewall      // W11
	, gridwall      // W12
	, bluewall      // W13
	, bluewall      // W14
	, bluewall      // W15
	, bluewall      // W16
	, bluewall      // W17
	, bluewall      // W18
	, bluewall      // W19
	, metalwall     // W20
	, metalwall     // W21
	, door_1        // W22
	, metalwall     // W23
	, metalwall     // W24
    , door_1        // W25
    , metalwall     // W26
    , metalwall     // W27
    , door_1        // W28
    , metalwall     // W29
    , metalwall     // W30
    , door_1        // W31
    , metalwall     // W32
    , metalwall     // W33
    , door_1        // W34

	, bluewall      // W35
	, bluewall      // W36
	, metalwall     // W37
	, door_1        // W38
	, metalwall     // W39
	, bluewall      // W40
	, bluewall      // W41
	, bluewall      // W42

	, bluewall     // W43
	, bluewall     // W44
	, bluewall     // W45
	, bluewall     // W46
	, bluewall     // W47

	, bluewall     // W48
	, bluewall     // W49
	, bluewall     // W50

	, bluewall     // W51
	, bluewall      // W52
	, bluewall      // W53
	, bluewall      // W54
	, bluewall      // W55
	, bluewall      // W56
	, bluewall      // W57
	, bluewall      // W58
	// , bluewall      // W59
	// , bluewall      // W60

};
