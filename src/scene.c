#include "types.h"
#include "scene.h"
#include "scene_title_bo1.h"
#include "scene_intro_cutscene_bo2.h"
#include "scene_intro_cutscene_cont_bo3.h"
#include "scene_elsie_bo4.h"
#include "scene_navigation_menus_bo5.h"
#include "scene_navigation_menus_bo6.h"
#include "scene_navigation_menus_bo7.h"
#include "scene_orchard_bo8.h"
#include "scene_orchard_bo9.h"
#include "scene_orchard_bo10.h"
#include "scene_river_bo11.h"
#include "scene_river_bo12.h"
#include "scene_graveyard_bo13.h"
#include "scene_witch_bo14.h"

// map_x,map_y: (index into map)
// dest_x,dest_y: (tile-level x,y)
// w,h: (tile-level width,height)
// map: map
// map_w: total row width of map array
void scene_set_bkg_submap_fixed(uint8_t map_x,
                                uint8_t map_y,
                                uint8_t dest_x,
                                uint8_t dest_y,
                                uint8_t w,
                                uint8_t h,
                                const uint8_t *map,
                                uint8_t map_w,
                                uint8_t tile_offset)
{
    // uint8_t upper_left = map_x + map_x*map_w;
    for (uint8_t dy = 0; dy < h; dy++)
    {
        uint16_t y_map_offset = map_y + dy * map_w;
        for (uint8_t dx = 0; dx < w; dx++)
        {
            uint8_t x_map_offset = map_x + dx;
            uint16_t idx = x_map_offset + y_map_offset;
            uint8_t tile = map[idx];
            set_bkg_tile_xy(dest_x + dx, dest_y + dy, tile + tile_offset);
        }
    }
    // set_bkg_submap(x,y, w,h, map, map_w);
}

// Note: always will default to 8x16 sprite mode
// -map only exports 8x8 tiles, re-write tile data in 8x16
void scene_sprite_operation(struct SpriteData data, enum SpriteOp op, struct SpriteOpArgs args)
{
    uint8_t tile_to_write = data.start_tile;
    for (uint8_t dy = 0; dy < data.h_tiles_16; dy++)
    {
        uint8_t height_offset = dy * data.w_tiles_8 * 2;
        for (uint8_t dx = 0; dx < data.w_tiles_8; dx++)
        {
            if (op & SpriteOp_SetData)
            {
                // write "top" and "bottom" next to each other
                // bottom is always a "widths" worth forward of tiles, which are 16 elements long
                uint8_t tile = data.tiles_8x8_map[height_offset + dx];
                uint8_t tile_below = data.tiles_8x8_map[height_offset + dx + data.w_tiles_8];
                set_sprite_data(tile_to_write, 1, data.tiles_8x8 + tile * 16);
                set_sprite_data(tile_to_write + 1, 1, data.tiles_8x8 + tile_below * 16);
                tile_to_write += 2;
            }
            uint8_t sp_index = data.start_sprite_index + dy * data.w_tiles_8 + dx;
            if (op & SpriteOp_SetTile)
            {
                set_sprite_tile(sp_index, data.start_tile + dx * 2 + dy * data.w_tiles_8 * 2);
            }
            if (op & SpriteOp_Move)
            {
                move_sprite(sp_index, args.x + dx * 8, args.y + dy * 16);
            }
        }
    }
}

void scene_animation_empty_frame(void) {}

inline void hide_sprites_range_alt(uint8_t start, uint8_t end)
{
    for (uint8_t i = start; i < end; i++)
    {
        hide_sprite(i);
    }
}

enum PersonID current_person;
enum ExpressionID current_expression;
#define UNDISPLAY_SPRITES hide_sprites_range_alt(0, 40);
#define UNDISPLAY_BG_MAP fill_bkg_rect(0, 0, 160 / 8, 144 / 8, 254);
#define UNSET_CHARACTER current_person = PersonID_None;
#define UNSET_EXPRESSION current_expression = ExpressionID_None;
#define UNDISPLAY_ALL UNDISPLAY_SPRITES UNDISPLAY_BG_MAP UNSET_CHARACTER UNSET_EXPRESSION
#define HIDE_ALL  \
    HIDE_SPRITES; \
    SHOW_WIN;
