#pragma once

#include "main.h"

#include "pros/abstract_motor.hpp"
#include "pros/adi.h"
#include "pros/misc.h"
#include "pros/misc.hpp"
#include "pros/motor_group.hpp"
#include "pros/motors.h"
#include "pros/motors.hpp"

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <vector>

#include "pros/adi.hpp"
#include "pros/motors.h"
#include "pros/motors.hpp"

const double RPM_RED = 100;
const double RPM_GRN = 200;
const double RPM_BLU = 600;

const pros::MotorGears GEAR_RED = pros::v5::MotorGears::red;
const pros::MotorGears GEAR_GREEN = pros::v5::MotorGears::green;
const pros::MotorGears GEAR_BLUE = pros::v5::MotorGears::blue;

const int MTR_MAX = 127;

const double WHL_DIAMETER = 2.75;
const double WHL_RADIUS = WHL_DIAMETER/2;

// get main controller
const inline pros::Controller MASTER(pros::E_CONTROLLER_MASTER);

// define a btn and stk variable
#define btn static constexpr pros::controller_digital_e_t
#define stk static constexpr pros::controller_analog_e_t

// map controller to variables
namespace controller {
    stk lx = pros::E_CONTROLLER_ANALOG_LEFT_X;
    stk ly = pros::E_CONTROLLER_ANALOG_LEFT_Y;

    stk rx = pros::E_CONTROLLER_ANALOG_RIGHT_X;
    stk ry = pros::E_CONTROLLER_ANALOG_RIGHT_Y;

    btn up = pros::E_CONTROLLER_DIGITAL_UP;
    btn down = pros::E_CONTROLLER_DIGITAL_DOWN;
    btn left = pros::E_CONTROLLER_DIGITAL_LEFT;
    btn right = pros::E_CONTROLLER_DIGITAL_RIGHT;

    btn A = pros::E_CONTROLLER_DIGITAL_A;
    btn B = pros::E_CONTROLLER_DIGITAL_B;
    btn X = pros::E_CONTROLLER_DIGITAL_X;
    btn Y = pros::E_CONTROLLER_DIGITAL_Y;

    btn lb = pros::E_CONTROLLER_DIGITAL_L1;
    btn lt = pros::E_CONTROLLER_DIGITAL_L2;

    btn rb = pros::E_CONTROLLER_DIGITAL_R1;
    btn rt = pros::E_CONTROLLER_DIGITAL_R2;
}

// motor ports (left)
const int L_FRNT_PORT = 1;
const int L_CNTR_PORT = 2;
const int L_REAR_PORT = 3;

// motor ports (right)
const int R_FRNT_PORT = 11;
const int R_CNTR_PORT = 12;
const int R_REAR_PORT = 13;

// Field Data
const double tile = 

// motors (left) :3
const inline pros::Motor LEFT_FRONT(L_FRNT_PORT, GEAR_BLUE);
const inline pros::Motor LEFT_CENTER(L_CNTR_PORT, GEAR_BLUE);
const inline pros::Motor LEFT_REAR(L_REAR_PORT, GEAR_BLUE);
const inline pros::MotorGroup LEFT_GROUP({L_FRNT_PORT,L_CNTR_PORT,L_REAR_PORT}, GEAR_BLUE);

// motors (right)
const inline pros::Motor RIGHT_FRONT(R_FRNT_PORT, GEAR_BLUE);
const inline pros::Motor RIGHT_CENTER(R_CNTR_PORT, GEAR_BLUE);
const inline pros::Motor RIGHT_REAR(R_REAR_PORT, GEAR_BLUE);
const inline pros::MotorGroup RIGHT_GROUP({R_FRNT_PORT,R_CNTR_PORT,R_REAR_PORT}, GEAR_BLUE);

// pneumatics, sensors, etc.
const pros::adi::DigitalOut ADI_A = pros::adi::DigitalOut(1);

