#ifndef _SCENE_H_
#define  _SCENE_H_

#include "SpeedSectionManager.h"
#include "SlalomSectionManager.h"

class Scene{
    public:
        Scene();
        bool run();
        void execUndefined();
        void execStart();
        void execSpeed();
        void execSlalom();
        void execGarage();

    private:
        enum State {
            UNDEFINED,
            START,
            SPEED,
            SLALOM,
            GARAGE,
            END
        };

        State mState;

        SpeedSectionManager *mSsm;
        SlalomSectionManager *mSlm;
};
#endif
