#ifndef _YPOSITION_H_
#define _YPOSITION_H_

#include "Measure.h"

class YPosition : public Measure{
    public:
        YPosition();
        double getvalue();
        void update(double y);

    private:
        double mYPosition;

};

#endif
