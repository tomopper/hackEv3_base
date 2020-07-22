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

static void user_system_create() {

  gBrightness = new Brightness();
  gHue = new HsvHue();
  gSatu = new HsvSatu();

  gColor = new MyColorSensor(PORT_2,gBrightness,gHue,gSatu);
  gLength = new Length();
  gTurnAngle = new TurnAngle();
  gVelocity = new Velocity();

  gOdo = new Odometry(gLeftWheel,gRightWheel,gLength,gTurnAngle,gVelocity);

  gPolling = new Polling(gColor,gOdo);

}
static void user_system_destroy() {

  delete gColor;
  delete gPolling;

}


void main_task(intptr_t unused) {
  user_system_create();

  sta_cyc(POLLING_CYC);

  slp_tsk();

  stp_cyc(POLLING_CYC);

  ext_tsk();
}
// end::main_task[]

void polling_task(intptr_t unused) {

  gArm->setPWM(0);
  gArm->setBrake(true);
  gLeftWheel->setPWM(8);
  gRightWheel->setPWM(10);
  gPolling->run();

    Measure *m = gBrightness;
    float br = m->getValue(); 
    float len = gLength->getValue();
    float turn = gTurnAngle->getValue();
    float v = gVelocity->getValue();
    float h = gHue->getValue();
    float s = gSatu->getValue();

    static char buf[100];
    sprintf(buf,"bri,H,S len, turn, v : %7.4f, %5.1f, %3.2f ,%3.1f, %4.2f, %4.2f ",br,h,s,len,turn,v);
    msg_log(buf);

  ext_tsk();
}