#ifndef _XPOSITION_H_
#define _XPOSITION_H_

#include "Measure.h"

class XPosition : public Measure{
    public:
        XPosition();
        double getvalue();
        void update(double x);

    private:
        double mXPosition;

};

#endif
