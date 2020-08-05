#ifndef _VIRTUAL_LINETRACER_H_
#define _VIRTUAL_LINETRACER_H_
#include "Walker.h"

class VirtualLineTracer : public Walker{
    public:
    VirtualLineTracer();
    void setParam(float speed,float target,float kp, float ki, float kd,float angleTarget,float angleKp,float centerX,float centerY);
    float DistanceCal();
    bool run();

}


#endif