#pragma bank 8
#include "scene_orchard_bo8.h"
#include "scene_elsie_bo4.h"
#include "state.h"

#define DRAW_BKG_ANIMATION_ORCHARD_TEXT(frame) DRAW_BKG_ANIMATION(bg_orchard_text_bo8_##frame, ELSIE_BG_END, 0, 0)
#include "bg_orchard_text_bo8_1.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT(1)
#include "bg_orchard_text_bo8_2.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT(2)
#include "bg_orchard_text_bo8_3.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT(3)
#include "bg_orchard_text_bo8_4.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT(4)
#include "bg_orchard_text_bo8_5.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT(5)
#include "bg_orchard_text_bo8_6.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT(6)
#include "bg_orchard_text_bo8_7.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT(7)
#include "bg_orchard_text_bo8_8.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT(8)
#include "bg_orchard_text_bo8_9.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT(9)
#include "bg_orchard_text_bo8_10.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT(10)
#include "bg_orchard_text_bo8_11.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT(11)
#include "bg_orchard_text_bo8_12.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT(12)
#include "bg_orchard_text_bo8_13.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT(13)
#include "bg_orchard_text_bo8_14.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT(14)
#include "bg_orchard_text_bo8_15.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT(15)

enum PersonID orchard_1_CharacterToShow()
{
    switch (state.current_scene)
    {
#define PERSON_CASE(num, person)         \
    case SceneID_Orchard_Delivery_##num: \
        return person;
        PERSON_CASE(1, PersonID_Elsie)
        PERSON_CASE(2, PersonID_Elsie)
        PERSON_CASE(3, PersonID_Elsie)
        PERSON_CASE(4, PersonID_Elsie)
        PERSON_CASE(5, PersonID_Elsie)
        PERSON_CASE(6, PersonID_Elsie)
        PERSON_CASE(7, PersonID_WitchNormal)
        PERSON_CASE(8, PersonID_Elsie)
        PERSON_CASE(9, PersonID_WitchNormal)
        PERSON_CASE(10, PersonID_WitchNormal)
        PERSON_CASE(11, PersonID_WitchNormal)
        PERSON_CASE(12, PersonID_WitchNormal)
        PERSON_CASE(13, PersonID_WitchNormal)
        PERSON_CASE(14, PersonID_Elsie)
        PERSON_CASE(15, PersonID_WitchNormal)
    }
    return PersonID_None;
}
enum ExpressionID orchard_1_ExpressionToShow()
{
    switch (state.current_scene)
    {
#define EXPRESSION_CASE(num, expression) \
    case SceneID_Orchard_Delivery_##num: \
        return ExpressionID_##expression;
        EXPRESSION_CASE(1, Thinking)
        EXPRESSION_CASE(2, Thinking)
        EXPRESSION_CASE(3, Smile)
        EXPRESSION_CASE(4, Smile)
        EXPRESSION_CASE(5, Smile)
        EXPRESSION_CASE(6, Smile)
        EXPRESSION_CASE(7, Normal)
        EXPRESSION_CASE(8, Smile)
        EXPRESSION_CASE(9, Normal)
        EXPRESSION_CASE(10, Normal)
        EXPRESSION_CASE(11, Normal)
        EXPRESSION_CASE(12, Normal)
        EXPRESSION_CASE(13, Normal)
        EXPRESSION_CASE(14, Ecstatic)
        EXPRESSION_CASE(15, Normal)
    }
    return ExpressionID_None;
}
void orchard_1_ShowText()
{
    switch (state.current_scene)
    {
#define CUTSCENE_CASE(frame)                \
    case SceneID_Orchard_Delivery_##frame:  \
        init_bg_orchard_text_bo8_##frame(); \
        return;
        CUTSCENE_CASE(1)
        CUTSCENE_CASE(2)
        CUTSCENE_CASE(3)
        CUTSCENE_CASE(4)
        CUTSCENE_CASE(5)
        CUTSCENE_CASE(6)
        CUTSCENE_CASE(7)
        CUTSCENE_CASE(8)
        CUTSCENE_CASE(9)
        CUTSCENE_CASE(10)
        CUTSCENE_CASE(11)
        CUTSCENE_CASE(12)
        CUTSCENE_CASE(13)
        CUTSCENE_CASE(14)
        CUTSCENE_CASE(15)
    }
}