#define ELSIE_CURRENT_PERSON maybe_new_person = PersonID_Elsie;
#define ELSIE_CURRENTLY_THINKING maybe_new_expression = ExpressionID_Thinking;
#define ELSIE_MENU_SCREEN ELSIE_CURRENT_PERSON ELSIE_CURRENTLY_THINKING
void scene_init_current_scene(enum SceneID current_scene)
{
    enum PersonID maybe_new_person = PersonID_None;
    enum ExpressionID maybe_new_expression = ExpressionID_None;
    switch (current_scene)
    {
    case SceneID_None:
        break;
    case SceneID_Title:
        SWITCH_ROM(1);
        init_bg_title_bo1();
        // init_sp_cursor_bo1();
        init_sp_start_bo1();
        break;
    case SceneID_End:
        UNDISPLAY_ALL
        SWITCH_ROM(1);
        init_bg_end_screen_bo1();
        break;
    case SceneID_Home:
        HIDE_ALL;
        UNDISPLAY_ALL
        ELSIE_MENU_SCREEN
        SWITCH_ROM(1);
        init_sp_cursor_bo1();
        SWITCH_ROM(5);
        init_bg_headings_bo5();
        init_sp_icon_craft_bo5();
        init_sp_icon_out_bo5();
        init_sp_icon_quest_bo5(3);
        // init_sp_icon_exclamation_bo5();
        SWITCH_ROM(6);
        init_sp_icon_bag_bo6(4);
        break;
#define INIT_BAG_PAGE(page)           \
    case SceneID_Bag_##page:          \
        HIDE_ALL                      \
        UNDISPLAY_ALL                 \
        SWITCH_ROM(7);                \
        init_bg_bag_screen_bo7(page); \
        break;
        INIT_BAG_PAGE(1)
        INIT_BAG_PAGE(2)
        INIT_BAG_PAGE(3)
    case SceneID_Quest:
        HIDE_ALL
        UNDISPLAY_ALL
        SWITCH_ROM(7);
        init_bg_quest_screen_bo7();
        break;
    case SceneID_CraftFinished:
        HIDE_ALL
        UNDISPLAY_ALL
        SWITCH_ROM(6);
        init_bg_last_potion();
        init_bg_potion_completed_bo6_1();
        break;
#define INIT_CRAFT_POTION(potion_number, potion_item_id) \
    case SceneID_Craft_Potion_##potion_number:           \
        HIDE_ALL                                         \
        UNDISPLAY_ALL                                    \
        SWITCH_ROM(6);                                   \
        init_bg_potion_headers_bo6_##potion_number();    \
        SWITCH_ROM(7);                                   \
        init_bg_quest_screen_text_bo7_2();               \
        init_bg_recipe(potion_item_id, 1);               \
        break;
        INIT_CRAFT_POTION(1, ItemID_LilyPotion)
        INIT_CRAFT_POTION(2, ItemID_Fortifier)
        INIT_CRAFT_POTION(3, ItemID_EasyRemedy)
        INIT_CRAFT_POTION(4, ItemID_GreenFlux)
        INIT_CRAFT_POTION(5, ItemID_SimpleWash)
        INIT_CRAFT_POTION(6, ItemID_LifeMana)
    case SceneID_Path:
        HIDE_ALL;
        UNDISPLAY_ALL
        ELSIE_MENU_SCREEN
        SWITCH_ROM(1);
        init_sp_cursor_bo1();
        SWITCH_ROM(5);
        init_bg_headings_bo5();
        init_sp_icon_home_bo5();
        init_sp_icon_orchard_bo5();
        init_sp_icon_river_bo5();
        init_sp_icon_graveyard_bo5();
        init_sp_icon_quest_bo5(5);
        // init_sp_icon_exclamation_bo5();
        SWITCH_ROM(6);
        init_sp_icon_bag_bo6(6);
        break;
    case SceneID_Orchard:
    case SceneID_River:
    case SceneID_Graveyard:
        HIDE_ALL;
        UNDISPLAY_ALL
        ELSIE_MENU_SCREEN
        SWITCH_ROM(1);
        init_sp_cursor_bo1();
        SWITCH_ROM(5);
        init_sp_icon_out_bo5();
        init_bg_headings_bo5();
        init_sp_icon_quest_bo5(4);
        // init_sp_icon_exclamation_bo5();
        SWITCH_ROM(6);
        init_sp_icon_bag_bo6(5);
        init_sp_icon_search_bo6();
        // init_sp_icon_wait_bo6();
        init_sp_icon_talk_bo6();
        break;
    case SceneID_Orchard_Search:
    case SceneID_River_Search:
    case SceneID_Graveyard_Search:
        HIDE_ALL
        UNDISPLAY_ALL
        SWITCH_ROM(6);
        init_bg_search_result_text_bo6_1();
        SWITCH_ROM(7);
        init_bg_last_item_found_bo7();
        break;
    case SceneID_Orchard_Deliver:
    case SceneID_River_Deliver:
    case SceneID_Graveyard_Deliver:
        HIDE_ALL;
        UNDISPLAY_ALL
        break;
    }
    if (SceneID_IntroCutscene_1 <= current_scene && current_scene <= SceneID_IntroCutscene_14)
    {
        SWITCH_ROM(2);
        intro_ShowText();
        maybe_new_person = intro_CharacterToShow();
        maybe_new_expression = intro_ExpressionToShow();
    }
    else if (SceneID_IntroCutscene_c_1 <= current_scene && current_scene <= SceneID_IntroCutscene_c_16)
    {
        SWITCH_ROM(3);
        intro_cont_ShowText();
        maybe_new_person = intro_cont_CharacterToShow();
        maybe_new_expression = intro_cont_ExpressionToShow();
    }
    else if (SceneID_Orchard_Delivery_1 <= current_scene && current_scene <= SceneID_Orchard_Delivery_15)
    {
        SWITCH_ROM(8);
        orchard_1_ShowText();
        maybe_new_person = orchard_1_CharacterToShow();
        maybe_new_expression = orchard_1_ExpressionToShow();
    }
    else if (SceneID_Orchard_Delivery_2_1 <= current_scene && current_scene <= SceneID_Orchard_Delivery_2_16)
    {
        SWITCH_ROM(9);
        orchard_2_ShowText();
        maybe_new_person = orchard_2_CharacterToShow();
        maybe_new_expression = orchard_2_ExpressionToShow();
    }
    else if (SceneID_Orchard_Delivery_3_1 <= current_scene && current_scene <= SceneID_Orchard_Delivery_3_16)
    {
        SWITCH_ROM(10);
        orchard_3_ShowText();
        maybe_new_person = orchard_3_CharacterToShow();
        maybe_new_expression = orchard_3_ExpressionToShow();
    }
    else if (SceneID_River_Delivery_1_1 <= current_scene && current_scene <= SceneID_River_Delivery_1_13)
    {
        SWITCH_ROM(11);
        river_1_ShowText();
        maybe_new_person = river_1_CharacterToShow();
        maybe_new_expression = river_1_ExpressionToShow();
    }
    else if (SceneID_River_Delivery_2_1 <= current_scene && current_scene <= SceneID_River_Delivery_2_13)
    {
        SWITCH_ROM(12);
        river_2_ShowText();
        maybe_new_person = river_2_CharacterToShow();
        maybe_new_expression = river_2_ExpressionToShow();
    }
    else if (SceneID_Graveyard_Delivery_1_1 <= current_scene && current_scene <= SceneID_Graveyard_Delivery_1_15)
    {
        SWITCH_ROM(13);
        graveyard_1_ShowText();
        maybe_new_person = graveyard_1_CharacterToShow();
        maybe_new_expression = graveyard_1_ExpressionToShow();
    }
    if (maybe_new_person != current_person)
    {
        HIDE_ALL;
        switch (maybe_new_person)
        {
        case PersonID_Elsie:
            ELSIE_BG
            ELSIE_FILL
            INIT_ELSIE_EXPRESSION(maybe_new_expression)
            break;
        case PersonID_WitchNormal:
            UNDISPLAY_SPRITES
            SWITCH_ROM(14);
            WITCH_FILL
            init_bg_witch_normal_bo14();
            break;
        case PersonID_WitchTrollBefore:
        case PersonID_WitchTrollAfter:
            UNDISPLAY_SPRITES
            SWITCH_ROM(14);
            WITCH_FILL
            init_bg_witch_troll_bo14();
            break;
        case PersonID_WitchZombie:
            UNDISPLAY_SPRITES
            SWITCH_ROM(14);
            WITCH_FILL
            init_bg_witch_zombie_bo14();
            break;
        }
    }
    else if (maybe_new_expression != current_expression)
    {
        UNDISPLAY_SPRITES
        switch (current_person)
        {
        case PersonID_Elsie:
            INIT_ELSIE_EXPRESSION(maybe_new_expression)
            break;
        }
    }
    current_person = maybe_new_person;
    current_expression = maybe_new_expression;
    HIDE_WIN;
    SHOW_SPRITES;
}

