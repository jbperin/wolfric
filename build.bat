
python tools\tile.py  assets\sprites02.png 7 8 -skipgrid 1
COPY assets\sprites02_tiles\tile_5_4.png assets\textures\sprite_deadsoldier.png
python .\tools\texture2buf.py assets\textures\sprite_deadsoldier.png --name deadsoldier > .\prod\RomlessDataDump\code\textures\deadsoldier.h


python .\tools\texture2buf.py assets\textures\sprit.png --name soldier > .\prod\RomlessDataDump\code\textures\soldier.h

COPY assets\sprites02_tiles\tile_1_0.png assets\textures\sprite_soldier_front.png
COPY assets\sprites02_tiles\tile_1_4.png assets\textures\sprite_soldier_back.png
COPY assets\sprites02_tiles\tile_1_2.png assets\textures\sprite_soldier_left.png
COPY assets\sprites02_tiles\tile_1_6.png assets\textures\sprite_soldier_right.png
python .\tools\texture2buf.py assets\textures\sprite_soldier_front.png --name soldier_front > .\prod\RomlessDataDump\code\textures\soldier_front.h
python .\tools\texture2buf.py assets\textures\sprite_soldier_back.png --name soldier_back > .\prod\RomlessDataDump\code\textures\soldier_back.h
python .\tools\texture2buf.py assets\textures\sprite_soldier_left.png --name soldier_left > .\prod\RomlessDataDump\code\textures\soldier_left.h
python .\tools\texture2buf.py assets\textures\sprite_soldier_right.png --name soldier_right > .\prod\RomlessDataDump\code\textures\soldier_right.h

python tools\tile.py  assets\sprites01.png 13 5 -skipgrid 1

COPY assets\sprites01_tiles\tile_5_1.png assets\textures\sprite_pieceofmeat.png
python .\tools\texture2buf.py assets\textures\sprite_pieceofmeat.png --name pieceofmeat > .\prod\RomlessDataDump\code\textures\pieceofmeat.h



python tools\tile.py  assets\spritesNtextures.png 33 8 -skipgrid 1
COPY /Y assets\spritesNtextures_tiles\tile_2_0.png assets\textures\texture_bluewall.png
COPY /Y assets\spritesNtextures_tiles\tile_2_2.png assets\textures\texture_gridwall.png
COPY /Y assets\spritesNtextures_tiles\tile_8_0.png assets\textures\texture_door_1.png
COPY /Y assets\spritesNtextures_tiles\tile_9_0.png assets\textures\texture_metalwall.png
COPY /Y assets\spritesNtextures_tiles\tile_14_3.png assets\textures\sprite_ammo_1.png
python .\tools\texture2buf.py assets\textures\texture_bluewall.png --name texture_bluewall > .\prod\RomlessDataDump\code\textures\bluewall.h
python .\tools\texture2buf.py assets\textures\texture_gridwall.png --name texture_gridwall > .\prod\RomlessDataDump\code\textures\gridwall.h
python .\tools\texture2buf.py assets\textures\texture_door_1.png --name door_1 > .\prod\RomlessDataDump\code\textures\door_1.h
python .\tools\texture2buf.py assets\textures\texture_metalwall.png --name metalwall > .\prod\RomlessDataDump\code\textures\metalwall.h
python .\tools\texture2buf.py assets\textures\sprite_ammo_1.png --replace_color 0 0 0 12 --name ammo_1 > .\prod\RomlessDataDump\code\textures\ammo_1.h

python tools\tile.py  assets\Objects_01.png 1 4 -skipgrid 1
COPY assets\Objects_01_tiles\tile_0_3.png assets\textures\sprite_lamp_1.png
python .\tools\texture2buf.py assets\textures\sprite_lamp_1.png --name lamp_1 > .\prod\RomlessDataDump\code\textures\lamp_1.h
REM python .\tools\texture2buf.py assets\sprites01_tiles\tile_4_1.png --name skullheap > .\prod\RomlessDataDump\code\textures\skullheap.h
REM python .\tools\texture2buf.py assets\sprites01_tiles\tile_7_1.png --name skeleton > .\prod\RomlessDataDump\code\textures\skeleton.h

