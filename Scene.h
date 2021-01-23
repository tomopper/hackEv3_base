#ifndef _SCENE_H_
#define  _SCENE_H_

#include "SpeedSectionManager.h"
#include "BingoSectionManager.h"
#include "ev3api.h"
#include "global.h"

class Scene{
    public:
        Scene();
        bool run();
        void execUndefined();
        void execStart();
        void execSpeed();
        void execBingo();
        void execGarage();
        void initSpeed();
        void initBingo();
        void finish();

    private:
        enum State {
            UNDEFINED,
            START,
            INIT_SPEED,
            SPEED,
            INIT_BINGO,
            BINGO,
            GARAGE,
            END
        };

        State mState;

        SpeedSectionManager *mSsm;
        BingoSectionManager *mBsm;
        FILE  *bt = NULL;

};
#endif
