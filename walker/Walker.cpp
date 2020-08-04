#include "Walker.h"

Walker::Walker( Odometry *odo):
    mOdo(odo)
{
    mPid = new PID();

    mBright = gBrightness;
}


void Walker::run()
{

}

void Walker::printInfo()
{
    msg_log("Walker");
}