python tools\tile.py  assets\BasicGun.png 1 5 -skipgrid 1
COPY /Y assets\BasicGun_tiles\tile_0_0.png prod\castoric\img\basic_gun_1.png
pushd prod\castoric
python tools\img2forgrnd.py img\basic_gun_1.png > proto\c\fg_gun.h
popd 
COPY /Y prod\castoric\proto\c\fg_gun.h  code\raycast\
@REM python .\tools\texture2buf.py assets\BasicGun_tiles\tile_0_0.png --name basicgun > .\prod\RomlessDataDump\code\textures\basicgun.h

python tools\tile.py  assets\BasicKnife.png 1 5 -skipgrid 1
python .\tools\texture2buf.py assets\BasicKnife_tiles\tile_0_0.png --name basicknife > .\prod\RomlessDataDump\code\textures\basicknife.h



REM COPY /Y prod\castoric\proto\c\ code\raycast\
REM COPY /Y prod\castoric\proto\c\ code\raycast\


COPY /Y prod\castoric\proto\c\collision.c  code\raycast\
COPY /Y prod\castoric\proto\c\collision_s.s  code\raycast\
REM COPY /Y prod\castoric\proto\c\config.h  code\raycast\
COPY /Y prod\castoric\proto\c\dda_s.s  code\raycast\
COPY /Y prod\castoric\proto\c\dichobuf.c  code\raycast\
COPY /Y prod\castoric\proto\c\dichobuf_s.s  code\raycast\
COPY /Y prod\castoric\proto\c\dist.c  code\raycast\
COPY /Y prod\castoric\proto\c\dist_s.s  code\raycast\
COPY /Y prod\castoric\proto\c\drawWalls_s.s  code\raycast\

COPY /Y prod\castoric\proto\c\engine.h  code\engine\
COPY /Y prod\castoric\proto\c\engine.c  code\engine\
COPY /Y prod\castoric\proto\c\engine_s.s  code\engine\

COPY /Y prod\castoric\proto\c\scene.c  code\scene\

COPY /Y prod\castoric\proto\c\textures\texture_bigbricks.h  code\scene\textures

COPY /Y prod\castoric\proto\c\fg_gun.h  code\raycast\


COPY /Y prod\castoric\proto\c\iea2d.c  code\raycast\
COPY /Y prod\castoric\proto\c\math.c  code\raycast\
COPY /Y prod\castoric\proto\c\raycast.c  code\raycast\
@REM COPY /Y prod\castoric\proto\c\raycast.h  code\raycast\
COPY /Y prod\castoric\proto\c\raycast_s.s  code\raycast\
COPY /Y prod\castoric\proto\c\foreground_s.s  code\raycast\
COPY /Y prod\castoric\proto\c\sprite.c  code\raycast\
COPY /Y prod\castoric\proto\c\sprite_s.s  code\raycast\
@REM COPY /Y prod\castoric\proto\c\tab3trigo.s  code\raycast\
COPY /Y prod\castoric\proto\c\raycast\tabAdrTabIdxRd.h  code\raycast\
@REM COPY /Y prod\castoric\proto\c\tabIdxRdTexture.h  code\raycast\

@REM BINARY  COPY /Y prod\castoric\proto\c\tabMulti.h  code\raycast\
@REM BINARY  COPY /Y prod\castoric\proto\c\tabTexelColor.h  code\raycast\

@REM COPY /Y prod\castoric\proto\c\tablogtrigo.h  code\raycast\
@REM COPY /Y prod\castoric\proto\c\tablogtrigo_s.s  code\raycast\
COPY /Y prod\castoric\proto\c\tabrayangle.h  code\raycast\
COPY /Y prod\castoric\proto\c\tabunfish.h  code\raycast\
COPY /Y prod\castoric\proto\c\tabunlogd2hh.h  code\raycast\
COPY /Y prod\castoric\proto\c\texel.c  code\raycast\
COPY /Y prod\castoric\proto\c\texel_s.s  code\raycast\
COPY /Y prod\castoric\proto\c\vertcolbuf.c  code\raycast\
COPY /Y prod\castoric\proto\c\vertcolbuf_s.s  code\raycast\
COPY /Y prod\castoric\proto\c\viewport.c  code\raycast\
@REM COPY /Y prod\castoric\proto\c\viewport_s.s  code\raycast\



@REM python tools\tile.py  assets\Textures-16.png 32 32
@REM python .\tools\texture2buf.py assets\Textures-16_tiles\tile_2_3.png --name roundstonewall_1 > .\code\scene\textures\roundstonewall_1.h
@REM python .\tools\texture2buf.py assets\Textures-16_tiles\tile_3_8.png --name bigredbrick_1 > .\code\scene\textures\bigredbrick_1.h

