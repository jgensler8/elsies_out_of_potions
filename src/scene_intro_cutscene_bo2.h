#pragma once
#include "scene.h"
#include "types.h"

// #define CUTSCENE_BG(frame) SCENE_BKG_HEADER(bg_intro_cutscene_bo2_##frame)
// CUTSCENE_BG(1)
// CUTSCENE_BG(2)
// CUTSCENE_BG(3)
// CUTSCENE_BG(4)
// CUTSCENE_BG(5)
// CUTSCENE_BG(6)
// CUTSCENE_BG(7)
// CUTSCENE_BG(8)
// CUTSCENE_BG(9)
// CUTSCENE_BG(10)
// CUTSCENE_BG(11)
// CUTSCENE_BG(12)
// CUTSCENE_BG(13)
// CUTSCENE_BG(14)

enum PersonID intro_CharacterToShow();
enum ExpressionID intro_ExpressionToShow();
void intro_ShowText(void);