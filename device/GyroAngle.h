#ifndef _GYROANGLE_H_
#define _GYROANGLE_H_
#include "Measure.h"

class GyroAngle : public Measure
{
    public :
        GyroAngle();
        float getValue();
        void update(float ga);
    private :
        double gAngle;
};

#endif