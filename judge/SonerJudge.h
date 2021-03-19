#ifndef _SONERJUDGE_H_
#define _SONERJUDGE_H_

#include "Judge.h"

class SonerJudge : public Judge
{
    public:
        SonerJudge();
        void setLength(float len,int d);
        bool run();

    private:
        int mDir; // 揺れ
        float mLen;

};

#endif