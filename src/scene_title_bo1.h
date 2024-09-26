#pragma once
#include "scene.h"

SCENE_BKG_HEADER(bg_title_bo1)
SCENE_BKG_HEADER(bg_end_screen_bo1)
SCENE_SPRITE_HEADER(sp_cursor_bo1)
SCENE_SPRITE_HEADER(sp_start_bo1)

enum CursorMode
{
    // one column on the right side
    CursorMode_SideMenu,
    // a grid of options, might have issues with sprite limit (?)
    CursorMode_GridMenu,
};

void set_cursor_mode(enum CursorMode mode);