#ifndef _SECTION_H_
#define _SECTION_H_

#include "LineTracer.h"
#include "SimpleWalker.h"

#include "Walker.h"
#include "Judge.h"
#include "LengthJudge.h"
#include "TurnAngleJudge.h"

class Section {
    public:
        Section();
        ~Section();
        virtual bool run();
        Walker *selectWalker(int no);
        Judge *selectJudge(int no);

        enum WALKER_NO {
            WALKER,
            TRACER
        };
            enum JUDGE_NO {
            LENGTH,
            TURNANGLE
        };

    protected:
        Walker *mWalker;
        Judge *mJudge;

    private:

};

#endif
