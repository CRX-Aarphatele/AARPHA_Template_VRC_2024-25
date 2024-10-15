#include "../globals.hpp"
#include "pros/motors.h"
#include "pros/rtos.hpp"
#include <math.h>

namespace pid { // signature of JH :3
    inline void move_forward_pid(double dist, double Kp, double Ki, double Kd, double delayTime, double timeMax, int direction =1){
        double error_L[3] = {
            0,0,0
        };
        double error_R[3] = {
            0,0,0
        };

        double dist_rotations = rot_per_dist(dist);
        double dt = delayTime/1000;

        double ct = cur_time();

        double N = 5;
        double tau = Kd / (Kp*N);
        double alpha = dt / (2*tau);

        double cDist=0;

        

        double a0 = 0;

        while(std::abs(error_L[0]) < 0.1 && std::abs(error_R[0]) < 0.1 || (cur_time()-ct < timeMax) ){
            

            pros::Task::delay(delayTime);
        }
    }

    inline void opControlPID(int input, double Kp, double Ki, double Kd, double dt){

    }
}