#include "scene_title_bo1.h"
#include "state.h"

#pragma bank 1

#include "bg_title_bo1.h"
DRAW_BKG_ANIMATION(bg_title_bo1, 0, 0, 0)
#include "bg_end_screen_bo1.h"
DRAW_BKG_ANIMATION(bg_end_screen_bo1, 0, 0, 0)

#include "sp_start_bo1.h"
DRAW_SP_ANIMATION(sp_start_bo1, 0, ICON_SP_1, ICON_DATA_1, ICON_W, ICON_H, 140, 90)
void init_sp_start_bo1() { init_sp_start_bo1_0(); }
void tick_sp_start_bo1() {}

#include "sp_cursor_bo1.h"
enum CursorMode cursor_mode = CursorMode_SideMenu;
void set_cursor_mode(enum CursorMode mode)
{
    cursor_mode = mode;
}
struct SpriteData cursor_data = {
    ICON_DATA_7,
    ICON_SP_7,
    ICON_W,
    ICON_H,
    sp_cursor_bo1_map,
    sp_cursor_bo1_tiles,
};
struct SpriteOpArgs cursor_args = {
    120,
    90,
};
void init_sp_cursor_bo1(void)
{
    scene_sprite_operation(cursor_data, SpriteOp_SetData | SpriteOp_SetTile | SpriteOp_Move, cursor_args);
}
struct animation cursor_animation = {0, 2, 1, 0};
void tick_sp_cursor_bo1(void)
{
    clock_t now = clock();
    if (now - cursor_animation.last_frame > ANIMATION_INTERVAL_CLOCKS)
    {
        cursor_animation.ticks_left -= 1;
        cursor_animation.last_frame = now;
        if (cursor_animation.ticks_left <= 0)
        {
            cursor_animation.current_frame = (cursor_animation.current_frame + 1) % cursor_animation.total_frames;
        }
    }
    if (cursor_mode == CursorMode_SideMenu)
    {
        cursor_args.x = ICON_COLUMN_1 - 16;
        cursor_args.y = ICON_ROW_1 + state.cursor_menu_choice * (ICON_ROW_SPACING);
    }
    switch (cursor_animation.current_frame)
    {
    case 0:
        cursor_args.x -= 2;
        scene_sprite_operation(cursor_data, SpriteOp_Move, cursor_args);
        if (cursor_animation.ticks_left == 0)
        {
            cursor_animation.ticks_left = 2;
        }
        break;
    case 1:
        scene_sprite_operation(cursor_data, SpriteOp_Move, cursor_args);
        if (cursor_animation.ticks_left == 0)
        {
            cursor_animation.ticks_left = 8;
        }
        break;
    }
}