@REM python tools\tile.py  assets\SeamlessTextures1616.png 12 16
@REM python .\tools\texture2buf.py assets\SeamlessTextures1616_tiles\tile_3_13.png --name metalwall_1 > .\code\scene\textures\metalwall_1.h
@REM python .\tools\texture2buf.py assets\SeamlessTextures1616_tiles\tile_3_15.png --name metalwall_2 > .\code\scene\textures\metalwall_2.h

@REM python .\tools\texture2buf.py assets\trees\mangrove_1.png --replace_color 0 0 0 12 > .\code\scene\textures\mangrove_1.h
@REM python .\tools\texture2buf.py assets\trees\mangrove_2.png --replace_color 0 0 0 12 > .\code\scene\textures\mangrove_2.h
@REM python .\tools\texture2buf.py assets\trees\mangrove_3.png --replace_color 0 0 0 12 > .\code\scene\textures\mangrove_3.h
@REM python .\tools\texture2buf.py assets\trees\tree_1_lightred.png --replace_color 0 0 0 12 > .\code\scene\textures\tree_1_lightred.h
@REM python .\tools\texture2buf.py assets\trees\tree_1_red.png --replace_color 0 0 0 12 > .\code\scene\textures\tree_1_red.h
@REM python .\tools\texture2buf.py assets\trees\tree_1_yellow.png --replace_color 0 0 0 12 > .\code\scene\textures\tree_1_yellow.h
@REM python .\tools\texture2buf.py assets\trees\tree_2_lightred.png --replace_color 0 0 0 12 > .\code\scene\textures\tree_2_lightred.h
@REM python .\tools\texture2buf.py assets\trees\tree_2_red.png --replace_color 0 0 0 12 > .\code\scene\textures\tree_2_red.h
@REM python .\tools\texture2buf.py assets\trees\tree_2_yellow.png --replace_color 0 0 0 12 > .\code\scene\textures\tree_2_yellow.h


@REM python .\tools\texture2buf.py assets\TransparentIcons_tiles\tile_6_4.png --name arbalete> .\code\scene\textures\arbalete.h
@REM python .\tools\texture2buf.py assets\TransparentIcons_tiles\tile_11_10.png --name keys > .\code\scene\textures\keys.h
@REM python .\tools\texture2buf.py assets\TransparentIcons_tiles\tile_11_11.png --name chest > .\code\scene\textures\chest.h
@REM python .\tools\texture2buf.py assets\TransparentIcons_tiles\tile_13_9.png --name letter > .\code\scene\textures\letter.h
@REM python .\tools\texture2buf.py assets\TransparentIcons_tiles\tile_13_10.png --name parchment_close > .\code\scene\textures\parchment_close.h
@REM python .\tools\texture2buf.py assets\TransparentIcons_tiles\tile_13_11.png --name parchment_open > .\code\scene\textures\parchment_open.h
@REM python .\tools\texture2buf.py assets\TransparentIcons_tiles\tile_13_12.png --name map > .\code\scene\textures\map.h

