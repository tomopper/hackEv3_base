#include "Polling.h"

Polling::Polling(MyColorSensor *col,
                 Odometry *odo,
                 MyGyroSensor *gyro):
    mColor(col),
    mOdo(odo),
    mGyro(gyro)
{

}

void Polling::run()
{
    mColor->update();
    mOdo->update();
    mGyro->update();    
}
