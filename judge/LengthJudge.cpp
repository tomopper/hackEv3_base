#include "LengthJudge.h"

LengthJudge::LengthJudge()
{

    float mStartlength = 0;
    float mFinishlength = 0;
}
void LengthJudge::setStartLength()
{}

void LengthJudge::setFinLength(float finlength)
{
    //終了値

    mFinishlength = finlength + mStartlength;
}
bool LengthJudge::run()
{

    if(){
        if (mLength->getValue() >=  mFinishlength)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

void LengthJudge::init(){

    mStartlength = mLength->getValue();
}

