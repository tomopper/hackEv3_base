#ifndef _SECTION_H_
#define _SECTION_H_

#include "LineTracer.h"
#include "SimpleWalker.h"

class Section {
    public:
        Section();
        virtual bool run();
        
    protected:
        LineTracer *mTracer;
        SimpleWalker *mWalker;

    private:

};

#endif
