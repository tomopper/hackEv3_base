#ifndef WALKER_H_
#define WALKER_H_

#include "Odometry.h"
#include "PID.h"

class Walker
{
    public:
        Walker( Odometry *odo);

        virtual void run();

    protected:
        Odometry *mOdo;
        PID *mPid;

    private:



};
#endif
