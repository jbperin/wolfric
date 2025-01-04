#ifndef ENGINE_H
#define ENGINE_H

// objects
#define OBJ_KEY         1
#define OBJ_TREE        2
#define OBJ_SOLDIER     3
// #define OBJ_LETTER      4
// #define OBJ_DOOR        5
// #define OBJ_CREATURE    6
// #define OBJ_ARBALETE    7
// #define OBJ_FIRE        8
extern unsigned char * objTexture  [];
extern unsigned char   objType     [];
extern unsigned char   objActive   [];
extern signed char     objPosX     [];
extern signed char     objPosY     [];
extern char *          objData     [];

extern unsigned char engCurrentObjectIdx;
extern unsigned char engObjType;
extern signed char engObjX, engObjY;
extern signed char *engObjData;

#endif