@REM python tools\tile.py  assets\ProjectUtumno_full.png 95 64 
@REM python .\tools\texture2buf.py assets\ProjectUtumno_full_tiles\tile_0_3.png  --name fountain > .\code\scene\textures\fountain.h
@REM python .\tools\texture2buf.py assets\ProjectUtumno_full_tiles\tile_0_45.png  --name headheap > .\code\scene\textures\headheap.h
@REM python .\tools\texture2buf.py assets\ProjectUtumno_full_tiles\tile_1_52.png  --name gate > .\code\scene\textures\gate.h
@REM python .\tools\texture2buf.py assets\ProjectUtumno_full_tiles\tile_49_23.png  --name arbalete_2 > .\code\scene\textures\arbalete_2.h
@REM python .\tools\texture2buf.py assets\ProjectUtumno_full_tiles\tile_60_15.png  --name strong_man > .\code\scene\textures\strong_man.h
@REM python .\tools\texture2buf.py assets\ProjectUtumno_full_tiles\tile_60_3.png  --name dragon_1 > .\code\scene\textures\dragon_1.h
@REM python .\tools\texture2buf.py assets\ProjectUtumno_full_tiles\tile_61_3.png  --name siren > .\code\scene\textures\siren.h
@REM python .\tools\texture2buf.py assets\ProjectUtumno_full_tiles\tile_67_48.png  --name eye > .\code\scene\textures\eye.h
@REM python .\tools\texture2buf.py assets\ProjectUtumno_full_tiles\tile_67_55.png  --name eye_2 > .\code\scene\textures\eye_2.h
@REM python .\tools\texture2buf.py assets\ProjectUtumno_full_tiles\tile_60_50.png  --name merlin > .\code\scene\textures\merlin.h
@REM python .\tools\texture2buf.py assets\ProjectUtumno_full_tiles\tile_94_10.png  --name dragon_2 > .\code\scene\textures\dragon_2.h
@REM python .\tools\texture2buf.py assets\ProjectUtumno_full_tiles\tile_40_55.png  --name key_1 > .\code\scene\textures\key_1.h
@REM python .\tools\texture2buf.py assets\ProjectUtumno_full_tiles\tile_40_56.png  --name lamp > .\code\scene\textures\lamp.h
@REM python .\tools\texture2buf.py assets\ProjectUtumno_full_tiles\tile_41_57.png  --name potion > .\code\scene\textures\potion.h
@REM python .\tools\texture2buf.py assets\ProjectUtumno_full_tiles\tile_13_13.png  --name tree_1 > .\code\scene\textures\tree_1.h
@REM python .\tools\texture2buf.py assets\ProjectUtumno_full_tiles\tile_13_14.png  --name tree_2 > .\code\scene\textures\tree_2.h
@REM python .\tools\texture2buf.py assets\ProjectUtumno_full_tiles\tile_13_15.png  --name tree_3 > .\code\scene\textures\tree_3.h
@REM python .\tools\texture2buf.py assets\ProjectUtumno_full_tiles\tile_13_16.png  --name tree_4 > .\code\scene\textures\tree_4.h
@REM python .\tools\texture2buf.py assets\ProjectUtumno_full_tiles\tile_12_32.png  --name statue_1 > .\code\scene\textures\statue_1.h
@REM python .\tools\texture2buf.py assets\ProjectUtumno_full_tiles\tile_12_33.png  --name statue_2 > .\code\scene\textures\statue_2.h
@REM python .\tools\texture2buf.py assets\ProjectUtumno_full_tiles\tile_12_19.png  --name statue_3 > .\code\scene\textures\statue_3.h
@REM python .\tools\texture2buf.py assets\ProjectUtumno_full_tiles\tile_19_44.png  --name gate_2 > .\code\scene\textures\gate_2.h

