#pragma bank 6
#include "scene_navigation_menus_bo6.h"
#include "state.h"

#include "bg_search_result_text_bo6_1.h"
DRAW_BKG_ANIMATION(bg_search_result_text_bo6_1, 0, 0, 0)

#define SEARCH_ROW ICON_ROW_2
#define SEARCH_ANIMATION(frame) DRAW_SP_ANIMATION(sp_icon_search_bo6_##frame, 0, ICON_SP_2, ICON_DATA_2, ICON_W, ICON_H, ICON_COLUMN_1, ICON_ROW_2)
#include "sp_icon_search_bo6_1.h"
SEARCH_ANIMATION(1)
#include "sp_icon_search_bo6_2.h"
SEARCH_ANIMATION(2)
#include "sp_icon_search_bo6_3.h"
SEARCH_ANIMATION(3)
void init_sp_icon_search_bo6(void)
{
    draw_sp_icon_search_bo6_1_0();
}
DEFAULT_SP_TICK_START(sp_icon_search_bo6, 5)
DEFAULT_SP_TICK_CASE_TICKS(0, draw_sp_icon_search_bo6_1_0, 2)
DEFAULT_SP_TICK_CASE_TICKS(1, draw_sp_icon_search_bo6_2_0, 2)
DEFAULT_SP_TICK_CASE_TICKS(2, draw_sp_icon_search_bo6_3_0, 2)
DEFAULT_SP_TICK_CASE_TICKS(3, draw_sp_icon_search_bo6_2_0, 2)
DEFAULT_SP_TICK_CASE_TICKS(4, draw_sp_icon_search_bo6_1_0, 2)
DEFAULT_SP_TICK_END

