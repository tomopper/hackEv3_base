#ifndef WALKER_H_
#define WALKER_H_

#include "Odometry.h"
#include "Brightness.h"
#include "PID.h"

extern Brightness *gBrightness;

class Walker
{
    public:
        Walker( Odometry *odo );

        virtual void run();
        virtual void printInfo();

    protected:
        Odometry *mOdo;
        PID *mPid;

        Brightness *mBright;

    private:



};
#endif
