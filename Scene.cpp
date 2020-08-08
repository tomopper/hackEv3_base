#include "Scene.h"

#include "ev3api.h"

Scene::Scene():
    mState(UNDEFINED)
{
    mSsm = new SpeedSectionManager();
    bSsm = new BlockSectionManager();
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
        case BINGO:
            execBingo();
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
    mState=START;
}
void Scene::execStart()
{

    // とりあえず動かすだけなので、設計に基づいて書き直そう
    msg_log("Press Touch Button to start.");
    ev3_sensor_config(EV3_PORT_1, TOUCH_SENSOR);
    if (ev3_touch_sensor_is_pressed(EV3_PORT_1) == 1)
    {
            // mState=SPEED;
            mState=BINGO;
    }
}
void Scene::execSpeed()
{
    if(mSsm->run()) {
        delete mSsm;
         msg_log("test length");
        mState = END;
    }
}
void Scene::execBingo()
{  
    if(bSsm->run()) {
        delete bSsm;
        msg_log("test length");
        mState = END;
    }
}
void Scene::execGarage()
{

}
