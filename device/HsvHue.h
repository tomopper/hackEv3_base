#ifndef __HSVHUE_H__
#define __HSVHUE_H__
#include "Measure.h"

class HsvHue : public Measure
{
    public:
        HsvHue();
        float getValue();
        void update(float h);

    private:
        float mHue;
};

#endif

