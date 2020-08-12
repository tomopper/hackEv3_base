#include "SpeedSectionManager.h"
#include "Section.h"

SpeedSectionManager::SpeedSectionManager():
  SectionManager()
{
    // test用初期化
#if defined(MAKE_RIGHT)
      const int _EDGE = LineTracer::LEFTEDGE;
#else
      const int _EDGE = LineTracer::RIGHTEDGE;
#endif

Section* sc = new Section();
//LineTracer(ショートカットなし)
  LineTracer* tracer = (LineTracer*)sc->selectWalker(Section::TRACER);
    tracer->setParam(30, 0 ,  30, 0.2, 0.1 );
    tracer->setEdgeMode(_EDGE);
    LengthJudge* Length = (LengthJudge*)sc->selectJudge(Section::LENGTH);
    Length->setStartLength();
    Length->setFinLength(150);
    addSection(sc);
    sc = new Section();
    tracer = (LineTracer*)sc->selectWalker(Section::TRACER);
    tracer->setParam(20, 0 ,  30, 0.2, 0.1 );
    tracer->setEdgeMode(_EDGE);
     Length = (LengthJudge*)sc->selectJudge(Section::LENGTH);
    Length->setStartLength();
    Length->setFinLength(100);
    addSection(sc);

}

