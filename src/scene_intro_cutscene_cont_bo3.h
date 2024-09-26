#pragma once
#include "scene.h"
#include "types.h"

// #define CUTSCENE_BG_CONT(frame) SCENE_BKG_HEADER(bg_intro_cutscene_cont_bo3_##frame)
// CUTSCENE_BG_CONT(1)
// CUTSCENE_BG_CONT(2)
// CUTSCENE_BG_CONT(3)
// CUTSCENE_BG_CONT(4)
// CUTSCENE_BG_CONT(5)
// CUTSCENE_BG_CONT(6)
// CUTSCENE_BG_CONT(7)
// CUTSCENE_BG_CONT(8)
// CUTSCENE_BG_CONT(9)
// CUTSCENE_BG_CONT(10)
// CUTSCENE_BG_CONT(11)
// CUTSCENE_BG_CONT(12)
// CUTSCENE_BG_CONT(13)
// CUTSCENE_BG_CONT(14)
// CUTSCENE_BG_CONT(15)
// CUTSCENE_BG_CONT(16)

enum PersonID intro_cont_CharacterToShow();
enum ExpressionID intro_cont_ExpressionToShow();
void intro_cont_ShowText(void);