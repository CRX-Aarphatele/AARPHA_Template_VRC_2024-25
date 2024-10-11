#include "../globals.hpp"
#include <math.h>

namespace pid {
    inline double pid(double input, double wish, double Kp, double Ki, double Kd, double &lastError, double &integral, double dt, int direction =1){
        double error = (wish-input) * direction;
        integral = (integral+error)*dt;
        double derivative = (error-lastError)/dt;
        lastError=error;

        return Kp*error + Ki*integral + Kd*derivative;
    }

    inline double deltaTime(double &lastTime){
        return cur_time()-lastTime;
    }
}