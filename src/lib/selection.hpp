#include "../globals.hpp"
#include "liblvgl/core/lv_disp.h"
#include "liblvgl/core/lv_event.h"
#include "liblvgl/core/lv_obj.h"
#include "liblvgl/core/lv_obj_style.h"
#include "liblvgl/draw/lv_draw_rect.h"
#include "liblvgl/misc/lv_area.h"
#include "liblvgl/misc/lv_color.h"
#include "liblvgl/misc/lv_style.h"
#include "liblvgl/widgets/lv_label.h"
#include "liblvgl/widgets/lv_switch.h"
#include "pros/colors.h"
#include "pros/colors.hpp"
#include "../include/liblvgl/lvgl.h"
#include <cstddef>
#include <cstdint>
#include <string>

/*

Selection Box Stuff

*/

const inline int COL_SIZE = 160;
const inline int ROW_SIZE = 34;

const inline int BTN_PADDING = 2;
const inline int BTN_TXT_LEFT_PADDING = 5;

class button {
    public:
        int x,y;
        int width,height;
        int padding;

        lv_color_t backgroundColour, highlightColour, hoverColour, clickColour;
        lv_style_t * btnStyle;
        std::string text;

        bool selected;

        button( int px, int py,
                int w, int h, 
                lv_color_t bgColour, lv_color_t hlColour, 
                lv_color_t hvColour, lv_color_t ckColour, 
                std::string txt, bool sel = false)

                : x(px), y(py)
                , width(w), height(h)
                , backgroundColour(bgColour), highlightColour(hlColour)
                , hoverColour(hvColour), clickColour(ckColour)
                , text(txt) 
                , selected(sel)
                {};

        void draw(){
            lv_obj_t * buttonObject = lv_obj_create(lv_scr_act());

            lv_obj_set_size(buttonObject,width,height);
            lv_obj_set_pos(buttonObject,x,y);

            // default state
            lv_obj_set_style_bg_color(buttonObject, backgroundColour,LV_STATE_DEFAULT);
            lv_obj_set_style_outline_color(buttonObject,highlightColour,LV_STATE_DEFAULT);

            // hover state
            lv_obj_set_style_bg_color(buttonObject,hoverColour,LV_STATE_PRESSED); 
            lv_obj_set_style_outline_color(buttonObject, highlightColour, LV_STATE_PRESSED);

            // selected state
            lv_obj_set_style_bg_color(buttonObject, clickColour, LV_STATE_CHECKED);
            lv_obj_set_style_outline_color(buttonObject, highlightColour, LV_STATE_CHECKED);

            // text label
            lv_obj_t * label = lv_label_create(buttonObject);
            lv_label_set_text(label, text.data());
            lv_obj_set_style_text_color(label, highlightColour, LV_STATE_ANY);
            lv_obj_align(label,LV_ALIGN_CENTER,0,0);

            // add callback for being pressed
            lv_obj_add_event_cb(buttonObject, btn_event_cb, LV_EVENT_PRESSED, NULL);
        }

        static void btn_event_cb(lv_event_t * e){
            
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

inline void initSelectorMenu(){
    std::vector<button> e;
    
    button mikeel = button(20,20, 200,50,lv_color_hex(0x403C40),lv_color_hex(0xFFF2FE),lv_color_hex(0x9c919c),lv_color_make(90,85,30),"h");
    
    mikeel.draw();
}