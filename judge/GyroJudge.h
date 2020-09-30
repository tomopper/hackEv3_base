#ifndef _GYROJUDGE_H_
#define _GYROJUDGE_H_

#include "Judge.h"

class GyroJudge : public Judge
{
    public:
        GyroJudge();
        void setVib(float v, int f);
        bool run();

    private:
        float vib; // 揺れ
        int flag;

};

#endif