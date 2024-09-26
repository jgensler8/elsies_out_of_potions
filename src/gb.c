#include "state.h"
#include "scene.h"
#include <rand.h>

#define UPDATE_LAST_INPUT state.handle_input = 0;
#define BUTTONS (state.joypad | joypad())
#define START_PRESSED (BUTTONS & J_START)
#define SELECT_PRESSED (BUTTONS & J_SELECT)
#define A_PRESSED (BUTTONS & J_A)
#define B_PRESSED (BUTTONS & J_B)
#define UP_PRESSED (BUTTONS & J_UP)
#define LEFT_PRESSED (BUTTONS & J_LEFT)
#define UP_PRESSED (BUTTONS & J_UP)
#define DOWN_PRESSED (BUTTONS & J_DOWN)
#define RIGHT_PRESSED (BUTTONS & J_RIGHT)

#define RESET_CURSOR state.cursor_menu_choice = 0;
#define HANDLE_A(next)           \
    if (A_PRESSED)               \
    {                            \
        state.next_scene = next; \
    }
#define HANDLE_B(next)           \
    if (B_PRESSED)               \
    {                            \
        state.next_scene = next; \
    }
#define HANDLE_LEFT(next)        \
    if (LEFT_PRESSED)            \
    {                            \
        state.next_scene = next; \
    }
#define HANDLE_RIGHT(next)       \
    if (RIGHT_PRESSED)           \
    {                            \
        state.next_scene = next; \
    }
#define HANDLE_UP(next)          \
    if (UP_PRESSED)              \
    {                            \
        state.next_scene = next; \
    }
#define HANDLE_DOWN(next)        \
    if (DOWN_PRESSED)            \
    {                            \
        state.next_scene = next; \
    }

inline uint8_t min(uint8_t a, uint8_t b)
{
    if (a < b)
    {
        return a;
    }
    return b;
}

