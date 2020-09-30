#include "AnglerVelocity.h"

AnglerVelocity::AnglerVelocity()
    :Measure()
{

}

float AnglerVelocity::getValue()
{
    return angvelo;
}

void AnglerVelocity::update(float a)
{
    angvelo = a;
}