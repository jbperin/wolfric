#include "raycast/config.h"

#ifndef USE_C_ENGINEPULSE

_engPulse
.(
    ldy #OBJECTS_MAX: sty _engCurrentObjectIdx
engPulseLoop
        ldy _engCurrentObjectIdx
        beq engPulseEndLoop
        dey : sty _engCurrentObjectIdx
        lda _objActive, y
        beq EndIfObjectIsActive
            ldy #0: jsr _engObjectPulse
EndIfObjectIsActive
        jmp engPulseLoop
engPulseEndLoop
.)
    rts


_engInitObjects
.(
    ldy #OBJECTS_MAX: sty _engCurrentObjectIdx
engInitLoop
        ldy _engCurrentObjectIdx
        beq engInitEndLoop
        dey : sty _engCurrentObjectIdx
        lda #0
        sta _objActive, y
        jmp engInitLoop
engInitEndLoop
.)
    rts

_engAddObjectASM
.(
    ; for (engCurrentObjectIdx = 0; engCurrentObjectIdx < OBJECTS_MAX; engCurrentObjectIdx++)
    ; {
    ;     if (objActive[engCurrentObjectIdx] == 0) break;
    ; }
    lda #0
    sta _engCurrentObjectIdx
loop_object:
    cmp #OBJECTS_MAX
    beq endloop_object

    tay 
    lda _objActive,y 
    beq endloop_object

    inc _engCurrentObjectIdx
    lda _engCurrentObjectIdx
    jmp loop_object
endloop_object:

    ; if (engCurrentObjectIdx != OBJECTS_MAX) {
    lda _engCurrentObjectIdx
    cmp #OBJECTS_MAX
    beq endif01
    ;     objActive[engCurrentObjectIdx] = 1;
        ldy _engCurrentObjectIdx
        lda #1
        sta _objActive, y
    ;     objType[engCurrentObjectIdx] = engObjType;
        lda _engObjType
        sta _objType, y
    ;     objPosX[engCurrentObjectIdx] = engObjX;
        lda _engObjX
        sta _objPosX, y
    ;     objPosY[engCurrentObjectIdx] = engObjY;
        lda _engObjY
        sta _objPosY, y
    ;     objData[engCurrentObjectIdx] = engObjData;
        tya
        asl
        tay
        lda _engObjData
        sta _objData,y
        iny
        lda _engObjData+1
        sta _objData,y
    ; };
endif01    
engAddObjectDone
.)
    rts
#endif ;; USE_C_ENGINEPULSE

