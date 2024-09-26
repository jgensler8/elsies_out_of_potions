#pragma bank 7
#include "scene_navigation_menus_bo7.h"
#include "state.h"

//
// Quest Screen
//

#define QUEST_ROW_1 1
#define QUEST_ROW_2 QUEST_ROW_1 + 2
#define QUEST_ROW_3 QUEST_ROW_2 + 2
#define QUEST_ROW_4 QUEST_ROW_3 + 2
#define QUEST_ROW_5 QUEST_ROW_4 + 2
#define QUEST_ROW_6 QUEST_ROW_5 + 2
#define QUEST_ROW_7 QUEST_ROW_6 + 2

#define QUEST_SCREEN_TEXT_TILE_WIDTH 20
#define QUEST_QUEST_TILE 0
#define QUEST_QUEST_X 0
#define QUEST_NEEDS_TILE QUEST_QUEST_TILE + QUEST_SCREEN_TEXT_TILE_WIDTH
#define QUEST_NEEDS_X 0
#define QUEST_RECIPE_TILE QUEST_NEEDS_TILE + QUEST_SCREEN_TEXT_TILE_WIDTH
#define QUEST_RECIPE_X 0
#include "bg_quest_screen_text_bo7_1.h"
DRAW_BKG_ANIMATION(bg_quest_screen_text_bo7_1, QUEST_QUEST_TILE, QUEST_QUEST_X, QUEST_ROW_2)
#include "bg_quest_screen_text_bo7_2.h"
DRAW_BKG_ANIMATION(bg_quest_screen_text_bo7_2, QUEST_NEEDS_TILE, QUEST_NEEDS_X, QUEST_ROW_4)
#include "bg_quest_screen_text_bo7_3.h"
DRAW_BKG_ANIMATION(bg_quest_screen_text_bo7_3, QUEST_RECIPE_TILE, QUEST_RECIPE_X, QUEST_ROW_4)

// #define QUEST_NAMES_TILE QUEST_RECIPE_TILE + 20
// #define QUEST_NAME_X 9
// #include "bg_character_names_bo7_1.h"
// DRAW_BKG_ANIMATION(bg_character_names_bo7_1, QUEST_NAMES_TILE, QUEST_NAME_X, QUEST_ROW_1)
// #include "bg_character_names_bo7_2.h"
// DRAW_BKG_ANIMATION(bg_character_names_bo7_2, QUEST_NAMES_TILE, QUEST_NAME_X, QUEST_ROW_1)
// #include "bg_character_names_bo7_3.h"
// DRAW_BKG_ANIMATION(bg_character_names_bo7_3, QUEST_NAMES_TILE, QUEST_NAME_X, QUEST_ROW_1)

#define QUEST_POTION_NAME_WIDTH 34
#define QUEST_POTION_NAME_TILE QUEST_RECIPE_TILE + QUEST_SCREEN_TEXT_TILE_WIDTH
#define QUEST_POTION_X 0
#include "bg_potion_names_bo7_1.h"
DRAW_BKG_ANIMATION(bg_potion_names_bo7_1, QUEST_POTION_NAME_TILE, QUEST_POTION_X, QUEST_ROW_3)
#include "bg_potion_names_bo7_2.h"
DRAW_BKG_ANIMATION(bg_potion_names_bo7_2, QUEST_POTION_NAME_TILE, QUEST_POTION_X, QUEST_ROW_3)
#include "bg_potion_names_bo7_3.h"
DRAW_BKG_ANIMATION(bg_potion_names_bo7_3, QUEST_POTION_NAME_TILE, QUEST_POTION_X, QUEST_ROW_3)
#include "bg_potion_names_bo7_4.h"
DRAW_BKG_ANIMATION(bg_potion_names_bo7_4, QUEST_POTION_NAME_TILE, QUEST_POTION_X, QUEST_ROW_3)
#include "bg_potion_names_bo7_5.h"
DRAW_BKG_ANIMATION(bg_potion_names_bo7_5, QUEST_POTION_NAME_TILE, QUEST_POTION_X, QUEST_ROW_3)
#include "bg_potion_names_bo7_6.h"
DRAW_BKG_ANIMATION(bg_potion_names_bo7_6, QUEST_POTION_NAME_TILE, QUEST_POTION_X, QUEST_ROW_3)

