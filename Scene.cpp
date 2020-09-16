#include "Scene.h"

#include "ev3api.h"

Scene::Scene() : mState(UNDEFINED)
{
    mSsm = new SpeedSectionManager();
    mSlm = new SlalomSectionManager();
    mGsm = new GarageSectionManager();
}

bool Scene::run()
{
    switch(mState) {
        case UNDEFINED:
            execUndefined();
            break;
        case START:
            execStart();
            break;
        case SPEED:
            execSpeed();
            break;
        case INIT_SLALOM:
            initSlalom();
            break;
        case SLALOM:
            execSlalom();
            break;
        case INIT_GARAGE:
            initGarage();
            break;
        case INIT_SPEED:
            initSpeed();
            break;
        case GARAGE:
            execGarage();
            break;
        default:
            return true;
    }
    return false;
}

void Scene::execUndefined()
{
    msg_log("Press Touch Button to start.");
    ev3_sensor_config(EV3_PORT_1, TOUCH_SENSOR);
    mState = START;
}
void Scene::execStart()
{
    // とりあえず動かすだけなので、設計に基づいて書き直そう
    if (ev3_touch_sensor_is_pressed(EV3_PORT_1) == 1)
    {
            mState=INIT_SPEED;
    }
}
void Scene::execSpeed()
{
    if (mSsm->run())
    {
        delete mSsm;
        // msg_log("test length");
        mState = INIT_GARAGE;
    }
}

void Scene::initSlalom(){
    mSlm->init();
    mState=SLALOM;
}
void Scene::initSpeed(){
    mSsm->init();
    mState = SPEED;
}

void Scene::execSlalom()
{
    if(mSlm->run()){
        delete mSlm;
        // msg_log("Tail test");
        mState = END;
    }
}
void Scene::initGarage()
{
    mGsm->init();
    mState=GARAGE;
}
void Scene::execGarage()
{
    if(mGsm->run()){
        delete mGsm;
        mState = INIT_SLALOM;
    }
}
