#pragma once

#include "../globals.hpp"
#include "math.h"
#include <numbers>

static int joymap(int stick){
    return (int) 127*sin(stick)*(std::numbers::pi/(2*127));
}