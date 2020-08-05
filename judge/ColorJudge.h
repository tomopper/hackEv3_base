#ifndef _BRIGHTNESSJUDGE_H_
#define _BRIGHTNESSJUDGE_H_
#include "judge.h"

class ColorJudge::public :judge{
    public:
    ColorJudge();
    void setColor(float h,float s);
    bool run();

    private:
    float hue;
    float satu;
    float sa1 =20  //色の誤差
    float sa2 =-20  //色の誤差
    float sa3 =1  //彩度の誤差
    float sa4 =-1  //彩度の誤差    
    float num
    




};



#endif



