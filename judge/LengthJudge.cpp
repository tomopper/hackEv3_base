#include "LengthJudge.h"
#include "util.h"

extern float gStart;

LengthJudge::LengthJudge()
{

    float mStartlength = 0;
    float mFinishlength = 0;
}
void LengthJudge::setFinLength2()
{
     mFinishlength = mFinishlength + mStartlength;
}

void LengthJudge::setFinLength(float finlength)
{
    //終了値

    mFinishlength = finlength;
     

}
bool LengthJudge::run()
{


   

    if (mFinishlength > mStartlength)
    {


     
        if (mLength->getValue() >= mFinishlength)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (mLength->getValue() < mFinishlength)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

void LengthJudge::init()
{
    if(update == Judge::UPDATE){
        gStart = mLength->getValue();
        mStartlength=gStart;
        mFinishlength = mFinishlength + gStart;
    }
    else{
    
        mStartlength=gStart;
        mFinishlength = mFinishlength + gStart;
    }


}

void LengthJudge::setupdate(Judge::JUDGE_MODE a){
        update=a;

}