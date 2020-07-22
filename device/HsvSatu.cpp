#include "HsvSatu.h"

HsvSatu::HsvSatu()
    : Measure()
{

}

float HsvSatu::getValue()
{
    return mSatu;
}

void HsvSatu::update(float s)
{
    mSatu = s;
}