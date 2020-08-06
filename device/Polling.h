#ifndef __POLLING_H__
#define __POLLING_H__

#include "MyColorSensor.h"
#include "Odometry.h"
#include "MyGyroSensor.h"

class Polling
{
    public:
        Polling(MyColorSensor *col,
                Odometry *odo,
                MyGyroSensor *gyro);
        void run();

    private:
        MyColorSensor *mColor;
        Odometry *mOdo;
        MyGyroSensor *mGyro;

};

#endif