@REM python tools\tile.py  assets\Fighter-F-01.png 4 7 --replace_color 0 117 117 6
@REM python .\tools\texture2buf.py assets\Fighter-F-01_tiles\tile_0_0.png --cfill 152 0 136 --name fighter_back > .\code\scene\textures\fighter_back.h
@REM python .\tools\texture2buf.py assets\Fighter-F-01_tiles\tile_1_0.png --cfill 152 0 136 --name fighter_right > .\code\scene\textures\fighter_right.h
@REM python .\tools\texture2buf.py assets\Fighter-F-01_tiles\tile_2_0.png --cfill 152 0 136 --name fighter_front > .\code\scene\textures\fighter_front.h
@REM python .\tools\texture2buf.py assets\Fighter-F-01_tiles\tile_3_0.png --cfill 152 0 136 --name fighter_left > .\code\scene\textures\fighter_left.h
@REM python tools\tile.py  assets\Princess-01.png 4 7 --replace_color 0 117 117 6
@REM python .\tools\texture2buf.py assets\Princess-01_tiles\tile_0_0.png --cfill 152 0 136 --name princess_back > .\code\scene\textures\princess_back.h
@REM python .\tools\texture2buf.py assets\Princess-01_tiles\tile_1_0.png --cfill 152 0 136 --name princess_right > .\code\scene\textures\princess_right.h
@REM python .\tools\texture2buf.py assets\Princess-01_tiles\tile_2_0.png --cfill 152 0 136 --name princess_front > .\code\scene\textures\princess_front.h
@REM python .\tools\texture2buf.py assets\Princess-01_tiles\tile_3_0.png --cfill 152 0 136 --name princess_left > .\code\scene\textures\princess_left.h
@REM python tools\tile.py  assets\cat.png 8 16 
@REM python .\tools\texture2buf.py assets\cat_tiles\tile_0_0.png --name cat_right > .\code\scene\textures\cat_right.h
@REM python .\tools\texture2buf.py assets\cat_tiles\tile_1_0.png --name cat_back > .\code\scene\textures\cat_back.h
@REM python .\tools\texture2buf.py assets\cat_tiles\tile_2_0.png --name cat_front > .\code\scene\textures\cat_front.h
@REM python .\tools\texture2buf.py assets\cat_tiles\tile_3_0.png --name cat_left > .\code\scene\textures\cat_left.h
@REM python tools\tile.py  assets\dog.png 8 16 
@REM python .\tools\texture2buf.py assets\dog_tiles\tile_0_0.png  --name dog_right > .\code\scene\textures\dog_right.h
@REM python .\tools\texture2buf.py assets\dog_tiles\tile_1_0.png  --name dog_back > .\code\scene\textures\dog_back.h
@REM python .\tools\texture2buf.py assets\dog_tiles\tile_2_0.png  --name dog_front > .\code\scene\textures\dog_front.h
@REM python .\tools\texture2buf.py assets\dog_tiles\tile_3_0.png  --name dog_left > .\code\scene\textures\dog_left.h
@REM python tools\tile.py  assets\lpc_minotaur.png 8 16 
@REM python .\tools\texture2buf.py assets\lpc_minotaur_tiles\tile_0_0.png  --name lpc_minotaur_back > .\code\scene\textures\lpc_minotaur_back.h
@REM python .\tools\texture2buf.py assets\lpc_minotaur_tiles\tile_1_0.png  --name lpc_minotaur_left > .\code\scene\textures\lpc_minotaur_left.h
@REM python .\tools\texture2buf.py assets\lpc_minotaur_tiles\tile_2_0.png  --name lpc_minotaur_front > .\code\scene\textures\lpc_minotaur_front.h
@REM python .\tools\texture2buf.py assets\lpc_minotaur_tiles\tile_3_0.png  --name lpc_minotaur_right > .\code\scene\textures\lpc_minotaur_right.h
@REM python tools\tile.py  assets\bull.png 8 4
@REM python .\tools\texture2buf.py assets\bull_tiles\tile_0_0.png  --name bull_back > .\code\scene\textures\bull_back.h
@REM python .\tools\texture2buf.py assets\bull_tiles\tile_1_0.png  --name bull_left > .\code\scene\textures\bull_left.h
@REM python .\tools\texture2buf.py assets\bull_tiles\tile_2_0.png  --name bull_front > .\code\scene\textures\bull_front.h
@REM python .\tools\texture2buf.py assets\bull_tiles\tile_3_0.png  --name bull_right > .\code\scene\textures\bull_right.h


@REM python tools\tile.py  assets\0xWR6B.gif 4 5 --replace_color 0 0 0 6 
@REM python tools\gif2buf.py  assets\0xWR6B_tiles\tile_1_0.gif assets\0xWR6B --name explosion --flist 0 1 2 4 > .\code\scene\textures\explosion.h
@REM python tools\gif2buf.py  assets\0xWR6B_tiles\tile_1_1.gif assets\0xWR6B --name explosion_02 --flist 0 1 2 4 > .\code\scene\textures\explosion_02.h


@REM python tools\tile.py  assets\E9LzHe.gif 5 4 --replace_color 0 0 0 24
@REM python tools\gif2buf.py  assets\E9LzHe_tiles\tile_2_2.gif assets\E9LzHe --name explosion_03 --fnum 4 > .\code\scene\textures\explosion_03.h
@REM python tools\gif2buf.py  assets\E9LzHe_tiles\tile_2_3.gif assets\E9LzHe --name explosion_04 --flist 0 2 3 5 > .\code\scene\textures\explosion_04.h

@REM python tools\gif2buf.py assets\dog.webp assets\dog --name dog --replace_color 255 255 255 0 > .\code\scene\textures\dog_anim.h
@REM python tools\gif2buf.py assets\fire.gif assets\fire --name fire --replace_color 255 255 255 0 > .\code\scene\textures\fire_anim.h

@REM python tools\tile.py  assets\bank4g.gif 3 3 --replace_color 0 0 0 12  
@REM python tools\gif2buf.py assets\bank4g_tiles\tile_0_2.gif assets\bank4g --name explosion_05 --flist 0 3 5 7 > .\code\scene\textures\explosion_05.h