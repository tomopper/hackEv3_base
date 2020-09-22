#include "Polling.h"

Polling::Polling(MyColorSensor *col,
                 Odometry *odo,
                 MyGyroSensor *gyro,
                 MySonarSensor *sonar):
    mColor(col),
    mOdo(odo),
    mGyro(gyro),
    mSonar(sonar)
{

}

void Polling::run()
{
    
SYSTIM start_tim;
SYSTIM tim1,tim2,tim3,tim4;
get_tim(&start_tim); 

    mColor->update();
get_tim(&tim1); 
    mOdo->update();
get_tim(&tim2); 
    mGyro->update();
get_tim(&tim3); 
    mSonar->update();    
get_tim(&tim4); 
 //   syslog(LOG_NOTICE,"time:color %d, odo %d, gyro %d, sonar %d",tim1-start_tim, tim2-tim1, tim3-tim2, tim4-tim3);
}
