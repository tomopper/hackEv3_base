#ifndef _ARMWALKER_H_
#define _ARMWALKER_H_

#include "Walker.h"
#include "Motor.h"
#include "Odometry.h"
#include "SpeedControl.h"
#include "ArmAngle.h"

extern ArmAngle *gArmAngle;

class ArmWalker : public Walker
{
    public :
        ArmWalker(Odometry *odo,
                    SpeedControl *scon);
        void setPwm(float target, float kp, float ki, float kd);
        void run();
        void init();
        void setFlag(int f);

    protected :
        SpeedControl *mSpeedControl;
        ArmAngle *mArmAngle;
        
    private : 
        int ap;
        float mTarget;
        float mPFactor;
        float mIFactor;
        float mDFactor;
        int stop_flag;
};

#endif
