
// West door
signed  char door_6_1_data[] = {
        0,      // state 0 : close,  1..6 : opening, 7: opened ,
        // Points to animate are indexes in scene data of coordinate to change
        45,     
        47,
        1,  // Direction to animate: 1 or -1
        0,  // Place holder for temporisation
        };    // 45 = 21(point n42)*2 (2 coord/point) + 2 (header nbPoints + nbWall) + 1 for y 

// South door
signed  char door_6_2_data[] = {
        0,      // state 0 : close,  1..6 : opening, 7: opened ,
        // Points to animate are indexes in scene data of coordinate to change
        52,     
        54,
        -1,  // Direction to animate: 1 or -1
        0,  // Place holder for temporisation
        };    // 32 = 25(point n46)*2 (2 coord/point) + 2 (header nbPoints + nbWall)

// East door
signed  char door_6_3_data[] = {
        0,      // state 0 : close,  1..6 : opening, 7: opened ,
        // Points to animate are indexes in scene data of coordinate to change
        61,     
        63,
        -1,  // Direction to animate: 1 or -1
        0,  // Place holder for temporisation
        };    // 61 = 29(point n46)*2 (2 coord/point) + 2 (header nbPoints + nbWall) + 1 for Y component

void engScene_06(){

        // East door
        engObjType = OBJ_DOOR;
        engObjX     = 24;
        engObjY     = 0;
        engObjData  = door_6_3_data;
        engAddObjectASM();
        objTexture[0] = 0;

        // South door
        engObjType = OBJ_DOOR;
        engObjX     = 0;
        engObjY     = -12;
        engObjData  = door_6_2_data;
        engAddObjectASM();
        objTexture[1] = 0;

        // West door
        engObjType = OBJ_DOOR;
        engObjX     = -24;
        engObjY     = 0;
        engObjData  = door_6_1_data;
        engAddObjectASM();
        objTexture[2] = 0;



}
