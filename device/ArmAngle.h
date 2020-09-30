#ifndef _ARMANGLE_H_
#define _ARMANGLE_H_

#include "Measure.h"

class ArmAngle : public Measure
{
    public :
        ArmAngle();
        float getValue();
        void update(float arm);
    private :
        float mArmAngle;
};

#endif
