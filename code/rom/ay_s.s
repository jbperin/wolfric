
;; Author: Jean-Baptiste PERIN 

#include "rom/via.h"
#include "rom/score.h"


.zero

_ayReg0      .dsb 1    ; R0  : Chan A Tone Period Fine (LSB)
_ayReg1      .dsb 1    ; R1  : Chan A Tone Period Coarse (HSB)
_ayReg2      .dsb 1    ; R2  : Chan B Tone Period Fine (LSB)
_ayReg3      .dsb 1    ; R3  : Chan B Tone Period Coarse (HSB)
_ayReg4      .dsb 1    ; R4  : Chan C Tone Period Fine (LSB)
_ayReg5      .dsb 1    ; R5  : Chan C Tone Period Coarse (HSB)
_ayReg6      .dsb 1    ; R6  : Noise Period 
_ayReg7      .dsb 1    ; R7  : Mixer 
_ayReg10     .dsb 1    ; R10 : Chan A Amplitude 
_ayReg11     .dsb 1    ; R11 : Chan B Amplitude
_ayReg12     .dsb 1    ; R12 : Chan C Amplitude
_ayReg13     .dsb 1    ; R13 : Envelope Period Fine 
_ayReg14     .dsb 1    ; R14 : Envelope Period Coarse 
_ayReg15     .dsb 1    ; R15 : Envelope Shape / Cycle 

; store precalculated values to write in via PCR for latch sequence
ayLatch_N   .dsb 1
ayLatch_V   .dsb 1
ayUnlatch   .dsb 1

; temporary variable
ayTmp       .dsb 1

#ifdef USE_AY_LIGHT_UPDATE
_ayOldReg0      .dsb 1    ; R0  : Chan A Tone Period Fine (LSB)
_ayOldReg1      .dsb 1    ; R1  : Chan A Tone Period Coarse (HSB)
_ayOldReg2      .dsb 1    ; R2  : Chan B Tone Period Fine (LSB)
_ayOldReg3      .dsb 1    ; R3  : Chan B Tone Period Coarse (HSB)
_ayOldReg4      .dsb 1    ; R4  : Chan C Tone Period Fine (LSB)
_ayOldReg5      .dsb 1    ; R5  : Chan C Tone Period Coarse (HSB)
_ayOldReg6      .dsb 1    ; R6  : Noise Period 
_ayOldReg7      .dsb 1    ; R7  : Mixer 
_ayOldReg10     .dsb 1    ; R10 : Chan A Amplitude 
_ayOldReg11     .dsb 1    ; R11 : Chan B Amplitude
_ayOldReg12     .dsb 1    ; R12 : Chan C Amplitude
_ayOldReg13     .dsb 1    ; R13 : Envelope Period Fine 
_ayOldReg14     .dsb 1    ; R14 : Envelope Period Coarse 
_ayOldReg15     .dsb 1    ; R15 : Envelope Shape / Cycle 
#endif

.text

#define LATCH_REG_NUMBER     sta via_porta:lda ayLatch_N:sta via_pcr:lda ayUnlatch: sta via_pcr
#define LATCH_REG_VALUE      sta via_porta:lda ayLatch_V:sta via_pcr:lda ayUnlatch: sta via_pcr


_ayInit:
    lda #0 
    sta _ayReg0 
    sta _ayReg1 
    sta _ayReg2 
    sta _ayReg3 
    sta _ayReg4 
    sta _ayReg5 
    sta _ayReg6 
    sta _ayReg10 
    sta _ayReg11 
    sta _ayReg12
    sta _ayReg13
    sta _ayReg14
    sta _ayReg15

#ifdef USE_AY_LIGHT_UPDATE
    sta _ayOldReg0
    sta _ayOldReg1
    sta _ayOldReg2
    sta _ayOldReg3
    sta _ayOldReg4
    sta _ayOldReg5
    sta _ayOldReg6
    sta _ayOldReg7
    sta _ayOldReg10
    sta _ayOldReg11
    sta _ayOldReg12
    sta _ayOldReg13
    sta _ayOldReg14
    sta _ayOldReg15
#endif


    lda #$3F    
    sta _ayReg7 


_ayUpdate:
	LDX #<(_ayReg0)	; LL de l'adresse des 14 paramètres
    LDY #>(_ayReg0)	; HH de l'adresse des 14 paramètres
    JSR BlockToAY		
    rts



; parametre A = register number of 8912
; parametre X = donnée à transférer
ayWriteRegister:
.(
    PHP              
    SEI              
    STA via_porta    
    TAY              
    TXA              
    CPY #$07         
    BNE WriteToAY_F59D        
    ORA #$40         
WriteToAY_F59D:
    PHA              
    LDA via_pcr      
    ORA #$EE         
    STA via_pcr      
    AND #$11         
    ORA #$CC         
    STA via_pcr      
    TAX              
    PLA              
    STA via_porta    
    TXA              
    ORA #$EC         
    STA via_pcr      
    AND #$11         
    ORA #$CC         
    STA via_pcr      
    plp
.)              
    rts              


;; Compute amplitude command to store in PSG register based on:
;;  the required volume in register X and consigne in register A
;; INPUTS :
;; Consigne in 4 LSB of register A
;; Volume  in 4 MSB of register X
;; OUTPUT :
;; Command in 4 LSB of register A
;; Destroys registers A and X

compensate:
.(
    stx     ayTmp
    and     ayTmp
    tax
    lda     compensAY,x
.)
    rts

compensAY 	.byt 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	.byt 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1
	.byt 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2
	.byt 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 2, 2, 3, 3, 3
	.byt 0, 0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 3, 3, 4, 4, 4
	.byt 0, 0, 0, 0, 1, 2, 2, 3, 3, 4, 4, 4, 4, 5, 5, 5
	.byt 0, 0, 0, 1, 2, 3, 3, 4, 4, 5, 5, 5, 5, 6, 6, 6
	.byt 0, 0, 1, 2, 3, 4, 4, 5, 5, 6, 6, 6, 6, 7, 7, 7
	.byt 0, 0, 2, 3, 4, 5, 5, 6, 6, 7, 7, 7, 7, 8, 8, 8
	.byt 0, 1, 3, 4, 5, 6, 6, 7, 7, 8, 8, 8, 8, 9, 9, 9
	.byt 0, 2, 4, 5, 6, 7, 7, 8, 8, 9, 9, 9, 9, 10, 10, 10
	.byt 0, 3, 5, 6, 7, 8, 8, 9, 9, 10, 10, 10, 10, 11, 11, 11
	.byt 0, 4, 6, 7, 8, 9, 9, 10, 10, 11, 11, 11, 11, 12, 12, 12
	.byt 0, 5, 7, 8, 9, 10, 10, 11, 11, 12, 12, 12, 12, 13, 13, 13
	.byt 0, 6, 8, 9, 10, 11, 11, 12, 12, 13, 13, 13, 13, 14, 14, 14
	.byt 0, 7, 9, 10, 11, 12, 12, 13, 13, 14, 14, 14, 14, 15, 15, 15