#define QUEST_RESOURCE_X 0
#define RESOURCE_NAME_TILE_WIDTH 30
#define QUEST_RESOURCE_1_TILE QUEST_POTION_NAME_TILE + QUEST_POTION_NAME_WIDTH
#define QUEST_RESOURCE_2_TILE QUEST_RESOURCE_1_TILE + RESOURCE_NAME_TILE_WIDTH
#include "bg_resource_names_bo7_1.h"
DRAW_BKG_ANIMATION(bg_resource_names_bo7_1, QUEST_RESOURCE_1_TILE, QUEST_RESOURCE_X, QUEST_ROW_5)
#include "bg_resource_names_bo7_2.h"
DRAW_BKG_ANIMATION(bg_resource_names_bo7_2, QUEST_RESOURCE_1_TILE, QUEST_RESOURCE_X, QUEST_ROW_5)
#include "bg_resource_names_bo7_3.h"
DRAW_BKG_ANIMATION(bg_resource_names_bo7_3, QUEST_RESOURCE_2_TILE, QUEST_RESOURCE_X, QUEST_ROW_6)
#include "bg_resource_names_bo7_4.h"
DRAW_BKG_ANIMATION(bg_resource_names_bo7_4, QUEST_RESOURCE_2_TILE, QUEST_RESOURCE_X, QUEST_ROW_6)
#include "bg_resource_names_bo7_5.h"
DRAW_BKG_ANIMATION(bg_resource_names_bo7_5, QUEST_RESOURCE_1_TILE, QUEST_RESOURCE_X, QUEST_ROW_5)
#include "bg_resource_names_bo7_6.h"
DRAW_BKG_ANIMATION(bg_resource_names_bo7_6, QUEST_RESOURCE_1_TILE, QUEST_RESOURCE_X, QUEST_ROW_5)
#include "bg_resource_names_bo7_7.h"
DRAW_BKG_ANIMATION(bg_resource_names_bo7_7, QUEST_RESOURCE_2_TILE, QUEST_RESOURCE_X, QUEST_ROW_6)
#include "bg_resource_names_bo7_8.h"
DRAW_BKG_ANIMATION(bg_resource_names_bo7_8, QUEST_RESOURCE_2_TILE, QUEST_RESOURCE_X, QUEST_ROW_6)
#include "bg_resource_names_bo7_9.h"
DRAW_BKG_ANIMATION(bg_resource_names_bo7_9, QUEST_RESOURCE_1_TILE, QUEST_RESOURCE_X, QUEST_ROW_5)
#include "bg_resource_names_bo7_10.h"
DRAW_BKG_ANIMATION(bg_resource_names_bo7_10, QUEST_RESOURCE_2_TILE, QUEST_RESOURCE_X, QUEST_ROW_6)

#define HAVE_ITEM(item) (state.item_counts[item] > 0)

inline void draw_item(enum ItemID item)
{
    switch (item)
    {
    // item 1
    case ItemID_SpryBerry:
        init_bg_resource_names_bo7_1();
        return;
    case ItemID_PineBark:
        init_bg_resource_names_bo7_2();
        return;
    case ItemID_MossTuft:
        init_bg_resource_names_bo7_5();
        return;
    case ItemID_WetLeaf:
        init_bg_resource_names_bo7_6();
        return;
    case ItemID_BoneDust:
        init_bg_resource_names_bo7_9();
        return;
    // item 2
    case ItemID_LilyStem:
        init_bg_resource_names_bo7_3();
        return;
    case ItemID_RosePetal:
        init_bg_resource_names_bo7_4();
        return;
    case ItemID_SnakeSkin:
        init_bg_resource_names_bo7_7();
        return;
    case ItemID_FishBones:
        init_bg_resource_names_bo7_8();
        return;
    case ItemID_BellFlower:
        init_bg_resource_names_bo7_10();
        return;
    }
}

void init_number_data();
inline void draw_resource_number(enum ItemID resource, uint8_t start_sprite_index, uint8_t bg_row_y);
void init_bg_recipe(enum ItemID recipe, uint8_t with_numbers)
{
    init_number_data();
    // recipe item 1
    enum ItemID i1 = required_item_1(recipe);
    draw_item(i1);
    if (with_numbers)
    {
        draw_resource_number(i1, ICON_SP_1, QUEST_ROW_6);
    }
    // recipe item 2
    enum ItemID i2 = required_item_2(recipe);
    draw_item(i2);
    if (with_numbers)
    {
        draw_resource_number(i2, ICON_SP_2, QUEST_ROW_7);
    }
}

