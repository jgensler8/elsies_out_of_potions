#include "state.h"
#include <rand.h>
struct GlobalState state;

enum ItemID required_item_1(enum ItemID to_make)
{
    switch (to_make)
    {
    // Orchard
    case ItemID_LilyPotion:
    case ItemID_EasyRemedy:
        return ItemID_SpryBerry;
    case ItemID_Fortifier:
        return ItemID_PineBark;
    // River
    case ItemID_GreenFlux:
        return ItemID_MossTuft;
    case ItemID_SimpleWash:
        return ItemID_WetLeaf;
    // Graveyard
    case ItemID_LifeMana:
        return ItemID_BoneDust;
    }
    return ItemID_None;
}
enum ItemID required_item_2(enum ItemID to_make)
{
    switch (to_make)
    {
    // Orchard
    case ItemID_LilyPotion:
        return ItemID_LilyStem;
    case ItemID_Fortifier:
    case ItemID_EasyRemedy:
        return ItemID_RosePetal;
    // River
    case ItemID_GreenFlux:
        return ItemID_SnakeSkin;
    case ItemID_SimpleWash:
        return ItemID_FishBones;
    // Graveyard
    case ItemID_LifeMana:
        return ItemID_BellFlower;
    }
    return ItemID_None;
}

void handle_orchard_delivery_or_story(void)
{
    if (state.quest.item == ItemID_LilyPotion && COUNT(state.quest.item) > 0)
    {
        // first quest
        state.next_scene = SceneID_Orchard_Delivery_3;
    }
    else if (state.quest.item == ItemID_Fortifier && COUNT(state.quest.item) > 0)
    {
        // second quest
        state.next_scene = SceneID_Orchard_Delivery_2_1;
    }
    else if (state.quest.item == ItemID_EasyRemedy && COUNT(state.quest.item) > 0)
    {
        // third quest
        state.next_scene = SceneID_Orchard_Delivery_3_1;
    }
    else
    {
        // send them back
        state.next_scene = SceneID_Orchard;
    }
}
void handle_river_delivery_or_story(void)
{
    if (state.quest.item == ItemID_GreenFlux && COUNT(state.quest.item) > 0)
    {
        // first quest
        state.next_scene = SceneID_River_Delivery_1_1;
    }
    else if (state.quest.item == ItemID_SimpleWash && COUNT(state.quest.item) > 0)
    {
        // second quest
        state.next_scene = SceneID_River_Delivery_2_1;
    }
    else
    {
        state.next_scene = SceneID_River;
    }
}
void handle_graveyard_delivery_or_story(void)
{
    if (state.quest.item == ItemID_LifeMana && COUNT(state.quest.item) > 0)
    {
        state.next_scene = SceneID_Graveyard_Delivery_1_1;
    }
    else
    {
        // send them back
        state.next_scene = SceneID_Graveyard;
    }
}

void start_quest(uint8_t quest_num)
{
    switch (quest_num)
    {
    case 1:
        // state.quest.person = PersonID_WitchOfTheWoods;
        state.quest.item = ItemID_LilyPotion;
        break;
    case 2:
        // state.quest.person = PersonID_WitchOfTheWoods;
        state.quest.item = ItemID_Fortifier;
        break;
    case 3:
        // state.quest.person = PersonID_WitchOfTheWoods;
        state.quest.item = ItemID_EasyRemedy;
        break;
    case 4:
        // state.quest.person = PersonID_RiverTroll;
        state.quest.item = ItemID_GreenFlux;
        break;
    case 5:
        // state.quest.person = PersonID_RiverTroll;
        state.quest.item = ItemID_SimpleWash;
        break;
    case 6:
        // state.quest.person = PersonID_Zombie;
        state.quest.item = ItemID_LifeMana;
        break;
    }
}

#define HALF 128
#define QUARTER 64
#define EIGHTH 32
#define SHRINK(item) (quarter / state.item_counts[item])
inline uint8_t adjust(enum ItemID item)
{
    uint16_t modifier = (QUARTER + EIGHTH);
    modifier = modifier * COUNT(item) / ITEM_COUNT_MAX;
    return HALF - modifier;
}
// not quite working perfectly
inline uint8_t friendly_pull(enum ItemID item)
{
    uint8_t pull = rand();
    if (pull < adjust(item))
    {
        return 1;
    }
    return 0;
}
uint16_t last_seed = 1;
enum ItemID search_location(enum SceneID location)
{
    // TODO: maybe change this later
    uint16_t seed = clock();
    initarand(seed * last_seed);
    last_seed = seed;
    switch (location)
    {
    case SceneID_Orchard:
        if (friendly_pull(ItemID_SpryBerry) > 0)
            return ItemID_SpryBerry;
        else if (friendly_pull(ItemID_PineBark) > 0)
            return ItemID_PineBark;
        else if (friendly_pull(ItemID_LilyStem) > 0)
            return ItemID_LilyStem;
        else
            return ItemID_RosePetal;
    case SceneID_River:
        if (friendly_pull(ItemID_MossTuft > 0))
            return ItemID_MossTuft;
        else if (friendly_pull(ItemID_WetLeaf) > 0)
            return ItemID_WetLeaf;
        else if (friendly_pull(ItemID_SnakeSkin) > 0)
            return ItemID_SnakeSkin;
        else
            return ItemID_FishBones;
    case SceneID_Graveyard:
        if (friendly_pull(ItemID_BoneDust))
            return ItemID_BoneDust;
        else
            return ItemID_BellFlower;
    }
    return ItemID_None;
}

uint8_t can_craft_potion(enum ItemID potion)
{
    return COUNT(required_item_1(potion)) > 0 && COUNT(required_item_2(potion)) > 0;
}

void craft_potion(enum ItemID potion)
{
    if (!can_craft_potion(potion))
    {
        return;
    }
    state.item_counts[required_item_1(potion)] -= 1;
    state.item_counts[required_item_2(potion)] -= 1;
    state.item_counts[potion] += 1;
    state.last_item_found = potion;
}