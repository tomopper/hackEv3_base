#include "ColorJudge.h"
#include <cmath>  


ColorJudge::ColorJudge()
{
    hue = 0.0;
    satu = 0.0;
    num=0;
}
void ColorJudge::setColor(float h, float s)
{
    hue = h;
    satu = s;
}
bool ColorJudge::run()
{
    if ((hue - mHsvHue->getValue()) >= 180)
    {
        num = hue + mHsvHue->getValue();
    }
    else{
        num=mHsvHue->getValue();
    }
    if (fabs(hue - num) >= sa2 && fabs(hue - num )<= sa1)
    {
        if ((mHsvSatu->getValue()) >= satu)
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}