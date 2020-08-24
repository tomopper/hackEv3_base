#ifndef _TURNANGLEJUDGE_H_
#define _TURNANGLEJUDGE_H_


#include "Judge.h"
class TurnAngleJudge : public Judge{
    public:
    TurnAngleJudge();


    void setStartAngle();
    void setFinishAngle(float finangle);
    bool run();
    void init();

    private:
    float mStartAngle;
    float mFinishAngle;



};


#endif



