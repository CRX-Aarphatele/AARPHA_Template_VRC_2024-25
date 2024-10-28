#include "../globals.hpp"
#include "liblvgl/core/lv_disp.h"
#include "liblvgl/core/lv_event.h"
#include "liblvgl/core/lv_obj.h"
#include "liblvgl/core/lv_obj_style.h"
#include "liblvgl/draw/lv_draw_rect.h"
#include "liblvgl/misc/lv_area.h"
#include "liblvgl/misc/lv_color.h"
#include "liblvgl/misc/lv_style.h"
#include "liblvgl/widgets/lv_btnmatrix.h"
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

namespace selector {

    inline lv_style_t style_trestle;

    inline static const char * map[] = {};

    static void style_init (void){
        

        lv_style_init(&style_trestle);

        /*
        403C40
        9C919C
        FFF2FE
        9D1FA8
        deae21
        */

        lv_color_t manganese_dark = LV_COLOR_MAKE16(8,15,8); // ourple
        lv_color_t manganese_clouds = LV_COLOR_MAKE(19,33,19); // ourple
        lv_color_t wisteria = LV_COLOR_MAKE16(31, 54, 31); // ourple
        lv_color_t porrum_dolce = LV_COLOR_MAKE16(15,8,13); // ourple
        lv_color_t saphris_p = LV_COLOR_MAKE16(17,33,2); // yellow

        lv_color_t teamBtn_tx_p = lv_color_black();

        lv_color_t blueTeam_hl = LV_COLOR_MAKE16(16,28,29);
        lv_color_t blueTeam_ll = LV_COLOR_MAKE16(7,7,13);

        lv_color_t redTeam_hl = LV_COLOR_MAKE16(26,11,14);
        lv_color_t redTeam_ll = LV_COLOR_MAKE16(14,4,10);


        
        lv_style_set_bg_opa(&style_trestle, LV_OPA_COVER);
        lv_style_set_bg_color(&style_trestle, manganese_clouds);
        

    }

    class toggle_team {

    };

    class button_slide {
        public:
            int x,y;
            int width,height;
            int padding;
            int buttons;

            int colour;

            int btnW, btnH;

            lv_color_t backgroundColour, highlightColour, hoverColour, clickColour;
            lv_style_t * style_trestle;

            button_slide( int px, int py,
                    int w, int h,
                    int btns)

                    : x(px), y(py)
                    , width(w), height(h),
                    buttons(btns)
                    {};

            void init(){
                btnW = width;
                btnH = height/buttons;

                style_init();

                
            }

            void draw(){
                
            }

            void callback(lv_event_t * e){
                lv_obj_t * obj = lv_event_get_target(e);
                uint32_t id = lv_btnmatrix_get_selected_btn(obj);

            }

    void event_select(lv_event_t * e){
        
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

    }

}