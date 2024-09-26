#include "scene_elsie_bo4.h"

#include "bg_elsie_bo4.h"
DRAW_BKG_ANIMATION(bg_elsie_bo4, 0, 0, 4)

#include "sp_elsie_dreaming_bo4_1.h"
DRAW_SP_ANIMATION(sp_elsie_dreaming_bo4_1, 0, 0, 0, 6, 5, 40 + 8, 64 + 16)
void init_sp_elsie_dreaming_bo4(void)
{
    draw_sp_elsie_dreaming_bo4_1_0();
}
DEFAULT_SP_TICK_START(sp_elsie_dreaming_bo4, 1)
DEFAULT_SP_TICK_CASE_TICKS(0, draw_sp_elsie_dreaming_bo4_1_0, 1)
DEFAULT_SP_TICK_END

#include "sp_elsie_ecstatic_bo4_1.h"
DRAW_SP_ANIMATION(sp_elsie_ecstatic_bo4_1, 0, 0, 0, 5, 3, 40 + 8, 64 + 16)
void init_sp_elsie_ecstatic_bo4(void)
{
    draw_sp_elsie_ecstatic_bo4_1_0();
}
DEFAULT_SP_TICK_START(sp_elsie_ecstatic_bo4, 1)
DEFAULT_SP_TICK_CASE_TICKS(0, draw_sp_elsie_ecstatic_bo4_1_0, 1)
DEFAULT_SP_TICK_END