inline uint8_t max(uint8_t a, uint8_t b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

inline uint8_t clamp(uint8_t x, uint8_t lo, uint8_t hi)
{
    return max(min(x, hi), lo);
}

// stack of size one
enum SceneID scene_stack;
#define HANDLE_SCENE_STACK_POP HANDLE_B(scene_stack)

inline void handle_sequence(uint8_t num_choices, enum SceneID choices[])
{
    if (UP_PRESSED || LEFT_PRESSED)
    {
        if (state.cursor_menu_choice > 0)
        {
            state.cursor_menu_choice -= 1;
        }
        UPDATE_LAST_INPUT
    }
    else if (DOWN_PRESSED || RIGHT_PRESSED)
    {
        state.cursor_menu_choice = min(state.cursor_menu_choice + 1, num_choices - 1);
        UPDATE_LAST_INPUT
    }
    if (A_PRESSED)
    {
        enum SceneID next = choices[state.cursor_menu_choice];
        if (next == SceneID_Bag_1 || next == SceneID_Bag_2 || next == SceneID_Bag_3 || next == SceneID_Quest)
        {
            scene_stack = state.current_scene;
        }
        state.next_scene = next;
        UPDATE_LAST_INPUT
    }
}
#define HANDLE_SEQUENCE(option_name, num_options, ...) \
    enum SceneID option_name[] = {__VA_ARGS__};        \
    handle_sequence(num_options, option_name);

inline void handle_input(void)
{
    switch (state.current_scene)
    {
    case SceneID_Title:
        if (START_PRESSED || A_PRESSED)
        {
            uint16_t seed = clock();
            initarand(seed);
            state.next_scene = SceneID_IntroCutscene_1;
            UPDATE_LAST_INPUT
        }
        break;
    case SceneID_Home:
        HANDLE_SEQUENCE(home, 4, SceneID_Path, SceneID_Craft_Potion_1, SceneID_Quest, SceneID_Bag_1)
        break;
    case SceneID_Quest:
        HANDLE_SCENE_STACK_POP
        break;
#define BAG_INPUT_CASE(page, left, right) \
    case SceneID_Bag_##page:              \
        HANDLE_LEFT(SceneID_Bag_##left)   \
        HANDLE_UP(SceneID_Bag_##left)     \
        HANDLE_RIGHT(SceneID_Bag_##right) \
        HANDLE_DOWN(SceneID_Bag_##right)  \
        HANDLE_SCENE_STACK_POP            \
        break;
        BAG_INPUT_CASE(1, 3, 2)
        BAG_INPUT_CASE(2, 1, 3)
        BAG_INPUT_CASE(3, 2, 1)
    case SceneID_CraftFinished:
        HANDLE_A(SceneID_Home)
        HANDLE_B(SceneID_Home)
        break;
#define INPUT_CRAFT_POTION(potion_number, potion_item_id, potion_number_left, potion_number_right) \
    case SceneID_Craft_Potion_##potion_number:                                                     \
        HANDLE_B(SceneID_Home)                                                                     \
        HANDLE_LEFT(SceneID_Craft_Potion_##potion_number_left)                                     \
        HANDLE_RIGHT(SceneID_Craft_Potion_##potion_number_right)                                   \
        if (A_PRESSED && can_craft_potion(potion_item_id))                                         \
        {                                                                                          \
            craft_potion(potion_item_id);                                                          \
            state.next_scene = SceneID_CraftFinished;                                              \
        }                                                                                          \
        break;
        INPUT_CRAFT_POTION(1, ItemID_LilyPotion, 6, 2)
        INPUT_CRAFT_POTION(2, ItemID_Fortifier, 1, 3)
        INPUT_CRAFT_POTION(3, ItemID_EasyRemedy, 2, 4)
        INPUT_CRAFT_POTION(4, ItemID_GreenFlux, 3, 5)
        INPUT_CRAFT_POTION(5, ItemID_SimpleWash, 4, 6)
        INPUT_CRAFT_POTION(6, ItemID_LifeMana, 5, 1)
    case SceneID_Path:
        HANDLE_SEQUENCE(path, 6, SceneID_Home, SceneID_Orchard, SceneID_River, SceneID_Graveyard, SceneID_Quest, SceneID_Bag_1)
        break;
#define HANDLE_SEARCH(search_scene, location)                                                                         \
    if (state.next_scene == search_scene)                                                                             \
    {                                                                                                                 \
        state.last_item_found = search_location(location);                                                            \
        state.item_counts[state.last_item_found] = min(state.item_counts[state.last_item_found] + 1, ITEM_COUNT_MAX); \
    }
    case SceneID_Orchard:
        HANDLE_SEQUENCE(orchard, 5, SceneID_Path, SceneID_Orchard_Search, SceneID_Orchard_Deliver, SceneID_Quest, SceneID_Bag_1)
        HANDLE_SEARCH(SceneID_Orchard_Search, SceneID_Orchard)
        break;
    case SceneID_Orchard_Search:
        HANDLE_A(SceneID_Orchard)
        break;
    case SceneID_Orchard_Deliver:
        handle_orchard_delivery_or_story();
        UPDATE_LAST_INPUT
        break;
    case SceneID_River:
        HANDLE_SEQUENCE(river, 5, SceneID_Path, SceneID_River_Search, SceneID_River_Deliver, SceneID_Quest, SceneID_Bag_1)
        HANDLE_SEARCH(SceneID_River_Search, SceneID_River)
        break;
    case SceneID_River_Search:
        HANDLE_A(SceneID_River)
        break;
    case SceneID_River_Deliver:
        handle_river_delivery_or_story();
        UPDATE_LAST_INPUT
        break;
    case SceneID_Graveyard:
        HANDLE_SEQUENCE(graveyard, 5, SceneID_Path, SceneID_Graveyard_Search, SceneID_Graveyard_Deliver, SceneID_Quest, SceneID_Bag_1)
        HANDLE_SEARCH(SceneID_Graveyard_Search, SceneID_Graveyard)
        break;
    case SceneID_Graveyard_Search:
        HANDLE_A(SceneID_Graveyard)
        break;
    case SceneID_Graveyard_Deliver:
        handle_graveyard_delivery_or_story();
        UPDATE_LAST_INPUT
        break;
#define STORY_NEXT(next)         \
    if A_PRESSED                 \
    {                            \
        state.next_scene = next; \
        UPDATE_LAST_INPUT        \
    }                            \
    break;
#define STORY_CASE(at, next) \
    case at:                 \
        STORY_NEXT(next)
#define INTRO_CUTSCENE_CASE(at_num, next_num) STORY_CASE(SceneID_IntroCutscene_##at_num, SceneID_IntroCutscene_##next_num)
        INTRO_CUTSCENE_CASE(1, 2)
        INTRO_CUTSCENE_CASE(2, 3)
        INTRO_CUTSCENE_CASE(3, 4)
        INTRO_CUTSCENE_CASE(4, 5)
        INTRO_CUTSCENE_CASE(5, 6)
        INTRO_CUTSCENE_CASE(6, 7)
        INTRO_CUTSCENE_CASE(7, 8)
        INTRO_CUTSCENE_CASE(8, 9)
        INTRO_CUTSCENE_CASE(9, 10)
        INTRO_CUTSCENE_CASE(10, 11)
        INTRO_CUTSCENE_CASE(11, 12)
        INTRO_CUTSCENE_CASE(12, 13)
        INTRO_CUTSCENE_CASE(13, 14)
        STORY_CASE(SceneID_IntroCutscene_14, SceneID_IntroCutscene_c_1)
#define INTRO_CUTSCENE_C_CASE(at_num, next_num) STORY_CASE(SceneID_IntroCutscene_c_##at_num, SceneID_IntroCutscene_c_##next_num)
        INTRO_CUTSCENE_C_CASE(1, 2)
        INTRO_CUTSCENE_C_CASE(2, 3)
        INTRO_CUTSCENE_C_CASE(3, 4)
        INTRO_CUTSCENE_C_CASE(4, 5)
        INTRO_CUTSCENE_C_CASE(5, 6)
        INTRO_CUTSCENE_C_CASE(6, 7)
        INTRO_CUTSCENE_C_CASE(7, 8)
        INTRO_CUTSCENE_C_CASE(8, 9)
        INTRO_CUTSCENE_C_CASE(9, 10)
        INTRO_CUTSCENE_C_CASE(10, 11)
        INTRO_CUTSCENE_C_CASE(11, 12)
        INTRO_CUTSCENE_C_CASE(12, 13)
        INTRO_CUTSCENE_C_CASE(13, 14)
        INTRO_CUTSCENE_C_CASE(14, 15)
        INTRO_CUTSCENE_C_CASE(15, 16)
    case SceneID_IntroCutscene_c_16:
        start_quest(1);
        STORY_NEXT(SceneID_Home)
#define ORCHARD_DELIVERY_1_CASE(at_num, next_num) STORY_CASE(SceneID_Orchard_Delivery_##at_num, SceneID_Orchard_Delivery_##next_num)
        // try to deliver without potion
        ORCHARD_DELIVERY_1_CASE(1, 2)
        STORY_CASE(SceneID_Orchard_Delivery_2, SceneID_Orchard)
        // try to deliver with potion
        ORCHARD_DELIVERY_1_CASE(3, 4)
        ORCHARD_DELIVERY_1_CASE(4, 5)
        ORCHARD_DELIVERY_1_CASE(5, 6)
        ORCHARD_DELIVERY_1_CASE(6, 7)
        ORCHARD_DELIVERY_1_CASE(7, 8)
        ORCHARD_DELIVERY_1_CASE(8, 9)
        ORCHARD_DELIVERY_1_CASE(9, 10)
        ORCHARD_DELIVERY_1_CASE(10, 11)
        ORCHARD_DELIVERY_1_CASE(11, 12)
        ORCHARD_DELIVERY_1_CASE(12, 13)
        ORCHARD_DELIVERY_1_CASE(13, 14)
        ORCHARD_DELIVERY_1_CASE(14, 15)
    case SceneID_Orchard_Delivery_15:
        start_quest(2);
        STORY_NEXT(SceneID_Orchard)
#define ORCHARD_DELIVERY_2_CASE(at_num, next_num) STORY_CASE(SceneID_Orchard_Delivery_2_##at_num, SceneID_Orchard_Delivery_2_##next_num)
        ORCHARD_DELIVERY_2_CASE(1, 2)
        ORCHARD_DELIVERY_2_CASE(2, 3)
        ORCHARD_DELIVERY_2_CASE(3, 4)
        ORCHARD_DELIVERY_2_CASE(4, 5)
        ORCHARD_DELIVERY_2_CASE(5, 6)
        ORCHARD_DELIVERY_2_CASE(6, 7)
        ORCHARD_DELIVERY_2_CASE(7, 8)
        ORCHARD_DELIVERY_2_CASE(8, 9)
        ORCHARD_DELIVERY_2_CASE(9, 10)
        ORCHARD_DELIVERY_2_CASE(10, 11)
        ORCHARD_DELIVERY_2_CASE(11, 12)
        ORCHARD_DELIVERY_2_CASE(12, 13)
        ORCHARD_DELIVERY_2_CASE(13, 14)
        ORCHARD_DELIVERY_2_CASE(14, 15)
        ORCHARD_DELIVERY_2_CASE(15, 16)
    case SceneID_Orchard_Delivery_2_16:
        start_quest(3);
        STORY_NEXT(SceneID_Orchard)
#define ORCHARD_DELIVERY_3_CASE(at_num, next_num) STORY_CASE(SceneID_Orchard_Delivery_3_##at_num, SceneID_Orchard_Delivery_3_##next_num)
        ORCHARD_DELIVERY_3_CASE(1, 2)
        ORCHARD_DELIVERY_3_CASE(2, 3)
        ORCHARD_DELIVERY_3_CASE(3, 4)
        ORCHARD_DELIVERY_3_CASE(4, 5)
        ORCHARD_DELIVERY_3_CASE(5, 6)
        ORCHARD_DELIVERY_3_CASE(6, 7)
        ORCHARD_DELIVERY_3_CASE(7, 8)
        ORCHARD_DELIVERY_3_CASE(8, 9)
        ORCHARD_DELIVERY_3_CASE(9, 10)
        ORCHARD_DELIVERY_3_CASE(10, 11)
        ORCHARD_DELIVERY_3_CASE(11, 12)
        ORCHARD_DELIVERY_3_CASE(12, 13)
        ORCHARD_DELIVERY_3_CASE(13, 14)
        ORCHARD_DELIVERY_3_CASE(14, 15)
        ORCHARD_DELIVERY_3_CASE(15, 16)
    case SceneID_Orchard_Delivery_3_16:
        start_quest(4);
        STORY_NEXT(SceneID_Orchard)
#define RIVER_DELIVERY_1_CASE(at_num, next_num) STORY_CASE(SceneID_River_Delivery_1_##at_num, SceneID_River_Delivery_1_##next_num)
        RIVER_DELIVERY_1_CASE(1, 2)
        RIVER_DELIVERY_1_CASE(2, 3)
        RIVER_DELIVERY_1_CASE(3, 4)
        RIVER_DELIVERY_1_CASE(4, 5)
        RIVER_DELIVERY_1_CASE(5, 6)
        RIVER_DELIVERY_1_CASE(6, 7)
        RIVER_DELIVERY_1_CASE(7, 8)
        RIVER_DELIVERY_1_CASE(8, 9)
        RIVER_DELIVERY_1_CASE(9, 10)
        RIVER_DELIVERY_1_CASE(10, 11)
        RIVER_DELIVERY_1_CASE(11, 12)
        RIVER_DELIVERY_1_CASE(12, 13)
    case SceneID_River_Delivery_1_13:
        start_quest(5);
        STORY_NEXT(SceneID_River)
#define RIVER_DELIVERY_2_CASE(at_num, next_num) STORY_CASE(SceneID_River_Delivery_2_##at_num, SceneID_River_Delivery_2_##next_num)
        RIVER_DELIVERY_2_CASE(1, 2)
        RIVER_DELIVERY_2_CASE(2, 3)
        RIVER_DELIVERY_2_CASE(3, 4)
        RIVER_DELIVERY_2_CASE(4, 5)
        RIVER_DELIVERY_2_CASE(5, 6)
        RIVER_DELIVERY_2_CASE(6, 7)
        RIVER_DELIVERY_2_CASE(7, 8)
        RIVER_DELIVERY_2_CASE(8, 9)
        RIVER_DELIVERY_2_CASE(9, 10)
        RIVER_DELIVERY_2_CASE(10, 11)
        RIVER_DELIVERY_2_CASE(11, 12)
        RIVER_DELIVERY_2_CASE(12, 13)
    case SceneID_River_Delivery_2_13:
        start_quest(6);
        STORY_NEXT(SceneID_River)
#define GRAVEYARD_DELIVERY_1_CASE(at_num, next_num) STORY_CASE(SceneID_Graveyard_Delivery_1_##at_num, SceneID_Graveyard_Delivery_1_##next_num)
        GRAVEYARD_DELIVERY_1_CASE(1, 2)
        GRAVEYARD_DELIVERY_1_CASE(2, 3)
        GRAVEYARD_DELIVERY_1_CASE(3, 4)
        GRAVEYARD_DELIVERY_1_CASE(4, 5)
        GRAVEYARD_DELIVERY_1_CASE(5, 6)
        GRAVEYARD_DELIVERY_1_CASE(6, 7)
        GRAVEYARD_DELIVERY_1_CASE(7, 8)
        GRAVEYARD_DELIVERY_1_CASE(8, 9)
        GRAVEYARD_DELIVERY_1_CASE(9, 10)
        GRAVEYARD_DELIVERY_1_CASE(10, 11)
        GRAVEYARD_DELIVERY_1_CASE(11, 12)
        GRAVEYARD_DELIVERY_1_CASE(12, 13)
        GRAVEYARD_DELIVERY_1_CASE(13, 14)
        GRAVEYARD_DELIVERY_1_CASE(14, 15)
    case SceneID_Graveyard_Delivery_1_15:
        STORY_NEXT(SceneID_End)
    default:
        break;
    }
}

// initially created to handle button irq handling
inline void reset_input(void)
{
    state.joypad = 0;
}

inline void render_current_scene(void)
{
    if (state.scene_state == SceneState_Uninitialized)
    {
        scene_init_current_scene(state.current_scene);
        state.scene_state = SceneState_Initialized;
    }
    if (state.next_scene != SceneID_None)
    {
        state.current_scene = state.next_scene;
        state.next_scene = SceneID_None;
        state.scene_state = SceneState_Uninitialized;
        return;
    }
    // handle input
    if (BUTTONS == 0)
    {
        state.handle_input = 1;
    }
    if (state.handle_input)
    {
        handle_input();
    }
    reset_input();
    scene_tick_all(state.current_scene);
}

// TODO: currently not handling interrupts
void handle_joypad(void)
{
    // state.joypad |= joypad();
    state.joypad = J_A;
}

void main(void)
{
    // initialize_sound();
    add_JOY(handle_joypad);
    SPRITES_8x16;
    SHOW_SPRITES;
    // TODO: experiment with other tiles (this should be the last one available for bg tiles)
    init_win(255);
    // TODO: maybe replace with other colors
    set_default_palette();
    const palette_color_t gb_pal[] = {RGB(0xff, 0xff, 0xff), 0x3306, 0x11c2, 0x8d42};
    set_bkg_palette(BKGF_CGB_PAL0, 1, gb_pal);
    set_sprite_palette(0, 1, gb_pal);
    state.current_scene = SceneID_Title;
    // state.current_scene = SceneID_Home;
    // state.current_scene = SceneID_Orchard;
    // state.current_scene = SceneID_River;
    // state.current_scene = SceneID_Graveyard;
    state.next_scene = SceneID_None;
    // state.quest.person = PersonID_WitchOfTheWoods;
    // state.quest.person = PersonID_RiverTroll;
    // state.quest.person = PersonID_Zombie;
    state.quest.item = ItemID_None;
    // state.quest.item = ItemID_LilyPotion;
    // state.quest.item = ItemID_Fortifier;
    // state.quest.item = ItemID_EasyRemedy;
    // state.quest.item = ItemID_GreenFlux;
    // state.quest.item = ItemID_SimpleWash;
    // state.quest.item = ItemID_LifeMana;
    // resources
    // state.item_counts[ItemID_SpryBerry] = 0;
    // state.item_counts[ItemID_PineBark] = 2;
    // state.item_counts[ItemID_LilyStem] = 1;
    // state.item_counts[ItemID_RosePetal] = 3;
    // potions
    // state.item_counts[ItemID_LilyPotion] = ITEM_COUNT_MAX;
    // state.item_counts[ItemID_Fortifier] = ITEM_COUNT_MAX;
    // state.item_counts[ItemID_EasyRemedy] = ITEM_COUNT_MAX;
    // state.item_counts[ItemID_GreenFlux] = ITEM_COUNT_MAX;
    // state.item_counts[ItemID_SimpleWash] = ITEM_COUNT_MAX;
    // state.item_counts[ItemID_LifeMana] = ITEM_COUNT_MAX;
    while (1)
    {
        wait_vbl_done();
        // hUGE_dosound();
        render_current_scene();
        // vsync();
        // delay(50);
    }
}