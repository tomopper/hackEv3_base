#ifndef _SECTION_CONTROL_H_
#define _SECTION_CONTROL_H_

#include "Section.h"

class SectionControl {
    public:
        SectionControl();
        virtual bool run();
        void addSection(Section *);
        void reset();

    protected:
        Section mSection[100];
        int mSectionIdx;
        int mLastIdx;
    private:


};

#endif