// inline void init_bg_quest_person(void)
// {
//     switch (state.quest.person)
//     {
//     // case PersonID_None:
//     //     init_bg_character_names_bo7_1();
//     //     break;
//     case PersonID_WitchOfTheWoods:
//         init_bg_character_names_bo7_1();
//         break;
//     case PersonID_RiverTroll:
//         init_bg_character_names_bo7_2();
//         break;
//     case PersonID_Zombie:
//         init_bg_character_names_bo7_3();
//         break;
//     }
// }

void init_bg_potion_name(enum ItemID item)
{
    switch (item)
    {
    // case ItemID_None:
    //     init_bg_potion_names_bo7_1();
    //     break;
    case ItemID_LilyPotion:
        init_bg_potion_names_bo7_1();
        return;
    case ItemID_Fortifier:
        init_bg_potion_names_bo7_2();
        return;
    case ItemID_EasyRemedy:
        init_bg_potion_names_bo7_3();
        return;
    case ItemID_GreenFlux:
        init_bg_potion_names_bo7_4();
        return;
    case ItemID_SimpleWash:
        init_bg_potion_names_bo7_5();
        return;
    case ItemID_LifeMana:
        init_bg_potion_names_bo7_6();
        return;
    }
}

void init_bg_quest_screen_bo7(void)
{
    // init_bg_quest_screen_text_bo7_1();
    // init_bg_quest_person();
    init_bg_quest_screen_text_bo7_1();
    init_bg_potion_name(state.quest.item);
    if (HAVE_ITEM(state.quest.item))
    {
        init_bg_quest_screen_text_bo7_3();
        return;
    }
    else
    {
        init_bg_quest_screen_text_bo7_2();
        init_bg_recipe(state.quest.item, 0);
    }
}

void init_bg_last_item_found_bo7(void)
{
    draw_item(state.last_item_found);
}

//
// Items (Bag) Screen
//

#define ITEMS_ROW_1 1
#define ITEMS_ROW_2 ITEMS_ROW_1 + 2
#define ITEMS_ROW_3 ITEMS_ROW_2 + 2
#define ITEMS_ROW_4 ITEMS_ROW_3 + 2
#define ITEMS_ROW_5 ITEMS_ROW_4 + 2
#define ITEMS_ROW_6 ITEMS_ROW_5 + 2
#define ITEMS_ROW_7 ITEMS_ROW_6 + 2
#define ITEMS_ROW_8 ITEMS_ROW_7 + 2
#define ITEMS_ROW_9 ITEMS_ROW_8 + 2
#define ITEMS_PAGE_TILE 0
#define ITEMS_ITEMS_TILE 0 + 24
#define ITEMS_ITEMS_X 0
#include "bg_items_screen_text_bo7_1.h"
DRAW_BKG_ANIMATION(bg_items_screen_text_bo7_1, ITEMS_PAGE_TILE, ITEMS_ITEMS_X, ITEMS_ROW_1)
#include "bg_items_screen_text_bo7_2.h"
DRAW_BKG_ANIMATION(bg_items_screen_text_bo7_2, ITEMS_PAGE_TILE, ITEMS_ITEMS_X, ITEMS_ROW_1)
#include "bg_items_screen_text_bo7_3.h"
DRAW_BKG_ANIMATION(bg_items_screen_text_bo7_3, ITEMS_PAGE_TILE, ITEMS_ITEMS_X, ITEMS_ROW_1)
#include "bg_items_screen_text_bo7_4.h"
DRAW_BKG_ANIMATION(bg_items_screen_text_bo7_4, ITEMS_ITEMS_TILE, ITEMS_ITEMS_X, ITEMS_ROW_2)
#include "bg_items_screen_text_bo7_5.h"
DRAW_BKG_ANIMATION(bg_items_screen_text_bo7_5, ITEMS_PAGE_TILE, ITEMS_ITEMS_X, ITEMS_ROW_1)
// #include "bg_items_screen_text_bo7_6.h"
// DRAW_BKG_ANIMATION(bg_items_screen_text_bo7_6, ITEMS_PAGE_TILE, ITEMS_ITEMS_X, ITEMS_ROW_1)
// #include "bg_items_screen_text_bo7_7.h"
// DRAW_BKG_ANIMATION(bg_items_screen_text_bo7_7, ITEMS_PAGE_TILE, ITEMS_ITEMS_X, ITEMS_ROW_1)
// #include "bg_items_screen_text_bo7_8.h"
// DRAW_BKG_ANIMATION(bg_items_screen_text_bo7_8, ITEMS_PAGE_TILE, ITEMS_ITEMS_X, ITEMS_ROW_1)
// #include "bg_items_screen_text_bo7_9.h"
// DRAW_BKG_ANIMATION(bg_items_screen_text_bo7_9, ITEMS_PAGE_TILE, ITEMS_ITEMS_X, ITEMS_ROW_1)
// #include "bg_items_screen_text_bo7_10.h"
// DRAW_BKG_ANIMATION(bg_items_screen_text_bo7_10, ITEMS_PAGE_TILE, ITEMS_ITEMS_X, ITEMS_ROW_1)

