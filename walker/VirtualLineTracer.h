#ifndef _VIRTUAL_LINETRACER_H_
#define _VIRTUAL_LINETRACER_H_

#include "SimpleWalker.h"
#include "PID.h"


class VirtualLineTracer : public SimpleWalker{
    public:
    VirtualLineTracer(Odometry *odo,
                    SpeedControl *scon);
    void setParam(float speed,float kp, float ki, float kd,float angleTarget,float angleKp,float X,float Y);
    void setCenterPosition(float centerx,float centery);

    void run();

    private:
    void setBaseDistance();
    float calcDistance();
    float calcTurn();

    float cx;
    float cy;
    float ax;
    float ay;
    float basedistance;
    float currentdistance;
    float mTarget;
    float mTargetSpeed;
    float mPFactor;
    float mIFactor;
    float mDFactor;
    float mCurve;
    float mAngleKp;


};


#endif