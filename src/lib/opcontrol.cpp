#include "oplib.hpp"

static void opInit(){

}

static void opMainLoop(){
    int fwd = controller::ly;
    fwd = joymap(fwd);
}
