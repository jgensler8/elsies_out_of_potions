#pragma once
#include <gbdk/platform.h>
#include <time.h>

#define ICON_SP_1 26
#define ICON_DATA_1 66
#define ICON_SP_2 ICON_SP_1 + 2
#define ICON_DATA_2 ICON_DATA_1 + 4
#define ICON_SP_3 ICON_SP_2 + 2
#define ICON_DATA_3 ICON_DATA_2 + 4
#define ICON_SP_4 ICON_SP_3 + 2
#define ICON_DATA_4 ICON_DATA_3 + 4
#define ICON_SP_5 ICON_SP_4 + 2
#define ICON_DATA_5 ICON_DATA_4 + 4
#define ICON_SP_6 ICON_SP_5 + 2
#define ICON_DATA_6 ICON_DATA_5 + 4
#define ICON_SP_7 ICON_SP_6 + 2
#define ICON_DATA_7 ICON_DATA_6 + 4
// #define ICON_SP_8 ICON_SP_7 + 2
// #define ICON_DATA_8 ICON_DATA_7 + 4
// #define ICON_SP_9 ICON_SP_8 + 2
// #define ICON_DATA_9 ICON_DATA_8 + 4
// #define ICON_SP_10 ICON_SP_9 + 2
// #define ICON_DATA_10 ICON_DATA_9 + 4
// #define ICON_SP_11 ICON_SP_10 + 2
// #define ICON_DATA_11 ICON_DATA_10 + 4
// #define ICON_SP_12 ICON_SP_11 + 2
// #define ICON_DATA_12 ICON_DATA_11 + 4
// args
#define ICON_W 2
#define ICON_H 1
#define ICON_UPPER_RIGHT_x 144 + 8
#define ICON_UPPER_RIGHT_y_1 0 + 16
#define ICON_UPPER_RIGHT_y_2 ICON_UPPER_RIGHT_y_1 + 16
#define ICON_COLUMN_1 124 + 8
#define ICON_COLUMN_2 ICON_COLUMN_1 + 16
#define ICON_ROW_SPACING 16
#define ICON_ROW_1 42 + 16
#define ICON_ROW_2 ICON_ROW_1 + ICON_ROW_SPACING
#define ICON_ROW_3 ICON_ROW_2 + ICON_ROW_SPACING
#define ICON_ROW_4 ICON_ROW_3 + ICON_ROW_SPACING
#define ICON_ROW_5 ICON_ROW_4 + ICON_ROW_SPACING
#define ICON_ROW_6 ICON_ROW_5 + ICON_ROW_SPACING

#define ANIMATION_INTERVAL_MS 100
// should be 60 clocks per second so 1000 / 60 = 16.6 ms per clock
#define MS_PER_CLOCK (1000 / CLOCKS_PER_SEC)
#define ANIMATION_INTERVAL_CLOCKS (ANIMATION_INTERVAL_MS / MS_PER_CLOCK)
#define INPUT_INTERVAL_CLOCKS 20
// #define ANIMATION_INTERVAL_CLOCKS 5
#define DEFAULT_TICKS_PER_FRAME 1
#define INIT_TICKS DEFAULT_TICKS_PER_FRAME
struct animation
{
    uint8_t current_frame;
    uint8_t total_frames;
    uint8_t ticks_left;
    clock_t last_frame;
    // uint8_t ticks_per_frame;
};
#define EMPTY_FRAME scene_animation_empty_frame
#define EMPTY_INIT_FRAME_4 EMPTY_FRAME, EMPTY_FRAME, EMPTY_FRAME, EMPTY_FRAME
#define EMPTY_INIT_FRAME_16 EMPTY_INIT_FRAME_4, EMPTY_INIT_FRAME_4, EMPTY_INIT_FRAME_4, EMPTY_INIT_FRAME_4
#define EMPTY_INIT_FRAMES {EMPTY_INIT_FRAME_16, EMPTY_INIT_FRAME_16}
#define EMPTY_DRAW_FRAME_4 EMPTY_FRAME, EMPTY_FRAME, EMPTY_FRAME, EMPTY_FRAME
#define EMPTY_DRAW_FRAME_16 EMPTY_DRAW_FRAME_4, EMPTY_DRAW_FRAME_4, EMPTY_DRAW_FRAME_4, EMPTY_DRAW_FRAME_4
#define EMPTY_DRAW_FRAMES {EMPTY_DRAW_FRAME_16, EMPTY_DRAW_FRAME_16}

