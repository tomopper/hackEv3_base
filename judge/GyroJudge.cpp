#include "GyroJudge.h"
#include "util.h"

GyroJudge::GyroJudge()
{
    vib = 0.0;
    flag = 0;
}

void GyroJudge::setVib(float v, int f)
{
    vib = v;
    flag = f;
}

bool GyroJudge::run()
{
    /*static char buf[256];
    sprintf(buf," %f\n",mGyroAngle->getValue());
    msg_log(buf);*/

    if(flag == 1){
        if(mGyroAngle->getValue() >= vib){
            return true;
        }
    }else{
        if(mGyroAngle->getValue() <= vib){
            return true;
        }
    }

    return false;
}