#pragma bank 14
#include "scene_witch_bo14.h"

#define WITCH_X_TILE 8
#define WITCH_Y_TILE 4
#include "bg_witch_normal_bo14.h"
DRAW_BKG_ANIMATION(bg_witch_normal_bo14, 0, WITCH_X_TILE, WITCH_Y_TILE)
#include "bg_witch_troll_bo14.h"
DRAW_BKG_ANIMATION(bg_witch_troll_bo14, 0, WITCH_X_TILE, WITCH_Y_TILE)
#include "bg_witch_zombie_bo14.h"
DRAW_BKG_ANIMATION(bg_witch_zombie_bo14, 0, WITCH_X_TILE, WITCH_Y_TILE)