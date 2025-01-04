// Inpired by Rax https://github.com/raxrax/oricAsciiTank



// objects
#include "engine.h"

unsigned char   objType     [OBJECTS_MAX];
unsigned char   objActive   [OBJECTS_MAX];
signed char     objPosX     [OBJECTS_MAX];
signed char     objPosY     [OBJECTS_MAX];
char *          objData     [OBJECTS_MAX];
unsigned char * objTexture  [OBJECTS_MAX];


// logarithm distance of object
unsigned char   objLogDistance  [OBJECTS_MAX];
// angle of object relatively to camera position
signed char   objAlpha  [OBJECTS_MAX];
// angle of object relatively to camera axe of view
signed char   objAngle  [OBJECTS_MAX];



// // Height of object on screen
// unsigned char   objHeight  [OBJECTS_MAX];
// // Center column of object on screen
// unsigned char   objColumn  [OBJECTS_MAX];


// static unsigned char engNbObject;
unsigned char engCurrentObjectIdx;

// void itemUpdate();
// char soldier_data [] = {32};
void soldierUpdate();

#ifdef USE_C_COMPUTELOGDIST
// Input : objPosX/Y[engCurrentObjectIdx], rayCamPosX/Y
// Oupt : objAngle, objLogDistance
extern void computeLogDistance ();
#endif

void doorUpdate()
{
}
void engObjectPulse()
{
    switch (objType[engCurrentObjectIdx])
    {
        case OBJ_LAMP:
        case OBJ_PIECE_OF_MEAT:
        case OBJ_DEAD_SOLDIER:
            computeLogDistance();
            dichoInsert (engCurrentObjectIdx, objLogDistance[engCurrentObjectIdx]);
            break;
        case OBJ_DOOR:
            doorUpdate();
            break;
        case OBJ_SOLDIER:
            soldierUpdate();
            break;
    }
}

#ifdef USE_C_ENGINEPULSE
void engPulse() {
    for (engCurrentObjectIdx = 0; engCurrentObjectIdx < OBJECTS_MAX; engCurrentObjectIdx++) {
        if (objActive[engCurrentObjectIdx]) {
            engObjectPulse();
        }
    }

}
#endif // USE_C_ENGINEPULSE

// unsigned char computeRelativeOrientation (signed char direction, signed char rayCamRotZ);

unsigned char computeRelativeOrientation (signed char dirP, signed char dirC) {
    unsigned char res;
    signed char reldiff;
    unsigned char absdiff;

    reldiff  = dirP - dirC + 32;
    absdiff = (unsigned char)(reldiff);

    res = absdiff >> 6;
    return res;
}
// void keyUpdate()
// {
// 	// unsigned char ex = objPosX[engCurrentObjectIdx];
//     // unsigned char ey = objPosY[engCurrentObjectIdx];
//     // printf ("key pulse\n");
//     // ldist = computeLogDist (objPosX[engCurrentObjectIdx], objPosY[engCurrentObjectIdx]);
//     dichoInsert (engCurrentObjectIdx, computeLogDist (objPosX[engCurrentObjectIdx], objPosY[engCurrentObjectIdx]));

//     objTexture[engCurrentObjectIdx] = texture_aKey;
//     // objPosX[engCurrentObjectIdx] = ex;
//     // objPosY[engCurrentObjectIdx] = ey;
// }


void soldierUpdate()
{
    // unsigned char ldist;
    unsigned char displaystate;
    signed char direction;
    // signed char sex, sey;
	signed char ex = objPosX[engCurrentObjectIdx];
    signed char ey = objPosY[engCurrentObjectIdx];
    // sex = ex;
    // sey = ey;
    direction = *(objData[engCurrentObjectIdx]);
    if (ex == 6) { //(ex == 24) 
        if (direction == -128){
            ex --;
        } else {
            direction += 16;
        }
    } else if (ex == -6) {
        if (direction == 0){
            ex ++;
        } else {
            direction += 16;
        }
    } else {
        if (direction == -128){
            ex --;
        } else {
            ex ++;;
        }
    }
    *(objData[engCurrentObjectIdx]) = direction;
    // if (isInWall(ex, ey)) {
    //      direction += 16;
    //      *(objData[engCurrentObjectIdx]) = direction;
    //      ex = sex;
    //      ey = sey;
    // }
    objPosX[engCurrentObjectIdx] = ex;
    objPosY[engCurrentObjectIdx] = ey;

    computeLogDistance();

    dichoInsertVal = objLogDistance[engCurrentObjectIdx];
    dichoInsertIdx = engCurrentObjectIdx;
    dichoASMInsert();

#ifdef USE_SPRITE    
    displaystate = computeRelativeOrientation (direction, rayCamRotZ);
    switch (displaystate) {
        case 0:
            objTexture[engCurrentObjectIdx] = soldier_back; // ptrTextureSoldierBack;
            break;
        case 1:
            objTexture[engCurrentObjectIdx] = soldier_left; // ptrTextureSoldierRight;
            break;
        case 2:
            objTexture[engCurrentObjectIdx] = soldier_front; // ptrTextureSoldierFront;
            break;
        case 3:
            objTexture[engCurrentObjectIdx] = soldier_right; // ptrTextureSoldierLeft;
            break;
    }
#endif
}
#ifdef USE_C_ENGINEPULSE
void engInitObjects()
{
    unsigned char i;
    for (i = 0; i < OBJECTS_MAX; i++) objActive[i] = 0;
}
#endif USE_C_ENGINEPULSE

unsigned char engObjType;
signed char engObjX, engObjY;
signed char *engObjData;

// void engAddObject(char type, signed char x, signed char y, char *data)
// {
//     for (engCurrentObjectIdx = 0; engCurrentObjectIdx < OBJECTS_MAX; engCurrentObjectIdx++)
//     {
//         if (objActive[engCurrentObjectIdx] == 0) break;
//     }
//     if (engCurrentObjectIdx != OBJECTS_MAX) {
//         objActive[engCurrentObjectIdx] = 1;
//         objType[engCurrentObjectIdx] = type;
//         objPosX[engCurrentObjectIdx] = x;
//         objPosY[engCurrentObjectIdx] = y;
//         objData[engCurrentObjectIdx] = data;
//     };

// }

// void engDeleteObject(unsigned char objectNumber) {
//     objActive[objectNumber] = 0;
// }

// void engDeleteAllObjects(unsigned char objectType) {
//     unsigned char i;
//     for (i = 0; i < OBJECTS_MAX; i++)
//         if (1 == objActive[i] && objectType == objType[i])
//             objActive[i] = 0;
// }


// void main () {
//     int ii;
//     printf ("coucou\n");
//     engInitObjects();
//     engAddObject(OBJ_KEY, 3, 3, 0);
//     engAddObject(OBJ_SOLDIER, 3, -3, soldier_data);
//     for (ii=0 ; ii < 4; ii++){
//         engPulse();
//     }
// }