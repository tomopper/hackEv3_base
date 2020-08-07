#include "BlockSectionManager.h"
#include "Section.h"

BlockSectionManager::BlockSectionManager()
{
    // test用初期化
 #if defined(MAKE_RIGHT)
      const int _EDGE = LineTracer::LEFTEDGE;
#else
      const int _EDGE = LineTracer::RIGHTEDGE;
#endif
    Section *sc = new Section();
    
    // LineTracer テスト
    LineTracer* tracer = (LineTracer*)sc->selectWalker(Section::TRACER);

    tracer->setParam(25, 0 ,  30, 0.2, 0.1 );
    tracer->setEdgeMode(_EDGE);


  //  SimpleWalker* Walker = (SimpleWalker*)sc->selectWalker(Section::WALKER);

   // Walker->run();
   // Walker->setCommand(10,0);
/*
    VirtualLineTracer* Virtual = (VirtualLineTracer*)sc->selectWalker(Section::VIRTUAL);

    Virtual->setCenterPosition(20,20);
    Virtual->setParam(25,30, 0.2, 0.1,1,1);
    Virtual->run();
*/


    LengthJudge* Length = (LengthJudge*)sc->selectJudge(Section::LENGTH);
    Length->setFinLength(150);

    //TurnAngleJudge* TurnAngle = (TurnAngleJudge*)sc->selectJudge(Section::TURNANGLE);
    //TurnAngle->setFinishAngle(90);


    //BrightnessJudge* Brightness = (BrightnessJudge*)sc->selectJudge(Section::BRIGHTNESS);
    //Brightness->setBrightness(0,0);


    //ColorJudge* Color = (ColorJudge*)sc->selectJudge(Section::COLOR);
    //Color->setColor(140,0);

    /*
    // SimpleWalkerテスト
    SimpleWalker* walker = (SimpleWalker*)sc->selectWalker(Section::WALKER);
    walker->setCommand(10,10);
    */
    addSection(sc);

}

bool BlockSectionManager::run()
{
    if(mSection[mSectionIdx]->run())
        return true;

    return false;
}