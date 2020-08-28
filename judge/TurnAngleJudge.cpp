#include "TurnAngleJudge.h"

extern float gStartAngle;


TurnAngleJudge::TurnAngleJudge()
{
    mStartAngle = 0.0;
    mFinishAngle = 0.0;
}

void TurnAngleJudge::setStartAngle()
{
    mStartAngle = mTurnAngle->getValue();
}

void TurnAngleJudge::setFinishAngle(float finangle)
{
    mFinishAngle = finangle;
}

bool TurnAngleJudge::run()
{

    if (mFinishAngle >= mStartAngle)
    {
        if (mTurnAngle->getValue() >= mFinishAngle)
        {
            return true;
        }

        return false;
    }
    else
    {

        if (mTurnAngle->getValue() <= mFinishAngle)
        {
            return true;
        }
        return false;
    }
}

void TurnAngleJudge::init()
{

    if(update == Judge::UPDATE){
    
    gStartAngle = mTurnAngle->getValue();
    mFinishAngle=mFinishAngle+gStartAngle;
    }
    else{

         mFinishAngle=mFinishAngle+gStartAngle;

    }
}

void TurnAngleJudge::setupdate(Judge::JUDGE_MODE a){
    update=a;

}

