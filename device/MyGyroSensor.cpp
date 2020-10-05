#include "MyGyroSensor.h"

MyGyroSensor::MyGyroSensor(ePortS port,
                            AnglerVelocity* angv,
                            GyroAngle* ga):
    mPort(port),
    mAnglerVelocity(angv),
    mGyroAngle(ga)
    
{
    mGyro = new GyroSensor(mPort);
    angvel = 0.0;
    gang = 0.0;
}

void MyGyroSensor::update()
{
    angvel = mGyro->getAnglerVelocity();
    gang = mGyro->getAngle();

    mAnglerVelocity->update(angvel);
    mGyroAngle->update(gang);
}

