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



// #include "h3/h3.h"
// #include "h3/h3.c"

unsigned char start_round[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

// ======
// PACK 1
// ======
#include "textures/metalwall_1.h"

#include "textures/texture_door.h"

#include "textures/keys.h"
#include "textures/letter.h"

#include "textures/tree_1.h"
#include "textures/tree_2.h"
#include "textures/tree_3.h"
#include "textures/mangrove_2.h"
#include "textures/tree_1_lightred.h"
#include "textures/mangrove_1.h"

// ======
// PACK 2
// ======
// #include "textures/bigredbrick_1.h"
#include "textures/metalwall_2.h"
#include "textures/gate.h"


#include "textures/princess_back.h"
#include "textures/princess_front.h"
#include "textures/princess_left.h"
#include "textures/princess_right.h"

#include "textures/texture_fire_anim.h"

// #include "textures/key_1.h"
// #include "textures/parchment_open.h"

// #include "textures/tree_2_yellow.h"
// #include "textures/mangrove_3.h"
// #include "textures/texture_tree.h"
// #include "textures/tree_1_red.h"
// #include "textures/tree_1_yellow.h"
// #include "textures/tree_2_lightred.h"




// ======
// PACK 3
// ======
#include "textures/roundstonewall_1.h"
#include "textures/gate_2.h"

#include "textures/strong_man.h"
#include "textures/arbalete.h"

#include "textures/dragon_1.h"
#include "textures/siren.h"
#include "textures/merlin.h"
#include "textures/eye.h"
#include "textures/eye_2.h"
#include "textures/potion.h"

// #include "textures/princess_back.h"
// #include "textures/princess_front.h"
// #include "textures/princess_left.h"
// #include "textures/princess_right.h"

// #include "textures/texture_fire_anim.h"

// #include "textures/explosion.h"

// #include "textures/explosion_02.h"



/*
// ======
// PACK 4
// ======

#include "textures/texture_door.h"

#include "textures/fighter_back.h"
#include "textures/fighter_front.h"
#include "textures/fighter_left.h"
#include "textures/fighter_right.h"

#include "textures/tree_3.h"

#include "textures/explosion_03.h"

// ======
// PACK 5
// ======

#include "textures/texture_metalwall.h"

#include "textures/bull_back.h"
#include "textures/bull_front.h"
#include "textures/bull_left.h"
#include "textures/bull_right.h"



#include "textures/explosion_04.h"

// ======
// PACK 6
// ======

#include "textures/texture_claybricks.h"

#include "textures/lpc_minotaur_back.h"
#include "textures/lpc_minotaur_front.h"
#include "textures/lpc_minotaur_left.h"
#include "textures/lpc_minotaur_right.h"

#include "textures/mangrove_2.h"

#include "textures/explosion_05.h"
*/


/*
// ======
// PACK 7
// ======

#include "textures/texture_purplestone.h"


#include "textures/lamp.h"

#include "textures/map.h"

#include "textures/fountain.h"

#include "textures/potion.h"
#include "textures/headheap.h"


// ======
// PACK 8
// ======

#include "textures/statue_3.h"
#include "textures/chest.h"
#include "textures/arbalete_2.h"
#include "textures/texture_key.h"

#include "textures/merlin.h"

#include "textures/dragon_1.h"
#include "textures/dragon_2.h"
#include "textures/eye.h"

// ======
// PACK 9
// ======

#include "textures/tree_2_yellow.h"
#include "textures/mangrove_3.h"
#include "textures/parchment_close.h"
#include "textures/texture_pillar.h"
#include "textures/statue_1.h"
#include "textures/statue_2.h"
#include "textures/texture_bluestone.h"
#include "textures/texture_bluewall.h"
#include "textures/texture_dentwall.h"
#include "textures/texture_logo.h"
*/
/*#include "textures/texture_christmas.h"*/

// #include "textures/cat_back.h"
// #include "textures/cat_front.h"
// #include "textures/cat_left.h"
// #include "textures/cat_right.h"


// #include "textures/texture_sback.h"
// #include "textures/texture_sfront.h"
// #include "textures/texture_sleft.h"
// #include "textures/texture_sright.h"


// #include "textures/dog_anim.h"


// #include "textures/texture_tree.h"
// #include "textures/tree_1_red.h"
// #include "textures/tree_1_yellow.h"
// #include "textures/tree_2_lightred.h"
// #include "textures/tree_2_red.h"
// #include "textures/texture_gridwall.h"
// #include "textures/texture_logo.h"
// #include "textures/texture_redbrick.h"
// #include "textures/texture_redbricks.h"
// #include "textures/texture_bigbricks.h"




// #include "textures/princess_back.h"
// #include "textures/princess_front.h"
// #include "textures/princess_left.h"
// #include "textures/princess_right.h"


// #include "textures/tree_2_red.h"