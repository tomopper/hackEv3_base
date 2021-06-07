#ifndef _COLOR_H_
#define _COLOR_H_
#include "Judge.h"

class ColorJudge :public Judge{
    public:
    ColorJudge();
    void setColor(float h,float s);
    bool run();

    private:
    float hue;
    float satu;
    float sa1 = 30;     //色の誤差
    float sa2 = 0;      //色の誤差
    float sa3 = 0.1;    // 彩度の誤差
    float sa4 = 0;      // 彩度の誤差
    float num;
    




};



#endif



