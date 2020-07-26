#include "Velocity.h"

Velocity::Velocity()
    : Measure()
{
    mCounts_idx=0;
    for(int i=0;i<MAX_CNT;i++) {
        mCounts1[i]=0;
        mCounts2[i]=0;
    }
}

float Velocity::getValue()
{
    int nextConts_idx = mCounts_idx+1;
    if(nextConts_idx==MAX_CNT)
        nextConts_idx=0;

    float left_len =  (mCounts1[mCounts_idx]-mCounts1[nextConts_idx])*D_LEFT*M_PI/360;
    float right_len = (mCounts2[mCounts_idx]-mCounts2[nextConts_idx])*D_RIGHT*M_PI/360;
    mVelocity = (left_len+right_len)/(2.0*DELTA*MAX_CNT);
    return mVelocity;
}

void Velocity::update(float cnt1,float cnt2)
{
    if(++mCounts_idx==MAX_CNT)
        mCounts_idx=0;

    mCounts1[mCounts_idx] = cnt1;
    mCounts2[mCounts_idx] = cnt2;

}