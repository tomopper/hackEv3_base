#ifndef _LENGTHJUDGE_H_
#define _LENGTHJUDGE_H_

#include "Judge.h"
class LengthJudge : public Judge{
    public:
    LengthJudge();
    void setStartLength();
    void setFinLength(float finlength);
    bool run();
    void init();

    private:
    float mStartlength;
    float mFinishlength;



};



#endif