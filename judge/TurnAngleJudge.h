#ifndef _TURNANGLEJUDGE_H_
#define _TURNANGLEJUDGE_H_


#include "TurnAngleJudge.h"
class TurnAngleJudge : public Judge{
    public:
    TurnAngleJudge();
    void setStartAngle();
    void setFinishAngle(float finangle);
    bool run();

    private:
    float mStartAngle;
    float mFinishAngle;



};


#endif



