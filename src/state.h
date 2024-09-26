#pragma once
#include <gbdk/platform.h>
#include <time.h>
#include "types.h"
#define COUNT(item) state.item_counts[item]

enum SceneState
{
    SceneState_Uninitialized,
    SceneState_Initialized,
};

enum ItemID required_item_1(enum ItemID to_make);
enum ItemID required_item_2(enum ItemID to_make);
enum ItemID search_location(enum SceneID location);
uint8_t can_craft_potion(enum ItemID potion);
void craft_potion(enum ItemID potion);

struct Quest
{
    enum ItemID item;
    // enum PersonID person;
};
void handle_orchard_delivery_or_story(void);
void handle_river_delivery_or_story(void);
void handle_graveyard_delivery_or_story(void);
void start_quest(uint8_t quest_num);

struct GlobalState
{
    enum SceneID current_scene;
    enum SceneID next_scene;
    enum SceneState scene_state;
    clock_t last_animation;
    uint8_t joypad;
    uint8_t handle_input;
    uint8_t cursor_menu_choice;
    struct Quest quest;
    enum ItemID item_counts[TOAL_ITEMS_IN_GAME];
    enum ItemID last_item_found;
};

extern struct GlobalState state;