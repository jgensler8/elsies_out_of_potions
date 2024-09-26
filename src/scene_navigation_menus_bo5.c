#pragma bank 5
#include "scene_navigation_menus_bo5.h"
#include "scene_elsie_bo4.h"
#include "state.h"

#define HEADING(frame) DRAW_BKG_ANIMATION(bg_headings_bo5_##frame, ELSIE_BG_END, 0, 0)
#include "bg_headings_bo5_1.h"
HEADING(1)
#include "bg_headings_bo5_2.h"
HEADING(2)
#include "bg_headings_bo5_3.h"
HEADING(3)
#include "bg_headings_bo5_4.h"
HEADING(4)
#include "bg_headings_bo5_5.h"
HEADING(5)
#include "bg_headings_bo5_6.h"
HEADING(6)
#include "bg_headings_bo5_7.h"
HEADING(7)
#include "bg_headings_bo5_8.h"
HEADING(8)
#include "bg_headings_bo5_9.h"
HEADING(9)
#include "bg_headings_bo5_10.h"
HEADING(10)
// #include "bg_headings_bo5_11.h"
// HEADING(11)
uint8_t current_heading;
void init_bg_headings_bo5(void)
{
    state.cursor_menu_choice = 0;
    // trigger draw based on screen unable to fit 255 menu options
    current_heading = 255;
    tick_bg_headings_bo5();
}
#define SCENE_HEADING_CASE(choice, heading)         \
    case choice:                                    \
        init_bg_headings_bo5_##heading();           \
        current_heading = state.cursor_menu_choice; \
        break;
#define QUEST_HEADING_3 SCENE_HEADING_CASE(2, 9)
#define QUEST_HEADING_4 SCENE_HEADING_CASE(3, 9)
#define QUEST_HEADING_5 SCENE_HEADING_CASE(4, 9)
#define BAG_HEADING_4 SCENE_HEADING_CASE(3, 10)
#define BAG_HEADING_5 SCENE_HEADING_CASE(4, 10)
#define BAG_HEADING_6 SCENE_HEADING_CASE(5, 10)
void tick_bg_headings_bo5(void)
{
    if (state.cursor_menu_choice == current_heading)
    {
        return;
    }
    switch (state.current_scene)
    {
    case SceneID_Home:
        switch (state.cursor_menu_choice)
        {
            SCENE_HEADING_CASE(0, 1)
            SCENE_HEADING_CASE(1, 2)
            QUEST_HEADING_3
            BAG_HEADING_4
        }
        break;
    case SceneID_Path:
        switch (state.cursor_menu_choice)
        {
            SCENE_HEADING_CASE(0, 3)
            SCENE_HEADING_CASE(1, 4)
            SCENE_HEADING_CASE(2, 5)
            SCENE_HEADING_CASE(3, 6)
            QUEST_HEADING_5
            BAG_HEADING_6
        }
        break;
    case SceneID_Orchard:
    case SceneID_River:
    case SceneID_Graveyard:
        switch (state.cursor_menu_choice)
        {
            SCENE_HEADING_CASE(0, 1)
            SCENE_HEADING_CASE(1, 7)
            SCENE_HEADING_CASE(2, 8)
            QUEST_HEADING_4
            BAG_HEADING_5
        }
        break;
    }
}

