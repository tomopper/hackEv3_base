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

    private:
        enum State {
            UNDEFINED,
            START,
            SPEED,
            BINGO,
            GARAGE,
            END
        };

        State mState;

        SpeedSectionManager *mSsm;
};
#endif
