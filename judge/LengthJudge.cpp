#include "LengthJudge.h"

LengthJudge::LengthJudge()
{

    float mStartlength = 0;
    float mFinishlength = 0;
}
void LengthJudge::setStartLength()
{
    //現在値

    mStartlength = mLength->getValue();
}
void LengthJudge::setFinLength(float finlength)
{
    //終了値

    mFinishlength = finlength + mStartlength;
}
bool LengthJudge::run()
{

    if (mLength->getValue() = > mFinishlength - 5 && mLength->getValue() = < mFinishlength + 5)
    {
        return true;
    }
    else
    {
        return false;
    }
}