#ifndef __MEASURE_H__
#define __MEASURE_H__

#include "LowPassFilter.h"
#include "ev3api.h"
class Measure
{
    public:
        Measure();
        virtual float getValue();

    protected:
        LowPassFilter *mLpf;
		FILE  *bt = NULL;
        SYSTIM start_tim;
        SYSTIM now_tim;

    private:

};

#endif

