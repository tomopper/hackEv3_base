#include "ArmWalker.h"

ArmWalker::ArmWalker(Odometry *odo,
                    SpeedControl *scon):
    Walker(odo),
    mSpeedControl(scon)
{
    mArmAngle = gArmAngle;

    ap = 0;
    mTarget = 0.0;
    mPFactor = 0.0;
    mIFactor = 0.0;
    mDFactor = 0.0;
    aAngle = 0.0;
}

void ArmWalker::setPwm(float target, float kp, float ki, float kd)
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
    aAngle = mArmAngle->getValue();

    ap = (int)mPid->getOperation(aAngle);
}

void ArmWalker::run()
{
    mOdo->setArmpwm(ap);
}