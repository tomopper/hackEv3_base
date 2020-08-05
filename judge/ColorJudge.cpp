#include "ColorJudge.h"

ColorJudge::ColorJudge()
{
    hue = 0.0;
    satu = 0.0;
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
    if (num - hue >= sa2 && num - hue <= sa1)
    {
        if ((satu - mHsvSatu->getValue()) <= sa3 && (satu - mHsvSatu->getValue()) >= sa4)
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}