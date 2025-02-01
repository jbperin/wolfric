
; signed char deltaX, deltaY;
_DeltaX .dsb 1
_DeltaY .dsb 1


; signed char theta, alpha ;
_theta .dsb 1
; _alpha .dsb 1

; unsigned char log_distance;
_log_distance .dsb 1

; signed char PtX;
; signed char PtY;
_PointX .dsb 1
_PointY .dsb 1


; signed char OriginX;
; signed char OriginY;
_OriginX .dsb 1
_OriginY .dsb 1

absDeltaX .dsb 1
absDeltaY .dsb 1

_lgdistance:
.(
    pha:txa:pha:tya:pha 


    ; DeltaX = PtX - glCamPosX ;
	sec
	lda _PointX
	sbc _OriginX
	sta _DeltaX
    sta _tx

    ; DeltaY = PtY - glCamPosY ;
	sec
	lda _PointY
	sbc _OriginY
	sta _DeltaY
    sta _ty

    ; theta = ATAN2 (DeltaY, DeltaX);
	jsr _atan2_8
	lda _res
	sta _theta

    lda _DeltaX
    bmi deltaX_negativ
    jmp absDeltaX_done
deltaX_negativ
    eor #$ff: sec: adc #$00
absDeltaX_done
    sta absDeltaX

    lda _DeltaY
    bmi deltaY_negativ
    jmp absDeltaY_done
deltaY_negativ
    eor #$ff: sec: adc #$00
absDeltaY_done
    sta absDeltaY

    lda absDeltaX
    cmp absDeltaY
    bcc absDeltaX_less_than_absDeltaY
    ; IF abs(DeltaX) > abs(DeltaY)
        ; log_distance = log2_tab[abs(DeltaX)] + tab_1overcos[(unsigned char)theta];
        ldy absDeltaX
        lda _log2_tab, y
        ldy _theta
        clc
        adc _tab_1overcos, y
        sta _log_distance

    jmp end_if_absDeltaX_less_than_absDeltaY
absDeltaX_less_than_absDeltaY    
    ; ELIF abs(DeltaX) < abs(DeltaY)
        ; log_distance = log2_tab[abs(DeltaY)] + tab_1oversin[(unsigned char)theta];
        ldy absDeltaY
        lda _log2_tab, y
        ldy _theta
        clc
        adc _tab_1oversin, y
        sta _log_distance
end_if_absDeltaX_less_than_absDeltaY


lgdistance_done
    pla:tay:pla:tax:pla
.)
    rts
