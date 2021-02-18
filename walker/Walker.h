#ifndef WALKER_H_
#define WALKER_H_

#include "Odometry.h"
#include "Brightness.h"
#include "PID.h"
#include "XPosition.h"
#include "YPosition.h"

extern Brightness *gBrightness;
extern XPosition *gXPosition;
extern YPosition *gYPosition;
extern TurnAngle *gTurnAngle;

class Walker
{
public:
    Walker(Odometry *odo);
    ~Walker( );

    virtual void init();
    virtual void run();
    virtual void printInfo();
    int getKind();

    

protected:
    Odometry *mOdo;
    PID *mPid;

    Brightness *mBright;
    XPosition *mXPosition;
    YPosition *mYPosition;
    TurnAngle *mTurnAngle;
    int kind;

private:
};
#endif
