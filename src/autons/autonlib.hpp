#pragma once

#include "../globals.hpp"
#include "../lib/PIDcontrol.hpp"
#include <cmath>

double Kp = 300;
double Ki = 300;
double Kd = 300;

inline void move_dist(double distance){
    double rotations = rot_per_dist(distance);
}