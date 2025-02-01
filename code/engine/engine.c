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
void doorUpdate();

#ifdef USE_C_COMPUTELOGDIST
// Input : objPosX/Y[engCurrentObjectIdx], rayCamPosX/Y
// Oupt : objAngle, objLogDistance
extern void computeLogDistance ();
#endif

extern unsigned char openDoorRequest;
extern unsigned char sceneUpdateRequest;
extern unsigned char shootRequest;
extern unsigned char score;
extern unsigned char ammo;
extern unsigned char health;
extern signed char  *ptrCurrentScene;

unsigned char logDist;

void engObjectPulse()
{
    switch (objType[engCurrentObjectIdx])
    {
        case OBJ_PLANT:
        case OBJ_LUSTRE:
        case OBJ_LAMP:
        case OBJ_DEAD_SOLDIER:
            computeLogDistance();
            // dichoInsert (engCurrentObjectIdx, objLogDistance[engCurrentObjectIdx]);
            // #TODO: Why can't we call ASM directly
            dichoInsertVal = (unsigned char)objLogDistance[engCurrentObjectIdx];
            if (dichoInsertVal > 10) {
                dichoInsertIdx = engCurrentObjectIdx;
                dichoASMInsert();
            }
            break;
        case OBJ_PIECE_OF_MEAT:
        case OBJ_AMMO:
            logDist = logdist (rayCamPosX, rayCamPosY, objPosX[engCurrentObjectIdx], objPosY[engCurrentObjectIdx]);

            computeLogDistance();
            // if ((unsigned char)(objLogDistance[engCurrentObjectIdx]) < 19){
            if (logDist < 19){
                if ((objType[engCurrentObjectIdx]==OBJ_AMMO) && (ammo <= 96)) {
                    ammo += 4;
                    objActive[engCurrentObjectIdx] = 0;
                    PING();
                }else if ((objType[engCurrentObjectIdx]==OBJ_PIECE_OF_MEAT) && (health <= 146)) {
                    // {asm(":breakhere:");}
                    health += 4;
                    objActive[engCurrentObjectIdx] = 0;
                    PING();
                }
            } else {
                // dichoInsert (engCurrentObjectIdx, objLogDistance[engCurrentObjectIdx]);
                // #TODO: Why can't we call ASM directly
                dichoInsertVal = (unsigned char)objLogDistance[engCurrentObjectIdx];
                dichoInsertIdx = engCurrentObjectIdx;
                dichoASMInsert();

            }
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

char *soldierData;
extern unsigned char sprite_deadsoldier[];
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
    soldierData        = objData[engCurrentObjectIdx];
    computeLogDistance();

    if (soldierData[0]==0) {
        objPosX[engCurrentObjectIdx] = soldierData[3];
        objPosY[engCurrentObjectIdx] = soldierData[4];
        objTexture[engCurrentObjectIdx] = sprite_deadsoldier;
    } else {
        if ((shootRequest == 1) && (abs (objAngle[engCurrentObjectIdx]) < 16)) { // && (abs (objAngle[engCurrentObjectIdx]) < 16)
            // health
            soldierData[2] -= 1;
            if (soldierData[2] == 0){
                // state = dead
                soldierData[0]=0;
                // remember death position
                soldierData[3]=ex;
                soldierData[4]=ey;
                objTexture[engCurrentObjectIdx] = sprite_deadsoldier;
                score += 2;
            } else {
                objTexture[engCurrentObjectIdx] = texture_hurt_soldier;
            }
        } else {
            direction = (signed char )(soldierData[1]);
            if (ex == soldierData[6]) { //(ex == 24) 
                if (direction == -128){
                    ex --;
                } else {
                    direction += 16;
                }
            } else if (ex == soldierData[5]) {
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
            soldierData[1] = direction;
            // if (isInWall(ex, ey)) {
            //      direction += 16;
            //      *(objData[engCurrentObjectIdx]) = direction;
            //      ex = sex;
            //      ey = sey;
            // }
            objPosX[engCurrentObjectIdx] = ex;
            objPosY[engCurrentObjectIdx] = ey;
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
        }
    }
    dichoInsertVal = (unsigned char)objLogDistance[engCurrentObjectIdx];
    dichoInsertIdx = engCurrentObjectIdx;
    dichoASMInsert();

}


char *doorData;
unsigned char doorState; // *(objData[engCurrentObjectIdx]);
unsigned char doorPt1;
unsigned char doorPt2;
signed char doorIncrem;

void doorUpdate()
{
    doorData        = objData[engCurrentObjectIdx];
    doorState       = (unsigned char)(doorData[0]); // *(objData[engCurrentObjectIdx]);
    doorPt1         = (unsigned char)(doorData[1]);
    doorPt2         = (unsigned char)(doorData[2]);
    doorIncrem      = doorData[3];
    // computeLogDistance();
    logDist = logdist (rayCamPosX, rayCamPosY, objPosX[engCurrentObjectIdx], objPosY[engCurrentObjectIdx]);
    if ((doorState == 0) && (openDoorRequest == 1) && (logDist <= 80 )){ 
        openDoorRequest     = 0;
        doorState           = 1;
        ZAP();
    }
    if (doorState != 0 && doorState < 7) {
        doorState ++;
        ptrCurrentScene[doorPt1] += doorIncrem;
        ptrCurrentScene[doorPt2] += doorIncrem;
        // *(objData[engCurrentObjectIdx])=state;
        doorData[0] = doorState;
        sceneUpdateRequest = 1;
        // initScene (scene_00, texture_00);
    } else if (doorState == 7) {
        // objActive[engCurrentObjectIdx]=0;
        doorData[4]=6;
        doorData[0]=8;
    } else if (doorState == 8) {
        // TODO: check if player not in
        doorData[4] -= 1;
        if (doorData[4] == 0){
            doorData[0]=9;
        }
    } else if (doorState >= 9 && doorState < 15) {
        doorData[0] +=1;
        ptrCurrentScene[doorPt1] -= doorIncrem;
        ptrCurrentScene[doorPt2] -= doorIncrem;
        sceneUpdateRequest = 1;
        // initScene (scene_00, texture_00);
    } else if (doorState == 15) {
        doorData[0] = 0;
    }
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