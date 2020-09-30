#ifndef _ANGLERVELOCITY_H_
#define _ANGLERVELOCITY_H_

#include "Measure.h"

class AnglerVelocity : public Measure
{
    public :
        AnglerVelocity();
        float getValue();
        void update(float a);
    private : 
        float angvelo;
};

#endif