// items

#define ITEMS_RESOURCE_1_TILE ITEMS_ITEMS_TILE + RESOURCE_NAME_TILE_WIDTH
#define ITEMS_RESOURCE_2_TILE ITEMS_RESOURCE_1_TILE + RESOURCE_NAME_TILE_WIDTH
#define ITEMS_RESOURCE_3_TILE ITEMS_RESOURCE_2_TILE + RESOURCE_NAME_TILE_WIDTH
#define ITEMS_RESOURCE_4_TILE ITEMS_RESOURCE_3_TILE + RESOURCE_NAME_TILE_WIDTH

#define BAG_TILE_SLOT_1 QUEST_RESOURCE_2_TILE + RESOURCE_NAME_TILE_WIDTH
#define BAG_TILE_SLOT_2 BAG_TILE_SLOT_1 + RESOURCE_NAME_TILE_WIDTH
DRAW_BKG_ANIMATION_SUFFIX(bg_resource_names_bo7_2, b, BAG_TILE_SLOT_1, ITEMS_ITEMS_X, ITEMS_ROW_7)
DRAW_BKG_ANIMATION_SUFFIX(bg_resource_names_bo7_4, b, BAG_TILE_SLOT_2, ITEMS_ITEMS_X, ITEMS_ROW_8)
DRAW_BKG_ANIMATION_SUFFIX(bg_resource_names_bo7_6, b, BAG_TILE_SLOT_1, ITEMS_ITEMS_X, ITEMS_ROW_7)
DRAW_BKG_ANIMATION_SUFFIX(bg_resource_names_bo7_8, b, BAG_TILE_SLOT_2, ITEMS_ITEMS_X, ITEMS_ROW_8)

// numbers

#define ITEMS_NUMBERS_TILE_START 0
#define ITEMS_NUMBERS_TILE_WIDTH 4

#include "bg_resource_numbers_bo7_1.h"
#include "bg_resource_numbers_bo7_2.h"
#include "bg_resource_numbers_bo7_3.h"
#include "bg_resource_numbers_bo7_4.h"
// #include "bg_resource_numbers_bo7_5.h"
// #include "bg_resource_numbers_bo7_6.h"
// #include "bg_resource_numbers_bo7_7.h"
// #include "bg_resource_numbers_bo7_8.h"
// #include "bg_resource_numbers_bo7_9.h"
// #include "bg_resource_numbers_bo7_10.h"

