
// North door
signed  char door_0_0_data[] = {
        0,      // state 0 : close,  1..6 : opening, 7: opened ,
        // Points to animate are indexes in scene data of coordinate to change
        56,     
        58,
        1,  // Direction to animate: 1 or -1
        0,  // Place holder for temporisation
        };    // 56 = 27(point n12)*2 (2 coord/point) + 2 (header nbPoints + nbWall)

// North West door
signed  char door_0_1_data[] = {
        0,      // state 0 : close,  1..6 : opening, 7: opened ,
        // Points to animate are indexes in scene data of coordinate to change
        65,     
        67,
        1,  // Direction to animate: 1 or -1
        0,  // Place holder for temporisation
        };    // 64 = 31(point n42)*2 (2 coord/point) + 2 (header nbPoints + nbWall)

// South West door
signed  char door_0_2_data[] = {
        0,      // state 0 : close,  1..6 : opening, 7: opened ,
        // Points to animate are indexes in scene data of coordinate to change
        73,     
        75,
        1,  // Direction to animate: 1 or -1
        0,  // Place holder for temporisation
        };    // 72 = 35(point n46)*2 (2 coord/point) + 2 (header nbPoints + nbWall)

//  South East door
signed  char door_0_3_data[] = {
        0,      // state 0 : close,  1..6 : opening, 7: opened ,
        // Points to animate are indexes in scene data of coordinate to change
        81,     
        83,
        -1,  // Direction to animate: 1 or -1
        0,  // Place holder for temporisation
        };    // 80 = 39(point n46)*2 (2 coord/point) + 2 (header nbPoints + nbWall)

//  North East door
signed  char door_0_4_data[] = {
        0,      // state 0 : close,  1..6 : opening, 7: opened ,
        // Points to animate are indexes in scene data of coordinate to change
        89,     
        91,
        -1,  // Direction to animate: 1 or -1
        0,  // Place holder for temporisation
        };    // 88 = 43(point n46)*2 (2 coord/point) + 2 (header nbPoints + nbWall)

signed char soldier1Data [] = {
    1,          // [0] state: 0=dead, 1=walking, 
    0,          // [1] direction
    4,          // [2] health
    0,          // [3] placeholder for xDeathPos
    0,          // [4] placeholder for yDeathPos
    -15,        // [5] min excursion
    15          // [6] max excursion
    };


void engScene_04(){

        // North door
        engObjType = OBJ_DOOR;
        engObjX     = 0;
        engObjY     = 30;
        engObjData  = door_0_0_data;
        engAddObjectASM();
        objTexture[0] = 0;

        // North West door
        engObjType = OBJ_DOOR;
        engObjX     = -12;
        engObjY     = 18;
        engObjData  = door_0_1_data;
        engAddObjectASM();
        objTexture[1] = 0;

        // South West door
        engObjType = OBJ_DOOR;
        engObjX     = -12;
        engObjY     = 0;
        engObjData  = door_0_2_data;
        engAddObjectASM();
        objTexture[2] = 0;

        //  South East door
        engObjType = OBJ_DOOR;
        engObjX     = 12;
        engObjY     = 0;
        engObjData  = door_0_3_data;
        engAddObjectASM();
        objTexture[3] = 0;

        //  North East door
        engObjType = OBJ_DOOR;
        engObjX     = 12;
        engObjY     = 18;
        engObjData  = door_0_4_data;
        engAddObjectASM();
        objTexture[4] = 0;

        engObjType = OBJ_SOLDIER;
        engObjX     = 0; // 2; // 
        engObjY     = -18; // 0; // 
        engObjData  = soldier1Data;
        engAddObjectASM();
        objTexture[5] = soldier_front;

        engObjType = OBJ_LAMP;
        engObjX     = 0;
        engObjY     = 18;
        engObjData  = 0;
        engAddObjectASM();
        objTexture[6] = lamp_1;

        engObjType = OBJ_LAMP;
        engObjX     = 0;
        engObjY     = 0;
        engObjData  = 0;
        engAddObjectASM();
        objTexture[7] = lamp_1;

        engObjType = OBJ_LAMP;
        engObjX     = -21;
        engObjY     = -18;
        engObjData  = 0;
        engAddObjectASM();
        objTexture[8] = lamp_1;

        engObjType = OBJ_LAMP;
        engObjX     = 21;
        engObjY     = -18;
        engObjData  = 0;
        engAddObjectASM();
        objTexture[9] = lamp_1;
        
        engObjType = OBJ_AMMO; //
        engObjX     = 30;
        engObjY     = -18;
        engObjData  = 0;
        engAddObjectASM();
        objTexture[10] = texture_ammo_1;//

        engObjType = OBJ_DEAD_SOLDIER;
        engObjX     = -18;
        engObjY     = 0;
        engObjData  = 0;
        engAddObjectASM();
        objTexture[11] = sprite_deadsoldier;


        engObjType = OBJ_PIECE_OF_MEAT;
        engObjX     = 0;
        engObjY     = -25;
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
};