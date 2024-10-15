#pragma once

#include "../globals.hpp"
#include "pros/colors.hpp"
#include "../lvgl/lvgl.h"

/*

Selection Box Locations (don't change pretty please)

*/

const int COL_SIZE = 160;
const int ROW_SIZE = 34;

const int BTN_PADDING = 2;
const int BTN_TXT_LEFT_PADDING = 5;

struct sel_button {
    int x, y, width, height, padding;

    pros::Color backgroundColour, highlightColour;

    std::string text = "default";
    bool selected, textCentered;
};



/*

Selections

*/

enum autonEnum {
    NOTHING = 0,
    DEFENSE = 1,
    OFFENSE = 2,

    SOLO_AWP_A = -1,
    SOLO_AWP_B = -2,
    SOLO_AWP_C = -3
};
inline int autonSelect = NOTHING;