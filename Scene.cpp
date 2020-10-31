#include "Scene.h"
#include "util.h"
#include "ev3api.h"
#include "etroboc_ext.h"

Scene::Scene() : mState(UNDEFINED)
{
    mSsm = new SpeedSectionManager();
   // mSlm = new SlalomSectionManager();
   // mGsm = new GarageSectionManager();

       msg_f("Scene Constructed!",1);

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
        case FINISH:
            execEnd();
            break;
        default:
            return true;
    }
    return false;
}

void Scene::execUndefined()
{
        static char buf[256];

    msg_f("repare Touch Button",1);
    int ret = ev3_sensor_config(EV3_PORT_1, TOUCH_SENSOR);
    msg_f("Press Touch Button to start.",1);
    sprintf(buf,"ER %d",ret);
    msg_f(buf,2);
    mState = START;
}
void Scene::execStart()
{
    static char buf[256];
    static int cnt=0;

    // とりあえず動かすだけなので、設計に基づいて書き直そう
    bool touch=false;
    if(cnt++==5) {
        touch = ev3_touch_sensor_is_pressed(EV3_PORT_1);
        cnt=0;
    }
    sprintf(buf,"touch %d",touch);
    msg_f(buf,3);
    if (touch )
    {
            msg_f("pressed ",2);
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
        // mState = FINISH;
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
        
        mState = FINISH;
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
        // mState = FINISH;
    }
}
void Scene::execEnd()
{
    // msg_log("finish!");
    ETRoboc_notifyCompletedToSimulator();

} 