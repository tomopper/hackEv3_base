// tag::walker_def[]
#include "app.h"
#include "util.h"

#include "Motor.h"

#include "Polling.h"
#include "MyColorSensor.h"
#include "Brightness.h"
#include "Length.h"
#include "TurnAngle.h"
#include "Odometry.h"
#include "Velocity.h"
#include "HsvHue.h"
#include "HsvSatu.h"
#include "SimpleWalker.h"
#include "SpeedControl.h"
#include "LineTracer.h"

using namespace ev3api;

Motor       *gLeftWheel = new Motor(PORT_C,false,LARGE_MOTOR);
Motor       *gRightWheel = new Motor(PORT_B,false,LARGE_MOTOR);
Motor       *gArm = new Motor(PORT_A,true,LARGE_MOTOR);

Polling *gPolling;
MyColorSensor *gColor;
Brightness *gBrightness;
HsvHue *gHue;
HsvSatu *gSatu;

Odometry *gOdo;
Length *gLength;
TurnAngle *gTurnAngle;
Velocity *gVelocity;

SpeedControl *gSpeed;
SimpleWalker *gWalker;
LineTracer *gTracer;


static void user_system_create() {

  gBrightness = new Brightness();
  gHue = new HsvHue();
  gSatu = new HsvSatu();

  gColor = new MyColorSensor(PORT_2,gBrightness,gHue,gSatu);
  gLength = new Length();
  gTurnAngle = new TurnAngle();
  gVelocity = new Velocity();

  gOdo = new Odometry(gLeftWheel,gRightWheel,gLength,gTurnAngle,gVelocity);
  gSpeed = new SpeedControl(gOdo,gVelocity);  
  gWalker = new SimpleWalker(gOdo,gSpeed); 
  gTracer = new LineTracer(gOdo,gSpeed);

  gPolling = new Polling(gColor,gOdo);


}
static void user_system_destroy() {

  delete gColor;
  delete gPolling;

}


void main_task(intptr_t unused) {
  user_system_create();

  sta_cyc(POLLING_CYC);
  sta_cyc(TRACER_CYC);

  slp_tsk();

  stp_cyc(POLLING_CYC);
  stp_cyc(TRACER_CYC);

  gLeftWheel->setPWM(0);
  gRightWheel->setPWM(0);

  ext_tsk();

  user_system_destroy();
}
// end::main_task[]

void polling_task(intptr_t unused) {

  gPolling->run();

    Measure *m = gBrightness;
    float br = m->getValue(); 
    float len = gLength->getValue();
    float turn = gTurnAngle->getValue();
    float v = gVelocity->getValue();
    float h = gHue->getValue();
    float s = gSatu->getValue();

    static char buf[100];
    sprintf(buf,"bri,H,S len, turn, v : %7.4f, %5.1f, %3.2f ,%3.3f, %4.2f, %4.2f ",br,h,s,len,turn,v);
    msg_log(buf);

  ext_tsk();
}

void tracer_task(intptr_t unused) {

  if (ev3_button_is_pressed(BACK_BUTTON)) {
    wup_tsk(MAIN_TASK);  // 左ボタン押下でメインを起こす
  } else {
    int arm_cnt = gArm->getCount();
   // syslog(LOG_NOTICE,"%d",arm_cnt);
    int diff = -50 - arm_cnt;
#if defined(MAKE_SIM)
    gArm->setPWM(diff*4.0);
#endif

    /*gWalker->setCommandV(10,0);
    gWalker->run();
    */
#if defined(MAKE_RIGHT)
      const int _EDGE = LineTracer::LEFTEDGE;
#else
      const int _EDGE = LineTracer::RIGHTEDGE;
#endif

    gTracer->setParam(25, 0 ,  30, 0.2, 0.1 );
    gTracer->setEdgeMode(_EDGE);
    gTracer->run();

  }

  ext_tsk();
}