#define DEFAULT_UNUSED_SPRITE_START 0
struct SpriteData sprite_number_zero = {
    ITEMS_NUMBERS_TILE_START + ITEMS_NUMBERS_TILE_WIDTH * 0,
    DEFAULT_UNUSED_SPRITE_START,
    ICON_W,
    ICON_H,
    bg_resource_numbers_bo7_1_map,
    bg_resource_numbers_bo7_1_tiles,
};
struct SpriteData sprite_number_one = {
    ITEMS_NUMBERS_TILE_START + ITEMS_NUMBERS_TILE_WIDTH * 1,
    DEFAULT_UNUSED_SPRITE_START,
    ICON_W,
    ICON_H,
    bg_resource_numbers_bo7_2_map,
    bg_resource_numbers_bo7_2_tiles,
};
struct SpriteData sprite_number_two = {
    ITEMS_NUMBERS_TILE_START + ITEMS_NUMBERS_TILE_WIDTH * 2,
    DEFAULT_UNUSED_SPRITE_START,
    ICON_W,
    ICON_H,
    bg_resource_numbers_bo7_3_map,
    bg_resource_numbers_bo7_3_tiles,
};
struct SpriteData sprite_number_three = {
    ITEMS_NUMBERS_TILE_START + ITEMS_NUMBERS_TILE_WIDTH * 3,
    DEFAULT_UNUSED_SPRITE_START,
    ICON_W,
    ICON_H,
    bg_resource_numbers_bo7_4_map,
    bg_resource_numbers_bo7_4_tiles,
};
// struct SpriteData sprite_number_four = {
//     ITEMS_NUMBERS_TILE_START + ITEMS_NUMBERS_TILE_WIDTH * 4,
//     DEFAULT_UNUSED_SPRITE_START,
//     ICON_W,
//     ICON_H,
//     bg_resource_numbers_bo7_5_map,
//     bg_resource_numbers_bo7_5_tiles,
// };
// struct SpriteData sprite_number_five = {
//     ITEMS_NUMBERS_TILE_START + ITEMS_NUMBERS_TILE_WIDTH * 5,
//     DEFAULT_UNUSED_SPRITE_START,
//     ICON_W,
//     ICON_H,
//     bg_resource_numbers_bo7_6_map,
//     bg_resource_numbers_bo7_6_tiles,
// };
// struct SpriteData sprite_number_six = {
//     ITEMS_NUMBERS_TILE_START + ITEMS_NUMBERS_TILE_WIDTH * 6,
//     DEFAULT_UNUSED_SPRITE_START,
//     ICON_W,
//     ICON_H,
//     bg_resource_numbers_bo7_7_map,
//     bg_resource_numbers_bo7_7_tiles,
// };
// struct SpriteData sprite_number_seven = {
//     ITEMS_NUMBERS_TILE_START + ITEMS_NUMBERS_TILE_WIDTH * 7,
//     DEFAULT_UNUSED_SPRITE_START,
//     ICON_W,
//     ICON_H,
//     bg_resource_numbers_bo7_8_map,
//     bg_resource_numbers_bo7_8_tiles,
// };
// struct SpriteData sprite_number_eight = {
//     ITEMS_NUMBERS_TILE_START + ITEMS_NUMBERS_TILE_WIDTH * 8,
//     DEFAULT_UNUSED_SPRITE_START,
//     ICON_W,
//     ICON_H,
//     bg_resource_numbers_bo7_9_map,
//     bg_resource_numbers_bo7_9_tiles,
// };
// struct SpriteData sprite_number_nine = {
//     ITEMS_NUMBERS_TILE_START + ITEMS_NUMBERS_TILE_WIDTH * 9,
//     DEFAULT_UNUSED_SPRITE_START,
//     ICON_W,
//     ICON_H,
//     bg_resource_numbers_bo7_10_map,
//     bg_resource_numbers_bo7_10_tiles,
// };

inline void draw_resource_number(enum ItemID resource, uint8_t start_sprite_index, uint8_t bg_row_y)
{
    struct SpriteOpArgs args = {
        148,
        bg_row_y * 8,
    };
    switch (state.item_counts[resource])
    {
    case 0:
        sprite_number_zero.start_sprite_index = start_sprite_index;
        scene_sprite_operation(sprite_number_zero, SpriteOp_SetTile | SpriteOp_Move, args);
        break;
    case 1:
        sprite_number_one.start_sprite_index = start_sprite_index;
        scene_sprite_operation(sprite_number_one, SpriteOp_SetTile | SpriteOp_Move, args);
        break;
    case 2:
        sprite_number_two.start_sprite_index = start_sprite_index;
        scene_sprite_operation(sprite_number_two, SpriteOp_SetTile | SpriteOp_Move, args);
        break;
    case 3:
        sprite_number_three.start_sprite_index = start_sprite_index;
        scene_sprite_operation(sprite_number_three, SpriteOp_SetTile | SpriteOp_Move, args);
        break;
        // case 4:
        //     sprite_number_four.start_sprite_index = start_sprite_index;
        //     scene_sprite_operation(sprite_number_four, SpriteOp_SetTile | SpriteOp_Move, args);
        //     break;
        // case 5:
        //     sprite_number_five.start_sprite_index = start_sprite_index;
        //     scene_sprite_operation(sprite_number_five, SpriteOp_SetTile | SpriteOp_Move, args);
        //     break;
        // case 6:
        //     sprite_number_six.start_sprite_index = start_sprite_index;
        //     scene_sprite_operation(sprite_number_six, SpriteOp_SetTile | SpriteOp_Move, args);
        //     break;
        // case 7:
        //     sprite_number_seven.start_sprite_index = start_sprite_index;
        //     scene_sprite_operation(sprite_number_seven, SpriteOp_SetTile | SpriteOp_Move, args);
        //     break;
        // case 8:
        //     sprite_number_eight.start_sprite_index = start_sprite_index;
        //     scene_sprite_operation(sprite_number_eight, SpriteOp_SetTile | SpriteOp_Move, args);
        //     break;
        // case 9:
        //     sprite_number_nine.start_sprite_index = start_sprite_index;
        //     scene_sprite_operation(sprite_number_nine, SpriteOp_SetTile | SpriteOp_Move, args);
        //     break;
    }
}

