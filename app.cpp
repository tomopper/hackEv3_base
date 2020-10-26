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
#include "MyGyroSensor.h"
#include "MySonarSensor.h"
#include "TailWalker.h"
#include "TailAngle.h"
#include "ArmWalker.h"
#include "ArmAngle.h"
#include "AnglerVelocity.h"
#include "GyroAngle.h"

#include "Scene.h"

using namespace ev3api;

Motor       *gLeftWheel;
Motor       *gRightWheel;
Motor       *gArm;
Motor       *gTail;

Polling *gPolling;
MyColorSensor *gColor;
Brightness *gBrightness;
HsvHue *gHue;
HsvSatu *gSatu;
XPosition *gXPosition;
YPosition *gYPosition;
MyGyroSensor *gGyro;
MySonarSensor *gSonar;

Odometry *gOdo;
Length *gLength;
TurnAngle *gTurnAngle;
Velocity *gVelocity;
TailAngle *gTailAngle;
ArmAngle *gArmAngle;
AnglerVelocity *gAnglerVelocity;
GyroAngle *gGyroAngle;

SpeedControl *gSpeed;
SimpleWalker *gWalker;
LineTracer *gTracer;
TailWalker *gTailWalker;
ArmWalker *gArmWalker;

Scene *gScene;
float gStart;
float gStartAngle;

static void user_system_create() {
  gLeftWheel = new Motor(PORT_C,false,LARGE_MOTOR);
  gRightWheel = new Motor(PORT_B,false,LARGE_MOTOR);
  gArm = new Motor(PORT_A,true,LARGE_MOTOR);
  gTail = new Motor(PORT_D,true,MEDIUM_MOTOR);

  gBrightness = new Brightness();
  gHue = new HsvHue();
  gSatu = new HsvSatu();
  gAnglerVelocity = new AnglerVelocity();
  gGyroAngle = new GyroAngle();

  gColor = new MyColorSensor(PORT_2,gBrightness,gHue,gSatu);
  gLength = new Length();
  gTurnAngle = new TurnAngle();
  gVelocity = new Velocity();
  gXPosition = new XPosition();
  gYPosition = new YPosition();
  gSonar = new MySonarSensor(PORT_3);
  gTailAngle = new TailAngle();
  gArmAngle = new ArmAngle();
  gGyro = new MyGyroSensor(PORT_4,gAnglerVelocity,gGyroAngle);

  gOdo = new Odometry(gLeftWheel,gRightWheel,gLength,gTurnAngle,gVelocity,gXPosition,gYPosition,gTail,gTailAngle,gArm,gArmAngle);

  gSpeed = new SpeedControl(gOdo,gVelocity);  
  gWalker = new SimpleWalker(gOdo,gSpeed); 
  gTracer = new LineTracer(gOdo,gSpeed);
  gTailWalker = new TailWalker(gOdo,gSpeed);
  gArmWalker = new ArmWalker(gOdo,gSpeed);



  gPolling = new Polling(gColor,gOdo,gGyro,gSonar);

  gScene = new Scene();

  gTailWalker->setPwm(0,1,0,0);
  gArmWalker->setPwm(-50,1,0,0);

}
static void user_system_destroy() {

  delete gColor;
  delete gPolling;

  delete gSpeed;
}


void main_task(intptr_t unused) {
  user_system_create();

  //sta_cyc(POLLING_CYC);
  sta_cyc(TRACER_CYC);

  slp_tsk();
  msg_f("waik up",0);
 // stp_cyc(POLLING_CYC);
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

    rgb_raw_t rgb = gColor->getRgb();
    static char buf[100];
    //sprintf(buf,"len , bri,H,S r,g,b, turn, v : %3.3f,  %7.4f,  %5.1f, %3.2f, %d,%d,%d  , %4.2f, %4.2f ",len,br,h,s,  rgb.r, rgb.g,rgb.b ,turn,v);
    //msg_log(buf);

  ext_tsk();
}

void tracer_task(intptr_t unused) {

  if (ev3_button_is_pressed(BACK_BUTTON)) {
    wup_tsk(MAIN_TASK);  // 左ボタン押下でメインを起こす
  } else {

    // とりあえずここで、アームの固定。設計に基づいて変えるべし
    int arm_cnt = gArm->getCount();
   // syslog(LOG_NOTICE,"%d",arm_cnt);
    int diff = -50 - arm_cnt;
#if defined(MAKE_SIM)
    //gArm->setPWM(diff*4.0);
#endif
  // しっぽ制御
    
    gTailWalker->run();
    gArmWalker->run();
    gScene->run();
  }

  ext_tsk();
}