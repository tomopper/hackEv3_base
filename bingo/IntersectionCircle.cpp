#include "IntersectionCircle.h"
#include "util.h"
IntersectionCircle::IntersectionCircle(int x, int y, int color)
:BlockStorage(x,y,color)
{
    printf("IntersectionCircle  %d,%d,%d\n" , x,y,color);
}
