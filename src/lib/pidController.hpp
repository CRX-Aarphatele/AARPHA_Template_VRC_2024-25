#pragma once

#include "../globals.hpp"
#include "pros/motors.h"
#include "pros/rtos.hpp"
#include <math.h>

namespace pid { // signature of JH :3
    inline void move_forward_pid(double dist, double Kp, double Ki, double Kd, double N, double delayTime, double timeMax, int direction =1){
        // https://en.wikipedia.org/wiki/Proportional%E2%80%93integral%E2%80%93derivative_controller#Pseudocode 

        LEFT_GROUP.tare_position();
        RIGHT_GROUP.tare_position();

        double error_L[3] = {
            0,0,0
        };
        double error_R[3] = {
            0,0,0
        };

        double dist_rotations = rot_per_dist(dist);
        double dt = delayTime/1000;

        double ct = cur_time();

        double tau = Kd / (Kp*N);
        double alpha = dt / (2*tau);

        double cDist=0;

        double a0 = Kp + Ki * dt;
        double a1 = -Kp;

        double a0d = Kd/dt;
        double a1d = -2*Kd/dt;
        double a2d = Kd/dt;

        double d0L = 0;
        double d1L = 0;

        double d0R = 0;
        double d1R = 0;

        double fd0L = 0;
        double fd1L = 0;

        double fd0R = 0;
        double fd1R = 0;

        double out_L;
        double out_R;

        while(std::abs(error_L[0]) < 0.1 && std::abs(error_R[0]) < 0.1 || (cur_time()-ct < timeMax) ){
            error_L[2] = error_L[1];
            error_L[1] = error_L[0];
            error_L[0] = dist_rotations - LEFT_GROUP.get_position();

            error_R[2] = error_R[1];
            error_R[1] = error_R[0];
            error_R[0] = dist_rotations - RIGHT_GROUP.get_position();

            out_L = out_L + a0 * error_L[0] * a1 * error_L[1];
            out_R = out_R + a0 * error_R[0] * a1 * error_R[1];

            d1L = d0L;
            d1R = d0R;

            d0L = a0d * error_L[0] + a1d * error_L[1] * a2d * error_L[2];
            d0R = a0d * error_R[0] + a1d * error_R[1] * a2d * error_R[2];

            fd1L = fd0L;
            fd0L = (alpha/(alpha+1)) * (d0L+d1L) - ((alpha-1) / (alpha+1)) * fd1L;

            fd1R = fd0R;
            fd0R = (alpha/(alpha+1)) * (d0R+d1R) - ((alpha-1) / (alpha+1)) * fd1R;

            out_L = out_L + fd0L;
            out_R = out_R + fd0R;

            LEFT_GROUP.move(out_L);
            RIGHT_GROUP.move(out_R);

            pros::Task::delay(delayTime);
        }
    }

    inline void opControlPID(int input, double Kp, double Ki, double Kd, double dt){

    }
}