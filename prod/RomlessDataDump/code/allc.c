#include "util.h"

#include "rom/myRom.h"
#include "rom/system.h"
#include "rom/myRom.c"

#include "rom/input.h"
#include "rom/input.c"

#include "rom/keyboard.h"
#include "rom/keyboard_c.c"
#include "rom/keyrepeat.c"

#include "rom/system.c"


unsigned char start_round[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

// wm $2000 11264 texture_base.bin
// COPY %OSDK%\Oricutron\texture_base.bin ..\..\data

#include "textures/bluewall.h"
#include "textures/door_1.h"
#include "textures/metalwall.h"
#include "textures/lamp_1.h"
#include "textures/soldier_back.h"
#include "textures/soldier_front.h"
#include "textures/soldier_left.h"
#include "textures/soldier_right.h"
#include "textures/pieceofmeat.h"
#include "textures/gridwall.h"
#include "textures/sprite_deadsoldier.h"

#include "textures/ammo_1.h"