#ifndef __BRIGHTNESS_H__
#define __BRIGHTNESS_H__
#include "Measure.h"

class Brightness : public Measure
{
    public:
        Brightness();
        float getValue();
        void update(float br);

    private:
        float mBrightness;
};

#endif