#include "sp_elsie_smile_bo4_1.h"
DRAW_SP_ANIMATION(sp_elsie_smile_bo4_1, 0, 0, 0, 5, 2, 40 + 8, 64 + 16)
#include "sp_elsie_smile_bo4_2.h"
DRAW_SP_ANIMATION(sp_elsie_smile_bo4_2, 0, 0, 0, 5, 2, 40 + 8, 64 + 16)
#include "sp_elsie_smile_bo4_3.h"
DRAW_SP_ANIMATION(sp_elsie_smile_bo4_3, 0, 0, 0, 5, 2, 40 + 8, 64 + 16)
void init_sp_elsie_smile_bo4(void)
{
    draw_sp_elsie_smile_bo4_1_0();
}
DEFAULT_SP_TICK_START(sp_elsie_smile_bo4, 4)
DEFAULT_SP_TICK_CASE_TICKS(0, draw_sp_elsie_smile_bo4_2_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(1, draw_sp_elsie_smile_bo4_3_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(2, draw_sp_elsie_smile_bo4_2_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(3, draw_sp_elsie_smile_bo4_1_0, 20)
DEFAULT_SP_TICK_END

#include "sp_elsie_thinking_bo4_1.h"
DRAW_SP_ANIMATION(sp_elsie_thinking_bo4_1, 0, 0, 0, 5, 5, 30 + 8, 64 + 16)
#include "sp_elsie_thinking_bo4_2.h"
DRAW_SP_ANIMATION(sp_elsie_thinking_bo4_2, 0, 0, 0, 5, 5, 30 + 8, 64 + 16)
#include "sp_elsie_thinking_bo4_3.h"
DRAW_SP_ANIMATION(sp_elsie_thinking_bo4_3, 0, 0, 0, 5, 5, 30 + 8, 64 + 16)
#include "sp_elsie_thinking_bo4_4.h"
DRAW_SP_ANIMATION(sp_elsie_thinking_bo4_4, 0, 0, 0, 5, 5, 30 + 8, 64 + 16)
#include "sp_elsie_thinking_bo4_5.h"
DRAW_SP_ANIMATION(sp_elsie_thinking_bo4_5, 0, 0, 0, 5, 5, 30 + 8, 64 + 16)
#include "sp_elsie_thinking_bo4_6.h"
DRAW_SP_ANIMATION(sp_elsie_thinking_bo4_6, 0, 0, 0, 5, 5, 30 + 8, 64 + 16)
void init_sp_elsie_thinking_bo4(void)
{
    draw_sp_elsie_thinking_bo4_1_0();
}
DEFAULT_SP_TICK_START(sp_elsie_thinking_bo4, 13)
// finger
DEFAULT_SP_TICK_CASE_TICKS(0, draw_sp_elsie_thinking_bo4_1_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(1, draw_sp_elsie_thinking_bo4_2_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(2, draw_sp_elsie_thinking_bo4_3_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(3, draw_sp_elsie_thinking_bo4_2_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(4, draw_sp_elsie_thinking_bo4_3_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(5, draw_sp_elsie_thinking_bo4_2_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(6, draw_sp_elsie_thinking_bo4_1_0, 10)
DEFAULT_SP_TICK_CASE_TICKS(7, draw_sp_elsie_thinking_bo4_4_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(8, draw_sp_elsie_thinking_bo4_5_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(9, draw_sp_elsie_thinking_bo4_6_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(10, draw_sp_elsie_thinking_bo4_5_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(11, draw_sp_elsie_thinking_bo4_4_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(12, draw_sp_elsie_thinking_bo4_1_0, 18)
// blink
DEFAULT_SP_TICK_END

#include "sp_elsie_reading_bo4_1.h"
DRAW_SP_ANIMATION(sp_elsie_reading_bo4_1, 0, 0, 0, 8, 5, 30 + 8, 64 + 16)
#include "sp_elsie_reading_bo4_2.h"
DRAW_SP_ANIMATION(sp_elsie_reading_bo4_2, 0, 0, 0, 8, 5, 30 + 8, 64 + 16)
#include "sp_elsie_reading_bo4_3.h"
DRAW_SP_ANIMATION(sp_elsie_reading_bo4_3, 0, 0, 0, 8, 5, 30 + 8, 64 + 16)
void init_sp_elsie_reading_bo4(void)
{
    draw_sp_elsie_reading_bo4_1_0();
}
DEFAULT_SP_TICK_START(sp_elsie_reading_bo4, 3)
DEFAULT_SP_TICK_CASE_TICKS(0, draw_sp_elsie_reading_bo4_2_0, 5)
DEFAULT_SP_TICK_CASE_TICKS(1, draw_sp_elsie_reading_bo4_1_0, 5)
DEFAULT_SP_TICK_CASE_TICKS(2, draw_sp_elsie_reading_bo4_3_0, 5)
DEFAULT_SP_TICK_END

#define ELSIE_SIGH_X 38
#define ELSIE_SIGH_W_TILES_8 5
#define ELSIE_SIGH_H_TILES_16 3
#include "sp_elsie_sigh_bo4_1.h"
DRAW_SP_ANIMATION(sp_elsie_sigh_bo4_1, 0, 0, 0, ELSIE_SIGH_W_TILES_8,ELSIE_SIGH_H_TILES_16, ELSIE_SIGH_X + 8, 64 + 16)
#include "sp_elsie_sigh_bo4_2.h"
DRAW_SP_ANIMATION(sp_elsie_sigh_bo4_2, 0, 0, 0, ELSIE_SIGH_W_TILES_8,ELSIE_SIGH_H_TILES_16, ELSIE_SIGH_X + 8, 64 + 16)
#include "sp_elsie_sigh_bo4_3.h"
DRAW_SP_ANIMATION(sp_elsie_sigh_bo4_3, 0, 0, 0, ELSIE_SIGH_W_TILES_8,ELSIE_SIGH_H_TILES_16, ELSIE_SIGH_X + 8, 64 + 16)
#include "sp_elsie_sigh_bo4_4.h"
DRAW_SP_ANIMATION(sp_elsie_sigh_bo4_4, 0, 0, 0, ELSIE_SIGH_W_TILES_8,ELSIE_SIGH_H_TILES_16, ELSIE_SIGH_X + 8, 64 + 16)
#include "sp_elsie_sigh_bo4_5.h"
DRAW_SP_ANIMATION(sp_elsie_sigh_bo4_5, 0, 0, 0, ELSIE_SIGH_W_TILES_8,ELSIE_SIGH_H_TILES_16, ELSIE_SIGH_X + 8, 64 + 16)
#include "sp_elsie_sigh_bo4_6.h"
DRAW_SP_ANIMATION(sp_elsie_sigh_bo4_6, 0, 0, 0, ELSIE_SIGH_W_TILES_8,ELSIE_SIGH_H_TILES_16, ELSIE_SIGH_X + 8, 64 + 16)
#include "sp_elsie_sigh_bo4_7.h"
DRAW_SP_ANIMATION(sp_elsie_sigh_bo4_7, 0, 0, 0, ELSIE_SIGH_W_TILES_8,ELSIE_SIGH_H_TILES_16, ELSIE_SIGH_X + 8, 64 + 16)
#include "sp_elsie_sigh_bo4_8.h"
DRAW_SP_ANIMATION(sp_elsie_sigh_bo4_8, 0, 0, 0, ELSIE_SIGH_W_TILES_8,ELSIE_SIGH_H_TILES_16, ELSIE_SIGH_X + 8, 64 + 16)
void init_sp_elsie_sigh_bo4(void)
{
    draw_sp_elsie_sigh_bo4_1_0();
}
DEFAULT_SP_TICK_START(sp_elsie_sigh_bo4, 6)
DEFAULT_SP_TICK_CASE_TICKS(0, draw_sp_elsie_sigh_bo4_1_0, 20)
DEFAULT_SP_TICK_CASE_TICKS(1, draw_sp_elsie_sigh_bo4_2_0, 3)
DEFAULT_SP_TICK_CASE_TICKS(2, draw_sp_elsie_sigh_bo4_3_0, 5)
DEFAULT_SP_TICK_CASE_TICKS(3, draw_sp_elsie_sigh_bo4_4_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(4, draw_sp_elsie_sigh_bo4_5_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(5, draw_sp_elsie_sigh_bo4_6_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(6, draw_sp_elsie_sigh_bo4_7_0, 1)
DEFAULT_SP_TICK_CASE_TICKS(7, draw_sp_elsie_sigh_bo4_8_0, 1)
DEFAULT_SP_TICK_END