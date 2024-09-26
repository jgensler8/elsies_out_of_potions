#include <gbdk/platform.h>
// #include "font.h"

const int letter_width = 16;
const int font_tile_parts = 2;
const int sp_x_mods[4] = {0, 8, 0, 8};
const int sp_y_mods[4] = {0, 0, 8, 8};
const int bkg_x_mods[4] = {0, 1, 0, 1};
const int bkg_y_mods[4] = {0, 0, 1, 1};
const int letter_widths[30] = {
    11, // a
    12, // b
    10, // c
    12, // d
    10, // e
    9,  // f
    11, // g
    12, // h
    5,  // i
    8,  // j
    10, // k
    8,  // l
    14, // m
    13, // n
    12, // o
    10, // p
    12, // q
    11, // r
    11, // s
    11, // t
    12, // u
    12, // v
    13, // w
    13, // x
    11, // y
    9,  // z
    0,
    0,
    0,
    0,
};
const int letter_spacing = 1;

// returns the sprite index after the last tile written
int sp_draw_text(int sp_tile_start, int out_x, int out_y, char *text)
{
    int letter_num = 0;
    int sp_tile_num = sp_tile_start;
    int write_x = out_x;
    while (text[letter_num] != NULL)
    {
        char letter = text[letter_num];
        if (letter == ' ')
        {
            // width of a space
            write_x += 11;
            letter_num += 1;
            continue;
        }
        int letter_idx = ((int)letter) - 97;
        int letter_width = letter_widths[letter_idx];
        int char_tile = letter_idx * 4;
        for (int font_tile_part = 0; font_tile_part < font_tile_parts; font_tile_part++)
        {
            // TODO if both parts of a tile are empty,
            //   continue, don't create a tile
            //   and do not increment sp_tile_num
            //   (currently only i/l + punctuation)
            set_sprite_tile(sp_tile_num, char_tile + font_tile_part * 2);
            int x_mod = sp_x_mods[font_tile_part];
            int y_mod = sp_y_mods[font_tile_part];
            move_sprite(sp_tile_num, write_x + x_mod, out_y + 16 + y_mod);
            sp_tile_num += 1;
        }
        write_x += letter_width + letter_spacing;
        letter_num++;
    }
    return sp_tile_num;
}

void bg_draw_text(int alphabet_sprite_start, int out_x, int out_y, char *text, const uint8_t *font_map)
{
    int letter_num = 0;
    int write_x = out_x;
    int write_y = out_y;
    while (text[letter_num] != NULL)
    {
        char letter = text[letter_num];
        if (letter == ' ')
        {
            // width of a space
            write_x += 1;
            letter_num++;
            continue;
        }
        int letter_idx = ((int)letter) - 97;
        // int letter_width = letter_widths[letter_idx];
        for (int font_tile_part = 0; font_tile_part < 4; font_tile_part++)
        {
            int x_mod = bkg_x_mods[font_tile_part];
            int y_mod = bkg_y_mods[font_tile_part];
            int mapped_tile = alphabet_sprite_start + font_map[letter_idx * 4 + font_tile_part];
            set_bkg_tile_xy(write_x + x_mod, write_y + y_mod, mapped_tile);
        }
        write_x += 2;
        letter_num++;
    }
}

