#pragma once
#include "scene.h"
#include "types.h"

SCENE_BKG_HEADER(bg_quest_screen_bo7)
void init_bg_last_item_found_bo7(void);
void init_bg_bag_screen_bo7(int page);
void init_bg_potion_name(enum ItemID potion);
SCENE_BKG_HEADER(bg_quest_screen_text_bo7_3)
void init_bg_recipe(enum ItemID recipe, uint8_t draw_numbers);