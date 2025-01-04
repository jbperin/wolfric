    .bss
; textures
* = $C000
_texture_wall:
_texture_bluewall:
_texture_metalwall:
_texture_gridwall:
_texture_bigbricks .dsb 1024
_texture_door:
_texture_smily_front .dsb 1024
_texture_01:
_texture_smily_back .dsb 1024
_texture_02:
_texture_smily_left .dsb 1024
_texture_03:
_texture_smily_right .dsb 1024
_texture_04:
_texture_tree .dsb 1024

_texture_05:
_texture_fire_frame_0 .dsb 1024
_texture_06:
_texture_fire_frame_1 .dsb 1024
_texture_07:
_texture_fire_frame_2 .dsb 1024
_texture_08:
_texture_fire_frame_3 .dsb 1024


; raytables.bin 4437 octets
; TODO . should be * = $ED95
* = $EC00

_multi120_low           .dsb 64 
_multi120_high          .dsb 64
_multi32_high           .dsb 32
_multi32_low            .dsb 32
_multiCoeff         .dsb 45
_atan_tab           .dsb 256
_octant_adjust          .dsb 8
_tab_exp            .dsb 256
_tab_exp_extended           .dsb 33
_tab_exp_extended2          .dsb 18
_tab_exp_extended3          .dsb 13
_log2_tab           .dsb 256

; coltexture
_tabRightRed            .dsb 64
_tabLeftRed         .dsb 64
_tabRightGreen          .dsb 64
_tabLeftGreen           .dsb 64
_tabRightBlue           .dsb 64
_tabLeftBlue            .dsb 64
_tabIdxRdTexture            .dsb 2016

_tab3Sin            .dsb 64
_tab3Cos            .dsb 256
_tabLog2Sin         .dsb 64
_tabLog2Cos         .dsb 256
_tab_1oversin           .dsb 64
_tab_1overcos           .dsb 256

; *= $FFEA