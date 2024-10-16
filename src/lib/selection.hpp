#pragma once

#include "../globals.hpp"
#include "liblvgl/core/lv_disp.h"
#include "liblvgl/core/lv_obj.h"
#include "liblvgl/core/lv_obj_style.h"
#include "liblvgl/draw/lv_draw_rect.h"
#include "liblvgl/misc/lv_color.h"
#include "pros/colors.h"
#include "pros/colors.hpp"
#include "../include/lvgl/lvgl.h"
#include <cstdint>
#include "../include/lvgl/examples/lv_examples.h" // idk

/*

Selection Box Locations (don't change pretty please)

*/

const int COL_SIZE = 160;
const int ROW_SIZE = 34;

const int BTN_PADDING = 2;
const int BTN_TXT_LEFT_PADDING = 5;

struct vector2 {
    int x,y;
    
    vector2(int x, int y);
};

struct button {
    static vector2 pos;
    static vector2 size;
    static int padding;

    static lv_color_t backgroundColour, highlightColour, hoverColour, clickColour;

    static std::string btnText;
    static bool selected, textCentered;

    button(vector2 posRect = pos, vector2 sizeRect = size, 
        lv_color_t bgColour = backgroundColour, lv_color_t hlColour = highlightColour, lv_color_t hvColour = hoverColour, lv_color_t clColour = clickColour, 
        std::string text = "default"); // AHHHHHHHHHHHHHHHH

    static void draw(){
        lv_obj_t * buttonObject = lv_obj_create(lv_scr_act());

        lv_obj_set_size(buttonObject,size.x,size.y);
        lv_obj_set_pos(buttonObject,pos.x,pos.y);

        // default state
        lv_obj_set_style_bg_color(buttonObject, backgroundColour,LV_STATE_DEFAULT);
        lv_obj_set_style_outline_color(buttonObject,highlightColour,LV_STATE_DEFAULT);

        // hover state
        lv_obj_set_style_bg_color(buttonObject,hoverColour,LV_STATE_HOVERED); 
        lv_obj_set_style_outline_color(buttonObject, highlightColour, LV_STATE_HOVERED);

        // selected state
        lv_obj_set_style_bg_color(buttonObject, clickColour, LV_STATE_PRESSED);
        lv_obj_set_style_outline_color(buttonObject, highlightColour, LV_STATE_PRESSED);

        // terrible terrible terrible terrible, if you can fix this please tell me

    }


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