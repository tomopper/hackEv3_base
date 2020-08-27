#include "TailWalker.h"
#include "Walker.h"
#include "util.h"
extern TailWalker *gTailWalker;

TailWalker::TailWalker(Odometry *odo,
                        SpeedControl *scon):
    Walker(odo),
    mSpeedControl(scon)

{
    mTailAngle = gTailAngle;

    tp = 0;
    mTarget = 0.0;
    mPFactor = 0.0;
    mIFactor = 0.0;
    mDFactor = 0.0;
    kind = 1;
    stop_flag = 0;   
}

void TailWalker::setPwm(float target, float kp, float ki, float kd)
{
    mTarget = target;
    mPFactor = kp;
    mIFactor = ki;
    mDFactor = kd;
    mPid->setLimit(50);
    mPid->setTarget(mTarget);
    mPid->setKp(mPFactor);
    mPid->setKi(mIFactor);
    mPid->setKd(mDFactor);
    static char buf[256];
    sprintf(buf," %f,%f,%f,%f",mTarget,mPFactor,mIFactor,mDFactor);
    msg_log(buf);
}

void TailWalker::run()
{
    if(stop_flag == 0){
    tp = (int)mPid->getOperation(mTailAngle->getValue());
    /*static char buf[256];
    sprintf(buf," %f,%d",mTailAngle->getValue(),tp);
    msg_log(buf);*/
    mOdo->setTailpwm(tp);
    }
}

void TailWalker::init()
{
    gTailWalker->setPwm(mTarget,mPFactor,mIFactor,mDFactor);
    static char buf[256];
    sprintf(buf," %f",mTarget);
    msg_log(buf);
}

void TailWalker::setFlag(int f)
{
    stop_flag = f;
}