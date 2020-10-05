#include "GyroJudge.h"
#include "util.h"

GyroJudge::GyroJudge()
{
    vib = 0;
    g = 0;
}

void GyroJudge::setVib(float v)
{
    vib = v;
}

bool GyroJudge::run()
{
    /*static char buf[256];
    sprintf(buf," %f\n",mGyroAngle->getValue());
    msg_log(buf);*/

    g = mGyroAngle->getValue();

    if(g < 0){
        g = -g;
    }

    if(g >= vib){
        return true;
    }

    return false;
}