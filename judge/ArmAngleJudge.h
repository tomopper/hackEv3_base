#ifndef _ARMANGLEJUDGE_H_
#define _ARMANGLEJUDGE_H_

#include "Judge.h"

class ArmAngleJudge : public Judge
{
    public :
        ArmAngleJudge();
        void init();
        void setFinAngle(float finangle);
        bool run();

    private : 
        float mStartAngle;
        float mFinAngle;

};

#endif