#define CRAFT_ROW ICON_ROW_2
#define CRAFT_ANIMATION(frame) DRAW_SP_ANIMATION(sp_icon_craft_bo5_##frame, 0, ICON_SP_2, ICON_DATA_2, ICON_W, ICON_H, ICON_COLUMN_1, CRAFT_ROW)
#include "sp_icon_craft_bo5_1.h"
CRAFT_ANIMATION(1)
#include "sp_icon_craft_bo5_2.h"
CRAFT_ANIMATION(2)
#include "sp_icon_craft_bo5_3.h"
CRAFT_ANIMATION(3)
#include "sp_icon_craft_bo5_4.h"
CRAFT_ANIMATION(4)
#include "sp_icon_craft_bo5_5.h"
CRAFT_ANIMATION(5)
#include "sp_icon_craft_bo5_6.h"
CRAFT_ANIMATION(6)
#include "sp_icon_craft_bo5_7.h"
CRAFT_ANIMATION(7)
#include "sp_icon_craft_bo5_8.h"
CRAFT_ANIMATION(8)
void init_sp_icon_craft_bo5(void)
{
    draw_sp_icon_craft_bo5_1_0();
}
DEFAULT_SP_TICK_START(sp_icon_craft_bo5, 8)
DEFAULT_SP_TICK_CASE_TICKS(0, draw_sp_icon_craft_bo5_1_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(1, draw_sp_icon_craft_bo5_2_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(2, draw_sp_icon_craft_bo5_3_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(3, draw_sp_icon_craft_bo5_4_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(4, draw_sp_icon_craft_bo5_5_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(5, draw_sp_icon_craft_bo5_6_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(6, draw_sp_icon_craft_bo5_7_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(7, draw_sp_icon_craft_bo5_8_0, 1)
DEFAULT_SP_TICK_END

#define OUT_ROW ICON_ROW_1
#define OUT_ANIMATION(frame) DRAW_SP_ANIMATION(sp_icon_out_bo5_##frame, 0, ICON_SP_1, ICON_DATA_1, ICON_W, ICON_H, ICON_COLUMN_1, OUT_ROW)
#include "sp_icon_out_bo5_1.h"
OUT_ANIMATION(1)
#include "sp_icon_out_bo5_2.h"
OUT_ANIMATION(2)
#include "sp_icon_out_bo5_3.h"
OUT_ANIMATION(3)
#include "sp_icon_out_bo5_4.h"
OUT_ANIMATION(4)
#include "sp_icon_out_bo5_5.h"
OUT_ANIMATION(5)
#include "sp_icon_out_bo5_6.h"
OUT_ANIMATION(6)
#include "sp_icon_out_bo5_7.h"
OUT_ANIMATION(7)
#include "sp_icon_out_bo5_8.h"
OUT_ANIMATION(8)
#include "sp_icon_out_bo5_9.h"
OUT_ANIMATION(9)
#include "sp_icon_out_bo5_10.h"
OUT_ANIMATION(10)
#include "sp_icon_out_bo5_11.h"
OUT_ANIMATION(11)
#include "sp_icon_out_bo5_12.h"
OUT_ANIMATION(12)
#include "sp_icon_out_bo5_13.h"
OUT_ANIMATION(13)
#include "sp_icon_out_bo5_14.h"
OUT_ANIMATION(14)
#include "sp_icon_out_bo5_15.h"
OUT_ANIMATION(15)
#include "sp_icon_out_bo5_16.h"
OUT_ANIMATION(16)
void init_sp_icon_out_bo5(void)
{
    draw_sp_icon_out_bo5_1_0();
}
DEFAULT_SP_TICK_START(sp_icon_out_bo5, 16)
DEFAULT_SP_TICK_CASE_TICKS(0, draw_sp_icon_out_bo5_1_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(1, draw_sp_icon_out_bo5_2_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(2, draw_sp_icon_out_bo5_3_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(3, draw_sp_icon_out_bo5_4_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(4, draw_sp_icon_out_bo5_5_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(5, draw_sp_icon_out_bo5_6_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(6, draw_sp_icon_out_bo5_7_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(7, draw_sp_icon_out_bo5_8_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(8, draw_sp_icon_out_bo5_9_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(9, draw_sp_icon_out_bo5_10_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(10, draw_sp_icon_out_bo5_11_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(11, draw_sp_icon_out_bo5_12_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(12, draw_sp_icon_out_bo5_13_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(13, draw_sp_icon_out_bo5_14_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(14, draw_sp_icon_out_bo5_15_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(15, draw_sp_icon_out_bo5_16_0, 1)
DEFAULT_SP_TICK_END

#define HOME_ROW ICON_ROW_1
#define HOME_ANIMATION(frame) DRAW_SP_ANIMATION(sp_icon_home_bo5_##frame, 0, ICON_SP_1, ICON_DATA_1, ICON_W, ICON_H, ICON_COLUMN_1, HOME_ROW)
#include "sp_icon_home_bo5_1.h"
HOME_ANIMATION(1)
#include "sp_icon_home_bo5_2.h"
HOME_ANIMATION(2)
#include "sp_icon_home_bo5_3.h"
HOME_ANIMATION(3)
#include "sp_icon_home_bo5_4.h"
HOME_ANIMATION(4)

void init_sp_icon_home_bo5(void)
{
    draw_sp_icon_home_bo5_1_0();
}
DEFAULT_SP_TICK_START(sp_icon_home_bo5, 4)
DEFAULT_SP_TICK_CASE_TICKS(0, draw_sp_icon_home_bo5_1_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(1, draw_sp_icon_home_bo5_2_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(2, draw_sp_icon_home_bo5_3_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(3, draw_sp_icon_home_bo5_4_0, 1)
DEFAULT_SP_TICK_END

#define ORCHARD_ROW ICON_ROW_2
#define ORCHARD_ANIMATION(frame) DRAW_SP_ANIMATION(sp_icon_orchard_bo5_##frame, 0, ICON_SP_2, ICON_DATA_2, ICON_W, ICON_H, ICON_COLUMN_1, ORCHARD_ROW)
#include "sp_icon_orchard_bo5_1.h"
ORCHARD_ANIMATION(1)
#include "sp_icon_orchard_bo5_2.h"
ORCHARD_ANIMATION(2)
void init_sp_icon_orchard_bo5(void)
{
    draw_sp_icon_orchard_bo5_1_0();
}
DEFAULT_SP_TICK_START(sp_icon_orchard_bo5, 2)
DEFAULT_SP_TICK_CASE_TICKS(0, draw_sp_icon_orchard_bo5_1_0, 6)
DEFAULT_SP_TICK_CASE_TICKS(1, draw_sp_icon_orchard_bo5_2_0, 6)
DEFAULT_SP_TICK_END

#define RIVER_ROW ICON_ROW_3
#define RIVER_ANIMATION(frame) DRAW_SP_ANIMATION(sp_icon_river_bo5_##frame, 0, ICON_SP_3, ICON_DATA_3, ICON_W, ICON_H, ICON_COLUMN_1, RIVER_ROW)
#include "sp_icon_river_bo5_1.h"
RIVER_ANIMATION(1)
#include "sp_icon_river_bo5_2.h"
RIVER_ANIMATION(2)
#include "sp_icon_river_bo5_3.h"
RIVER_ANIMATION(3)
#include "sp_icon_river_bo5_4.h"
RIVER_ANIMATION(4)
#include "sp_icon_river_bo5_5.h"
RIVER_ANIMATION(5)
void init_sp_icon_river_bo5(void)
{
    draw_sp_icon_river_bo5_1_0();
}
DEFAULT_SP_TICK_START(sp_icon_river_bo5, 5)
DEFAULT_SP_TICK_CASE_TICKS(0, draw_sp_icon_river_bo5_1_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(1, draw_sp_icon_river_bo5_2_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(2, draw_sp_icon_river_bo5_3_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(3, draw_sp_icon_river_bo5_4_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(4, draw_sp_icon_river_bo5_5_0, 1)
DEFAULT_SP_TICK_END

#define GRAVEYARD_ROW ICON_ROW_4
#define GRAVEYARD_ANIMATION(frame) DRAW_SP_ANIMATION(sp_icon_graveyard_bo5_##frame, 0, ICON_SP_4, ICON_DATA_4, ICON_W, ICON_H, ICON_COLUMN_1, GRAVEYARD_ROW)
#include "sp_icon_graveyard_bo5_1.h"
GRAVEYARD_ANIMATION(1)
#include "sp_icon_graveyard_bo5_2.h"
GRAVEYARD_ANIMATION(2)
#include "sp_icon_graveyard_bo5_3.h"
GRAVEYARD_ANIMATION(3)
#include "sp_icon_graveyard_bo5_4.h"
GRAVEYARD_ANIMATION(4)
#include "sp_icon_graveyard_bo5_5.h"
GRAVEYARD_ANIMATION(5)
#include "sp_icon_graveyard_bo5_6.h"
GRAVEYARD_ANIMATION(6)
#include "sp_icon_graveyard_bo5_7.h"
GRAVEYARD_ANIMATION(7)
#include "sp_icon_graveyard_bo5_8.h"
GRAVEYARD_ANIMATION(8)
#include "sp_icon_graveyard_bo5_9.h"
GRAVEYARD_ANIMATION(9)
#include "sp_icon_graveyard_bo5_10.h"
GRAVEYARD_ANIMATION(10)
#include "sp_icon_graveyard_bo5_11.h"
GRAVEYARD_ANIMATION(11)
void init_sp_icon_graveyard_bo5(void)
{
    draw_sp_icon_graveyard_bo5_1_0();
}
DEFAULT_SP_TICK_START(sp_icon_graveyard_bo5, 11)
DEFAULT_SP_TICK_CASE_TICKS(0, draw_sp_icon_graveyard_bo5_1_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(1, draw_sp_icon_graveyard_bo5_2_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(2, draw_sp_icon_graveyard_bo5_3_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(3, draw_sp_icon_graveyard_bo5_4_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(4, draw_sp_icon_graveyard_bo5_5_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(5, draw_sp_icon_graveyard_bo5_6_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(6, draw_sp_icon_graveyard_bo5_7_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(7, draw_sp_icon_graveyard_bo5_8_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(8, draw_sp_icon_graveyard_bo5_9_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(9, draw_sp_icon_graveyard_bo5_10_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(10, draw_sp_icon_graveyard_bo5_11_0, 1)
DEFAULT_SP_TICK_END

#define QUEST_ROW ICON_ROW_2
#define QUEST_ANIMATION(frame, suffix, row) DRAW_SP_ANIMATION(sp_icon_quest_bo5_##frame, suffix, ICON_SP_5, ICON_DATA_5, ICON_W, ICON_H, ICON_COLUMN_1, row)
#include "sp_icon_quest_bo5_1.h"
QUEST_ANIMATION(1, r3, ICON_ROW_3)
QUEST_ANIMATION(1, r4, ICON_ROW_4)
QUEST_ANIMATION(1, r5, ICON_ROW_5)
#include "sp_icon_quest_bo5_2.h"
QUEST_ANIMATION(2, r3, ICON_ROW_3)
QUEST_ANIMATION(2, r4, ICON_ROW_4)
QUEST_ANIMATION(2, r5, ICON_ROW_5)
int draw_sp_icon_saved;
void init_sp_icon_quest_bo5(int row)
{
    draw_sp_icon_saved = row;
    switch (row)
    {
    case 3:
        init_sp_icon_quest_bo5_1_r3();
        break;
    case 4:
        init_sp_icon_quest_bo5_1_r4();
        break;
    case 5:
        init_sp_icon_quest_bo5_1_r5();
        break;
    }
}
void draw_sp_icon_quest_saved_1()
{
    switch (draw_sp_icon_saved)
    {
    case 3:
        init_sp_icon_quest_bo5_1_r3();
        break;
    case 5:
        init_sp_icon_quest_bo5_1_r5();
        break;
    }
}
void draw_sp_icon_quest_saved_2()
{
    switch (draw_sp_icon_saved)
    {
    case 3:
        init_sp_icon_quest_bo5_2_r3();
        break;
    case 5:
        init_sp_icon_quest_bo5_2_r5();
        break;
    }
}
DEFAULT_SP_TICK_START(sp_icon_quest_bo5, 2)
DEFAULT_SP_TICK_CASE_TICKS(0, draw_sp_icon_quest_saved_1, 6)
DEFAULT_SP_TICK_CASE_TICKS(1, draw_sp_icon_quest_saved_2, 6)
DEFAULT_SP_TICK_END

#define EXCLAMATION_ROW ICON_ROW_2
#define EXCLAMATION_ANIMATION(frame) DRAW_SP_ANIMATION(sp_icon_exclamation_bo5_##frame, 0, ICON_SP_6, ICON_DATA_6, ICON_W, ICON_H, ICON_COLUMN_2, ICON_ROW_1)
#include "sp_icon_exclamation_bo5_1.h"
EXCLAMATION_ANIMATION(1)
#include "sp_icon_exclamation_bo5_2.h"
EXCLAMATION_ANIMATION(2)
#include "sp_icon_exclamation_bo5_3.h"
EXCLAMATION_ANIMATION(3)
void init_sp_icon_exclamation_bo5(void)
{
    draw_sp_icon_exclamation_bo5_1_0();
}
DEFAULT_SP_TICK_START(sp_icon_exclamation_bo5, 5)
DEFAULT_SP_TICK_CASE_TICKS(0, draw_sp_icon_exclamation_bo5_1_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(1, draw_sp_icon_exclamation_bo5_2_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(2, draw_sp_icon_exclamation_bo5_3_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(3, draw_sp_icon_exclamation_bo5_2_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(4, draw_sp_icon_exclamation_bo5_1_0, 1)
DEFAULT_SP_TICK_END