//
// scene.c API
//
struct SpriteData
{
    uint8_t start_tile;
    uint8_t start_sprite_index;
    uint8_t w_tiles_8;
    uint8_t h_tiles_16;
    uint8_t *tiles_8x8_map;
    uint8_t *tiles_8x8;
};
enum SpriteOp
{
    SpriteOp_SetData = 1,
    SpriteOp_SetTile = 2,
    SpriteOp_Move = 4,
};
struct SpriteOpArgs
{
    uint8_t x;
    uint8_t y;
};
extern void scene_animation_empty_frame(void);
extern void scene_init_current_scene(enum SceneID current_scene);
extern void scene_tick_all(enum SceneID current_scene);
extern void scene_set_bkg_submap_fixed(uint8_t map_x,
                                       uint8_t map_y,
                                       uint8_t dest_x,
                                       uint8_t dest_y,
                                       uint8_t w,
                                       uint8_t h,
                                       const uint8_t *map,
                                       uint8_t map_w,
                                       uint8_t tile_offset);
void scene_sprite_operation(struct SpriteData data, enum SpriteOp op, struct SpriteOpArgs args);
//
// scene includes
//

#define SCENE_BKG_HEADER(ident) \
    void init_##ident(void);

#define SCENE_SPRITE_HEADER(ident) \
    void init_##ident(void);       \
    void tick_##ident(void);

#define DRAW_BKG_ANIMATION_SUFFIX(ident, suffix, first_tile, x_tile, y_tile)                                                                 \
    void init_##ident##suffix(void)                                                                                                          \
    {                                                                                                                                        \
        set_bkg_data(first_tile, ident##_TILE_COUNT, ident##_tiles);                                                                         \
        /*set_bkg_tiles(x_tile,y_tile, w,h, ident##_map);*/                                                                                  \
        scene_set_bkg_submap_fixed(0, 0, x_tile, y_tile, ident##_WIDTH / 8, ident##_HEIGHT / 8, ident##_map, ident##_WIDTH / 8, first_tile); \
    }                                                                                                                                        \
    void draw_##ident##suffix(void) {}
#define DRAW_BKG_ANIMATION(ident, first_tile, x_tile, y_tile)                                                                                \
    void init_##ident(void)                                                                                                                  \
    {                                                                                                                                        \
        set_bkg_data(first_tile, ident##_TILE_COUNT, ident##_tiles);                                                                         \
        /*set_bkg_tiles(x_tile,y_tile, w,h, ident##_map);*/                                                                                  \
        scene_set_bkg_submap_fixed(0, 0, x_tile, y_tile, ident##_WIDTH / 8, ident##_HEIGHT / 8, ident##_map, ident##_WIDTH / 8, first_tile); \
    }                                                                                                                                        \
    void draw_##ident(void) {}

#define DRAW_SP_ANIMATION(ident, frame, sp_start, tile_start, w_tiles_8, h_tiles_16, x, y)       \
    void draw_##ident##_##frame(void);                                                           \
    void init_##ident##_##frame(void)                                                            \
    {                                                                                            \
        draw_##ident##_##frame();                                                                \
    }                                                                                            \
    void draw_##ident##_##frame(void)                                                            \
    {                                                                                            \
        struct SpriteData data = {                                                               \
            tile_start,                                                                          \
            sp_start,                                                                            \
            w_tiles_8,                                                                           \
            h_tiles_16,                                                                          \
            ident##_map,                                                                         \
            ident##_tiles,                                                                       \
        };                                                                                       \
        struct SpriteOpArgs args = {                                                             \
            x,                                                                                   \
            y,                                                                                   \
        };                                                                                       \
        scene_sprite_operation(data, SpriteOp_SetData | SpriteOp_SetTile | SpriteOp_Move, args); \
    }

#define DEFAULT_SP_TICK_CASE(frame, fx)      \
    case frame:                              \
        fx();                                \
        this_state->ticks_left = INIT_TICKS; \
        break;
#define DEFAULT_SP_TICK_CASE_TICKS(frame, fx, ticks) \
    case frame:                                      \
        fx();                                        \
        this_state->ticks_left = ticks;              \
        break;

#define DEFAULT_SP_TICK_START(ident, frames)                                                    \
    struct animation ident##_state = {0, frames, INIT_TICKS, 0};                                \
    void tick_##ident(void)                                                                     \
    {                                                                                           \
        struct animation *this_state = &ident##_state;                                          \
        clock_t now = clock();                                                                  \
        if (now - this_state->last_frame < ANIMATION_INTERVAL_CLOCKS)                           \
        {                                                                                       \
            return;                                                                             \
        }                                                                                       \
        this_state->last_frame = now;                                                           \
        this_state->ticks_left -= 1;                                                            \
        if (this_state->ticks_left > 0)                                                         \
        {                                                                                       \
            return;                                                                             \
        }                                                                                       \
        this_state->current_frame = (this_state->current_frame + 1) % this_state->total_frames; \
        switch (this_state->current_frame)                                                      \
        {

#define DEFAULT_SP_TICK_END \
    }                       \
    }

// end of scene.h