void scene_tick_all(enum SceneID current_scene)
{
    switch (current_scene)
    {
    case SceneID_Title:
        SWITCH_RAM(1);
        // tick_sp_cursor_bo1();
        break;
    case SceneID_Home:
        SWITCH_ROM(1);
        tick_sp_cursor_bo1();
        SWITCH_ROM(5);
        tick_bg_headings_bo5();
        tick_sp_icon_craft_bo5();
        tick_sp_icon_out_bo5();
        tick_sp_icon_quest_bo5();
        // tick_sp_icon_exclamation_bo5();
        break;
    case SceneID_Path:
        SWITCH_ROM(1);
        tick_sp_cursor_bo1();
        SWITCH_ROM(5);
        tick_bg_headings_bo5();
        tick_sp_icon_home_bo5();
        tick_sp_icon_orchard_bo5();
        tick_sp_icon_river_bo5();
        tick_sp_icon_graveyard_bo5();
        tick_sp_icon_quest_bo5();
        // tick_sp_icon_exclamation_bo5();
        break;
    case SceneID_Orchard:
    case SceneID_River:
    case SceneID_Graveyard:
        SWITCH_ROM(1);
        tick_sp_cursor_bo1();
        SWITCH_ROM(5);
        tick_bg_headings_bo5();
        tick_sp_icon_out_bo5();
        SWITCH_ROM(6);
        tick_sp_icon_search_bo6();
        // tick_sp_icon_wait_bo6();
        tick_sp_icon_talk_bo6();
        break;
    }
    if (current_person != PersonID_None)
    {
        switch (current_person)
        {
        case PersonID_Elsie:
            ELSIE_BANK;
            switch (current_expression)
            {
            case ExpressionID_Smile:
                tick_sp_elsie_smile_bo4();
                break;
            case ExpressionID_Ecstatic:
                tick_sp_elsie_ecstatic_bo4();
                break;
            case ExpressionID_Thinking:
                tick_sp_elsie_thinking_bo4();
                break;
            case ExpressionID_Dreaming:
                tick_sp_elsie_dreaming_bo4();
                break;
            case ExpressionID_Sigh:
                tick_sp_elsie_sigh_bo4();
                break;
            case ExpressionID_Surprised:
                break;
            case ExpressionID_Reading:
                tick_sp_elsie_reading_bo4();
                break;
            }
            break;
        }
    }
}