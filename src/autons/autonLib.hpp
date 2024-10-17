#pragma once

#include "../globals.hpp"
#include "../lib/pidController.hpp"
#include <cmath>

inline double Kp = 300;
inline double Ki = 300;
inline double Kd = 300;

inline void move_dist(double distance){
    double rotations = rot_per_dist(distance);
}