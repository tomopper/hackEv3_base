#ifndef _SCENE_H_
#define  _SCENE_H_

#include "SpeedSectionManager.h"

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

    private:
        enum State {
            UNDEFINED,
            START,
            INIT_SPEED,
            SPEED,
            BINGO,
            GARAGE,
            END
        };

        State mState;

        SpeedSectionManager *mSsm;
};
#endif
