#include "ArmAngle.h"

//#define BTLOG
ArmAngle::ArmAngle():
    Measure()
{
#ifdef BTLOG
      bt = ev3_serial_open_file(EV3_SERIAL_BT);
	  get_tim(&start_tim); 
#endif
    
}

float ArmAngle::getValue()
{
#ifdef BTLOG
    get_tim(&now_tim); 
    fprintf(bt,"arm:%d,%f\n",(int)(now_tim-start_tim),mArmAngle);
#endif
    // return mArmAngle;
    return mLpf->getFillteredValue();
}

void ArmAngle::update(float arm)
{
    mLpf->addValue(arm);
    mArmAngle = arm;
}