void init_number_data()
{
    struct SpriteOpArgs unused = {0, 0};
    scene_sprite_operation(sprite_number_zero, SpriteOp_SetData, unused);
    scene_sprite_operation(sprite_number_one, SpriteOp_SetData, unused);
    scene_sprite_operation(sprite_number_two, SpriteOp_SetData, unused);
    scene_sprite_operation(sprite_number_three, SpriteOp_SetData, unused);
    // scene_sprite_operation(sprite_number_four, SpriteOp_SetData, unused);
    // scene_sprite_operation(sprite_number_five, SpriteOp_SetData, unused);
    // scene_sprite_operation(sprite_number_six, SpriteOp_SetData, unused);
    // scene_sprite_operation(sprite_number_seven, SpriteOp_SetData, unused);
    // scene_sprite_operation(sprite_number_eight, SpriteOp_SetData, unused);
    // scene_sprite_operation(sprite_number_nine, SpriteOp_SetData, unused);
}

void init_bg_bag_screen_bo7(int page)
{
    init_number_data();
    switch (page)
    {
    case 1:
        init_bg_items_screen_text_bo7_1();
        //  recipe 1
        init_bg_resource_names_bo7_1();
        draw_resource_number(ItemID_SpryBerry, ICON_SP_1, ITEMS_ROW_6);
        init_bg_resource_names_bo7_3();
        draw_resource_number(ItemID_LilyStem, ICON_SP_3, ITEMS_ROW_7);
        // recipe 2
        init_bg_resource_names_bo7_4b();
        draw_resource_number(ItemID_PineBark, ICON_SP_2, ITEMS_ROW_8);
        init_bg_resource_names_bo7_2b();
        draw_resource_number(ItemID_RosePetal, ICON_SP_4, ITEMS_ROW_9);
        break;
    case 2:
        init_bg_items_screen_text_bo7_2();
        // recipe 4
        init_bg_resource_names_bo7_5();
        draw_resource_number(ItemID_MossTuft, ICON_SP_1, ITEMS_ROW_6);
        init_bg_resource_names_bo7_7();
        draw_resource_number(ItemID_SnakeSkin, ICON_SP_3, ITEMS_ROW_7);
        // recipe 5
        init_bg_resource_names_bo7_6b();
        draw_resource_number(ItemID_WetLeaf, ICON_SP_2, ITEMS_ROW_8);
        init_bg_resource_names_bo7_8b();
        draw_resource_number(ItemID_FishBones, ICON_SP_4, ITEMS_ROW_9);
        break;
    case 3:
        init_bg_items_screen_text_bo7_3();
        // recipe 6
        init_bg_resource_names_bo7_9();
        draw_resource_number(ItemID_BoneDust, ICON_SP_1, ITEMS_ROW_6);
        init_bg_resource_names_bo7_10();
        draw_resource_number(ItemID_BellFlower, ICON_SP_2, ITEMS_ROW_7);
        break;
        // case 4:
        //     init_bg_items_screen_text_bo7_4();
        //     // potions
        //     init_bg_potion_names_bo7_1();
        //     draw_resource_number(ItemID_LilyPotion, ICON_SP_1, ITEMS_ROW_4);
        //     init_bg_potion_names_bo7_2();
        //     draw_resource_number(ItemID_Fortifier, ICON_SP_2, ITEMS_ROW_5);
        //     init_bg_potion_names_bo7_1();
        //     draw_resource_number(ItemID_EasyRemedy, ICON_SP_1, ITEMS_ROW_6);
        //     init_bg_potion_names_bo7_2();
        //     draw_resource_number(ItemID_GreenFlux, ICON_SP_2, ITEMS_ROW_7);
        //     init_bg_potion_names_bo7_1();
        //     draw_resource_number(ItemID_SimpleWash, ICON_SP_1, ITEMS_ROW_8);
        //     init_bg_potion_names_bo7_2();
        //     draw_resource_number(ItemID_LifeMana, ICON_SP_2, ITEMS_ROW_9);
        //     break;
    }
}