#define WAIT_ROW ICON_ROW_2
#define WAIT_ANIMATION(frame) DRAW_SP_ANIMATION(sp_icon_wait_bo6_##frame, 0, ICON_SP_3, ICON_DATA_3, ICON_W, ICON_H, ICON_COLUMN_1, ICON_ROW_3)
#include "sp_icon_wait_bo6_1.h"
WAIT_ANIMATION(1)
#include "sp_icon_wait_bo6_2.h"
WAIT_ANIMATION(2)
#include "sp_icon_wait_bo6_3.h"
WAIT_ANIMATION(3)
#include "sp_icon_wait_bo6_4.h"
WAIT_ANIMATION(4)
#include "sp_icon_wait_bo6_5.h"
WAIT_ANIMATION(5)
#include "sp_icon_wait_bo6_6.h"
WAIT_ANIMATION(6)
#include "sp_icon_wait_bo6_7.h"
WAIT_ANIMATION(7)
#include "sp_icon_wait_bo6_8.h"
WAIT_ANIMATION(8)
#include "sp_icon_wait_bo6_9.h"
WAIT_ANIMATION(9)
void init_sp_icon_wait_bo6(void)
{
    draw_sp_icon_wait_bo6_1_0();
}
DEFAULT_SP_TICK_START(sp_icon_wait_bo6, 9)
DEFAULT_SP_TICK_CASE_TICKS(0, draw_sp_icon_wait_bo6_1_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(1, draw_sp_icon_wait_bo6_2_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(2, draw_sp_icon_wait_bo6_3_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(3, draw_sp_icon_wait_bo6_4_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(4, draw_sp_icon_wait_bo6_5_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(5, draw_sp_icon_wait_bo6_6_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(6, draw_sp_icon_wait_bo6_7_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(7, draw_sp_icon_wait_bo6_8_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(8, draw_sp_icon_wait_bo6_9_0, 10)
DEFAULT_SP_TICK_END

#define TALK_ROW ICON_ROW_2
#define TALK_ANIMATION(frame) DRAW_SP_ANIMATION(sp_icon_talk_bo6_##frame, 0, ICON_SP_3, ICON_DATA_4, ICON_W, ICON_H, ICON_COLUMN_1, ICON_ROW_3)
#include "sp_icon_talk_bo6_1.h"
TALK_ANIMATION(1)
#include "sp_icon_talk_bo6_2.h"
TALK_ANIMATION(2)
#include "sp_icon_talk_bo6_3.h"
TALK_ANIMATION(3)
#include "sp_icon_talk_bo6_4.h"
TALK_ANIMATION(4)
#include "sp_icon_talk_bo6_5.h"
TALK_ANIMATION(5)
#include "sp_icon_talk_bo6_6.h"
TALK_ANIMATION(6)
void init_sp_icon_talk_bo6(void)
{
    draw_sp_icon_talk_bo6_1_0();
}
DEFAULT_SP_TICK_START(sp_icon_talk_bo6, 6)
DEFAULT_SP_TICK_CASE_TICKS(0, draw_sp_icon_talk_bo6_1_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(1, draw_sp_icon_talk_bo6_2_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(2, draw_sp_icon_talk_bo6_3_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(3, draw_sp_icon_talk_bo6_4_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(4, draw_sp_icon_talk_bo6_5_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(5, draw_sp_icon_talk_bo6_1_0, 10)
DEFAULT_SP_TICK_END

#define BAG_ROW ICON_ROW_2
#define BAG_ANIMATION(frame, suffix, row) DRAW_SP_ANIMATION(sp_icon_bag_bo6_##frame, suffix, ICON_SP_6, ICON_DATA_6, ICON_W, ICON_H, ICON_COLUMN_1, row)
#include "sp_icon_bag_bo6_1.h"
BAG_ANIMATION(1, r4, ICON_ROW_4)
BAG_ANIMATION(1, r5, ICON_ROW_5)
BAG_ANIMATION(1, r6, ICON_ROW_6)
#include "sp_icon_bag_bo6_2.h"
BAG_ANIMATION(2, r4, ICON_ROW_4)
BAG_ANIMATION(2, r5, ICON_ROW_5)
BAG_ANIMATION(2, r6, ICON_ROW_6)
int draw_sp_bag_saved;
void init_sp_icon_bag_bo6(int row)
{
    draw_sp_bag_saved = row;
    switch (row)
    {
    case 4:
        draw_sp_icon_bag_bo6_1_r4();
        break;
    case 5:
        draw_sp_icon_bag_bo6_1_r5();
        break;
    case 6:
        draw_sp_icon_bag_bo6_1_r6();
        break;
    }
}
void draw_sp_bag_saved_1(void)
{
    switch (draw_sp_bag_saved)
    {
    case 3:
        draw_sp_icon_bag_bo6_1_r4();
        break;
    case 5:
        draw_sp_icon_bag_bo6_1_r6();
        break;
    }
}
void draw_sp_bag_saved_2(void)
{
    switch (draw_sp_bag_saved)
    {
    case 3:
        draw_sp_icon_bag_bo6_2_r4();
        break;
    case 5:
        draw_sp_icon_bag_bo6_2_r6();
        break;
    }
}
DEFAULT_SP_TICK_START(sp_icon_bag_bo6, 2)
DEFAULT_SP_TICK_CASE_TICKS(0, draw_sp_bag_saved_1, 2)
DEFAULT_SP_TICK_CASE_TICKS(1, draw_sp_bag_saved_2, 2)
DEFAULT_SP_TICK_END

#define POTION_HEADER_TILE_LENGTH 40
#define POTION_HEADER_FIRST_TILE 40
#include "bg_potion_headers_bo6_1.h"
DRAW_BKG_ANIMATION(bg_potion_headers_bo6_1, POTION_HEADER_FIRST_TILE, 0, 0)
#include "bg_potion_headers_bo6_2.h"
DRAW_BKG_ANIMATION(bg_potion_headers_bo6_2, POTION_HEADER_FIRST_TILE, 0, 0)
#include "bg_potion_headers_bo6_3.h"
DRAW_BKG_ANIMATION(bg_potion_headers_bo6_3, POTION_HEADER_FIRST_TILE, 0, 0)
#include "bg_potion_headers_bo6_4.h"
DRAW_BKG_ANIMATION(bg_potion_headers_bo6_4, POTION_HEADER_FIRST_TILE, 0, 0)
#include "bg_potion_headers_bo6_5.h"
DRAW_BKG_ANIMATION(bg_potion_headers_bo6_5, POTION_HEADER_FIRST_TILE, 0, 0)
#include "bg_potion_headers_bo6_6.h"
DRAW_BKG_ANIMATION(bg_potion_headers_bo6_6, POTION_HEADER_FIRST_TILE, 0, 0)

#include "bg_potion_completed_bo6_1.h"
DRAW_BKG_ANIMATION(bg_potion_completed_bo6_1, POTION_HEADER_FIRST_TILE + POTION_HEADER_TILE_LENGTH, 0, 6)

void init_bg_last_potion(void)
{
    switch (state.last_item_found)
    {
    case ItemID_LilyPotion:
        init_bg_potion_headers_bo6_1();
        break;
    }
}
