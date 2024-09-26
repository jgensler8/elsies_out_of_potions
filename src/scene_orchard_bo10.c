#pragma bank 10
#include "scene_orchard_bo10.h"
#include "scene_elsie_bo4.h"
#include "state.h"

#define DRAW_BKG_ANIMATION_ORCHARD_TEXT_3(frame) DRAW_BKG_ANIMATION(bg_orchard_delivery_3_text_bo10_##frame, ELSIE_BG_END, 0, 0)
#include "bg_orchard_delivery_3_text_bo10_1.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT_3(1)
#include "bg_orchard_delivery_3_text_bo10_2.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT_3(2)
#include "bg_orchard_delivery_3_text_bo10_3.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT_3(3)
#include "bg_orchard_delivery_3_text_bo10_4.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT_3(4)
#include "bg_orchard_delivery_3_text_bo10_5.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT_3(5)
#include "bg_orchard_delivery_3_text_bo10_6.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT_3(6)
#include "bg_orchard_delivery_3_text_bo10_7.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT_3(7)
#include "bg_orchard_delivery_3_text_bo10_8.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT_3(8)
#include "bg_orchard_delivery_3_text_bo10_9.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT_3(9)
#include "bg_orchard_delivery_3_text_bo10_10.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT_3(10)
#include "bg_orchard_delivery_3_text_bo10_11.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT_3(11)
#include "bg_orchard_delivery_3_text_bo10_12.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT_3(12)
#include "bg_orchard_delivery_3_text_bo10_13.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT_3(13)
#include "bg_orchard_delivery_3_text_bo10_14.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT_3(14)
#include "bg_orchard_delivery_3_text_bo10_15.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT_3(15)
#include "bg_orchard_delivery_3_text_bo10_16.h"
DRAW_BKG_ANIMATION_ORCHARD_TEXT_3(16)

enum PersonID orchard_3_CharacterToShow()
{
    switch (state.current_scene)
    {
#define PERSON_CASE(frame, person)           \
    case SceneID_Orchard_Delivery_3_##frame: \
        return person;
        PERSON_CASE(1, PersonID_Elsie)
        PERSON_CASE(2, PersonID_WitchNormal)
        PERSON_CASE(3, PersonID_WitchNormal)
        PERSON_CASE(4, PersonID_WitchNormal)
        PERSON_CASE(5, PersonID_WitchNormal)
        PERSON_CASE(6, PersonID_WitchTrollBefore)
        PERSON_CASE(7, PersonID_WitchTrollBefore)
        PERSON_CASE(8, PersonID_WitchTrollBefore)
        PERSON_CASE(9, PersonID_WitchTrollBefore)
        PERSON_CASE(10, PersonID_Elsie)
        PERSON_CASE(11, PersonID_WitchTrollBefore)
        PERSON_CASE(12, PersonID_WitchTrollBefore)
        PERSON_CASE(13, PersonID_WitchTrollBefore)
        PERSON_CASE(14, PersonID_Elsie)
        PERSON_CASE(15, PersonID_WitchTrollBefore)
        PERSON_CASE(16, PersonID_WitchTrollBefore)
    }
    return PersonID_None;
}
enum ExpressionID orchard_3_ExpressionToShow()
{
    switch (state.current_scene)
    {
#define EXPRESSION_CASE(num, expression)   \
    case SceneID_Orchard_Delivery_3_##num: \
        return ExpressionID_##expression;
        EXPRESSION_CASE(1, Sigh)
        EXPRESSION_CASE(2, Normal)
        EXPRESSION_CASE(3, Normal)
        EXPRESSION_CASE(4, Normal)
        EXPRESSION_CASE(5, Normal)
        EXPRESSION_CASE(6, Normal)
        EXPRESSION_CASE(7, Normal)
        EXPRESSION_CASE(8, Normal)
        EXPRESSION_CASE(9, Normal)
        EXPRESSION_CASE(10, Smile)
        EXPRESSION_CASE(11, Normal)
        EXPRESSION_CASE(12, Normal)
        EXPRESSION_CASE(13, Normal)
        EXPRESSION_CASE(14, Sigh)
        EXPRESSION_CASE(15, Normal)
        EXPRESSION_CASE(16, Normal)
    }
    return ExpressionID_None;
}
void orchard_3_ShowText()
{
    switch (state.current_scene)
    {
#define CUTSCENE_CASE(frame)                            \
    case SceneID_Orchard_Delivery_3_##frame:            \
        init_bg_orchard_delivery_3_text_bo10_##frame(); \
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
        CUTSCENE_CASE(16)
    }
}