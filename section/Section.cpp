#include "Section.h"

extern SimpleWalker *gWalker;
extern LineTracer *gTracer;
 
Section::Section()
{
    mTracer = gTracer;
    mWalker = gWalker;
}

bool Section::run()
{
 #if defined(MAKE_RIGHT)
      const int _EDGE = LineTracer::LEFTEDGE;
#else
      const int _EDGE = LineTracer::RIGHTEDGE;
#endif
       // for test
    mTracer->setParam(25, 0 ,  30, 0.2, 0.1 );
    mTracer->setEdgeMode(_EDGE);
    mTracer->run();
    return false;
}