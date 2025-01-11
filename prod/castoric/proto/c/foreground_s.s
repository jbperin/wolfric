#include "config.h"
#ifdef USE_FOREGROUND
.zero

_ptrReadForegroundLeft .dsb 2
_ptrReadForegroundRight .dsb 2

.text

#include "raycast\patch_gun_shoot.s"
#include "raycast\patch_gun_unshoot.s"
#include "raycast\patch_knife_shoot.s"
#include "raycast\patch_knife_unshoot.s"
#endif
