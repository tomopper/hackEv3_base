#ifndef _TAILWALKER_H_
#define _TAILWALKER_H_

#include "Walker.h"
#include "Motor.h"
#include "Odometry.h"
#include "SpeedControl.h"
#include "TailAngle.h"

extern TailAngle *gTailAngle;

class TailWalker : public Walker
{
    public:
        TailWalker(Odometry *odo,
                    SpeedControl *scon);
        void setPwm(float target, float kp, float ki, float kd);
        void run();
        void init();
        void setFlag(int f);
    
    protected:
        SpeedControl *mSpeedControl;
        TailAngle *mTailAngle;

    private:
        int tp;
        float mTarget;
        float mPFactor;
        float mIFactor;
        float mDFactor;
        int stop_flag;

};

#endif
