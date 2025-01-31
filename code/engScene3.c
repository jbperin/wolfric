
// South door
signed  char door_1_0_data[] = {
        0,      // state 0 : close,  1..6 : opening, 7: opened ,
        // Points to animate are indexes in scene data of coordinate to change
        60,     
        62,
        1,  // Direction to animate: 1 or -1
        0,  // Place holder for temporisation
        };    // 60 = 29(point n12)*2 (2 coord/point) + 2 (header nbPoints + nbWall)

// North door
signed  char door_1_1_data[] = {
        0,      // state 0 : close,  1..6 : opening, 7: opened ,
        // Points to animate are indexes in scene data of coordinate to change
        68,     
        70,
        1,  // Direction to animate: 1 or -1
        0,  // Place holder for temporisation
        };    // 68 = 33(point n42)*2 (2 coord/point) + 2 (header nbPoints + nbWall)

// East door
signed  char door_1_2_data[] = {
        0,      // state 0 : close,  1..6 : opening, 7: opened ,
        // Points to animate are indexes in scene data of coordinate to change
        77,     
        79,
        -1,  // Direction to animate: 1 or -1
        0,  // Place holder for temporisation
        };    // 77= 37(point n46)*2 (2 coord/point) + 2 (header nbPoints + nbWall) + 1 to aniamte Y coordinate


void engScene_03(){

        engObjType = OBJ_DOOR;
        engObjX     = 0;
        engObjY     = -18;
        engObjData  = door_1_0_data;
        engAddObjectASM();
        objTexture[0] = 0;

        engObjType = OBJ_DOOR;
        engObjX     = 0;
        engObjY     = 18;
        engObjData  = door_1_1_data;
        engAddObjectASM();
        objTexture[1] = 0;

        engObjType = OBJ_DOOR;
        engObjX     = 30;
        engObjY     = 0;
        engObjData  = door_1_2_data;
        engAddObjectASM();
        objTexture[2] = 0;

        engObjType = OBJ_PLANT;
        engObjX     = -24;
        engObjY     = 6;
        engObjData  = 0;
        engAddObjectASM();
        objTexture[3] = plant_1;

        engObjType = OBJ_PLANT;
        engObjX     = -24;
        engObjY     = -6;
        engObjData  = 0;
        engAddObjectASM();
        objTexture[4] = plant_1;

        engObjType = OBJ_PLANT;
        engObjX     = -12;
        engObjY     = 6;
        engObjData  = 0;
        engAddObjectASM();
        objTexture[5] = plant_1;

        engObjType = OBJ_PLANT;
        engObjX     = 12;
        engObjY     = 6;
        engObjData  = 0;
        engAddObjectASM();
        objTexture[6] = plant_1;

        engObjType = OBJ_LUSTRE;
        engObjX     = -18;
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
        engObjX     = 18;
        engObjY     = 0;
        engObjData  = 0;
        engAddObjectASM();
        objTexture[9] = lustre;
}