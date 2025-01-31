// South door
signed  char door_2_1_data[] = {
        0,      // state 0 : close,  1..6 : opening, 7: opened ,
        // Points to animate are indexes in scene data of coordinate to change
        41,     
        43,
        1,  // Direction to animate: 1 or -1
        0,  // Place holder for temporisation
        };    // 64 = 19(point n42)*2 (2 coord/point) + 2 (header nbPoints + nbWall)
// North door
signed  char door_2_2_data[] = {
        0,      // state 0 : close,  1..6 : opening, 7: opened ,
        // Points to animate are indexes in scene data of coordinate to change
        49,     
        51,
        -1,  // Direction to animate: 1 or -1
        0,  // Place holder for temporisation
        };    // 49 = 23(point n46)*2 (2 coord/point) + 2 (header nbPoints + nbWall) + 1 for Y component


signed char soldier2Data [] = {
    1,          // [0] state: 0=dead, 1=walking, 
    0,          // [1] direction
    4,          // [2] health
    0,          // [3] placeholder for xDeathPos
    0,          // [4] placeholder for yDeathPos
    27,        // [5] min excursion
    45          // [6] max excursion
    };


void engScene_05(){

        // South door
        engObjType = OBJ_DOOR;
        engObjX     = 12;
        engObjY     = -36;
        engObjData  = door_2_1_data;
        engAddObjectASM();
        objTexture[0] = 0;

        // North door
        engObjType = OBJ_DOOR;
        engObjX     = 18;
        engObjY     = 0;
        engObjData  = door_2_2_data;
        engAddObjectASM();
        objTexture[1] = 0;

        engObjType = OBJ_PLANT;
        engObjX     = 42;
        engObjY     = 12;
        engObjData  = 0;
        engAddObjectASM();
        objTexture[2] = barrel;

        engObjType = OBJ_PLANT;
        engObjX     = 36;
        engObjY     = 6;
        engObjData  = 0;
        engAddObjectASM();
        objTexture[3] = table;

        engObjType = OBJ_PLANT;
        engObjX     = 30;
        engObjY     = -18;
        engObjData  = 0;
        engAddObjectASM();
        objTexture[4] = well;

        engObjType = OBJ_PLANT;
        engObjX     = 42;
        engObjY     = -18;
        engObjData  = 0;
        engAddObjectASM();
        objTexture[5] = well;

        engObjType = OBJ_PLANT;
        engObjX     = 48;
        engObjY     = 12;
        engObjData  = 0;
        engAddObjectASM();
        objTexture[6] = barrel;

        engObjType = OBJ_SOLDIER;
        engObjX     = 36; // 2; // 
        engObjY     = 0; // 0; // 
        engObjData  = soldier2Data;
        engAddObjectASM();
        objTexture[7] = soldier_front;

}
