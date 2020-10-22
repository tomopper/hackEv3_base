#ifndef _GYROJUDGE_H_
#define _GYROJUDGE_H_

#include "Judge.h"

class GyroJudge : public Judge
{
    public:
        GyroJudge();
        void setVib(float v);
        bool run();

    private:
        float vib; // 揺れ
        float g;

};

#endif