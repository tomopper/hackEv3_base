#ifndef _SECTION_H_
#define _SECTION_H_

#include "LineTracer.h"
#include "SimpleWalker.h"
#include "VirtualLineTracer.h"

#include "Walker.h"
#include "Judge.h"
#include "LengthJudge.h"
#include "TurnAngleJudge.h"
#include "BrightnessJudge.h"
#include "ColorJudge.h"

class Section {
    public:
        Section();
        ~Section();
        virtual bool run();
        Walker *selectWalker(int no);
        Judge *selectJudge(int no);

        enum WALKER_NO {
            WALKER,
            TRACER,
            VIRTUAL
        };
            enum JUDGE_NO {
            LENGTH,
            TURNANGLE,
            BRIGHTNESS,
            COLOR
        };

    protected:
        Walker *mWalker;
        Judge *mJudge;

    private:

};

#endif
