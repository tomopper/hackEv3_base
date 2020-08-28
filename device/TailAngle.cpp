#include "TailAngle.h"
#include "util.h"

TailAngle::TailAngle():
    Measure()
{

}

float TailAngle::getValue()
{

    //return mTailAngle;
    return mLpf->getFillteredValue();

}

void TailAngle::update(float tail)
{
    mLpf->addValue(tail);
    mTailAngle = tail;
    /*static char buf[256];
    sprintf(buf," %f",mTailAngle);
    msg_log(buf);*/
}