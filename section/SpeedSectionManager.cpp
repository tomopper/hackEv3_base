#include "SpeedSectionManager.h"
#include "Section.h"

SpeedSectionManager::SpeedSectionManager() : SectionManager()
{

  // test用初期化
#if defined(MAKE_RIGHT)
  const int _EDGE = LineTracer::LEFTEDGE;
#else
  const int _EDGE = LineTracer::RIGHTEDGE;
#endif

  for (n = 0; wp[n].flag != -1; n++)
  {

    Section *sc = new Section();

    setWalker(sc);
    setJudge(sc);

    addSection(sc);
  }

  /*  Section* sc = new Section();

    VirtualLineTracer2* Virtual2 = (VirtualLineTracer2*)sc->selectWalker(Section::VIRTUAL2);
  
    Virtual2->setAbsTurnAngle(-20);
    Virtual2->setParam(10,5, 0.2, 0.2,1,1);
    LengthJudge* Length = (LengthJudge*)sc->selectJudge(Section::LENGTH);
    Length->setStartLength();
    Length->setFinLength(40);

    addSection(sc);

    sc = new Section();

    VirtualLineTracer2* Virtual2 = (VirtualLineTracer2*)sc->selectWalker(Section::VIRTUAL2);
  
    Virtual2->setAbsTurnAngle(-45);
    Virtual2->setParam(10,5, 0.2, 0.2,1,1);
    LengthJudge* Length = (LengthJudge*)sc->selectJudge(Section::LENGTH);
    Length->setStartLength();
    Length->setFinLength(40);

    addSection(sc);
*/

  // Section* sc = new Section();
  // addSection(sc);

  /* for(int num=0;p[num].flag==-1;num++){
        Section* sc = new Section();
        SimpleWalker* Walker = (SimpleWalker*)sc->selectWalker(p[num].walk);



        addSection(sc);
    }*/
  /* Section* sc = new Section();
    SimpleWalker* Walker = (SimpleWalker*)sc->selectWalker(Section::WALKER);
    Walker->setCommand(0,10);
    TurnAngleJudge* TurnAngle = (TurnAngleJudge*)sc->selectJudge(Section::TURNANGLE);
    TurnAngle->setStartAngle();
    TurnAngle->setFinishAngle(-90);
    addSection(sc);
*/

  /* Section* sc = new Section();

    VirtualLineTracer2* Virtual2 = (VirtualLineTracer2*)sc->selectWalker(Section::VIRTUAL2);
  
    Virtual2->setAbsTurnAngle(0);
    Virtual2->setParam(40,2, 0.2,0.2,1,1);
    LengthJudge* Length = (LengthJudge*)sc->selectJudge(Section::LENGTH);
    Length->setStartLength();
    Length->setFinLength(90);

    addSection(sc);*/

  /* sc = new Section();

    VirtualLineTracer2* Virtual2 = (VirtualLineTracer2*)sc->selectWalker(Section::VIRTUAL2);
  
    Virtual2->setAbsTurnAngle(-45);
    Virtual2->setParam(10,5, 0.2, 0.2,1,1);
    LengthJudge* Length = (LengthJudge*)sc->selectJudge(Section::LENGTH);
    Length->setStartLength();
    Length->setFinLength(40);

    addSection(sc);
*/

  //LineTracer(ショートカットなし)
  /*  LineTracer* tracer = (LineTracer*)sc->selectWalker(Section::TRACER);
    tracer->setParam(30, 0 ,  30, 0.2, 0.1 );
    tracer->setEdgeMode(_EDGE);
    LengthJudge* Length = (LengthJudge*)sc->selectJudge(Section::LENGTH);
    Length->setStartLength();
    Length->setFinLength(110);
     addSection(sc);
*/
  //  sc = new Section();

  /*    Section* sc = new Section();
    VirtualLineTracer* Virtual = (VirtualLineTracer*)sc->selectWalker(Section::VIRTUAL);


    Virtual->setRound(30);
    Virtual->setParam(10,10, 0, 0,1,1);
    LengthJudge* Length = (LengthJudge*)sc->selectJudge(Section::LENGTH);
    Length->setStartLength();
    Length->setFinLength(100);



    addSection(sc);

    sc = new Section();
    Virtual = (VirtualLineTracer*)sc->selectWalker(Section::VIRTUAL);

    Virtual->setRound(-30);
    Virtual->setParam(10,10, 0, 0,1,1);
    Length = (LengthJudge*)sc->selectJudge(Section::LENGTH);
    Length->setStartLength();
    Length->setFinLength(200);



    addSection(sc);
*/

  /*sc = new Section();
    tracer = (LineTracer*)sc->selectWalker(Section::TRACER);
    tracer->setParam(20, 0 ,  30, 0.2, 0.1 );
    tracer->setEdgeMode(_EDGE);
     Length = (LengthJudge*)sc->selectJudge(Section::LENGTH);
    Length->setStartLength();
    Length->setFinLength(100);
    addSection(sc);

*/

  //Section *sc = new Section();

  // LineTracer テスト
  /*  LineTracer* tracer = (LineTracer*)sc->selectWalker(Section::TRACER);

    tracer->setParam(25, 0 ,  30, 0.2, 0.1 );
    tracer->setEdgeMode(_EDGE);

    LengthJudge* Length = (LengthJudge*)sc->selectJudge(Section::LENGTH);
    Length->setFinLength(150);

     addSection(sc);
    sc = new Section();


  SimpleWalker* Walker = (SimpleWalker*)sc->selectWalker(Section::WALKER);

    Walker->run();
    Walker->setCommand(10,0);


    Length = (LengthJudge*)sc->selectJudge(Section::LENGTH);
    Length->setFinLength(100);
    */
  // VirtualLineTracer* Virtual = (VirtualLineTracer*)sc->selectWalker(Section::VIRTUAL);

  //Virtual->setCenterPosition(0,10);
  //Virtual->setRound(-10);
  //Virtual->setParam(50,2, 0.2, 0,1,1);
  //Virtual->run();

  // VirtualLineTracer2* Virtual2 = (VirtualLineTracer2*)sc->selectWalker(Section::VIRTUAL2);

  // Virtual2->setsPosition(0,0);
  // Virtual2->setfPosition(1000,0);
  // Virtual2->setAbsTurnAngle(30);

  //Virtual2->setParam(20,1, 0.2, 0.2,1,1);

  //LengthJudge* Length = (LengthJudge*)sc->selectJudge(Section::LENGTH);
  //Length->setFinLength(1500);

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
}

void SpeedSectionManager::setWalker(Section *sc)
{

  Walker *walk = sc->selectWalker(wp[n].walk);

  switch (wp[n].walk)
  {
  case Section::VIRTUAL2:

    ((VirtualLineTracer2 *)walk)->setAbsTurnAngle(wp[n].absangle);
    ((VirtualLineTracer2 *)walk)->setParam(wp[n].speed, wp[n].kp, wp[n].ki, wp[n].kd, wp[n].angleTarget, wp[n].anglekp);

    break;
  case Section::WALKER:

    ((SimpleWalker *)walk)->setCommand(wp[n].forward, wp[n].turn);

    break;
  case Section::VIRTUAL:

    ((VirtualLineTracer *)walk)->setRound(wp[n].round);
    ((VirtualLineTracer *)walk)->setParam(wp[n].speed, wp[n].kp, wp[n].ki, wp[n].kd, wp[n].angleTarget, wp[n].anglekp); //(20,2, 0.2, 0,1,1)

    break;
  case Section::TRACER:

    ((LineTracer *)walk)->setParam(wp[n].speed, wp[n].target, wp[n].kp, wp[n].ki, wp[n].kd); //(30, 0 ,  30, 0.2, 0.1 )
    ((LineTracer *)walk)->setEdgeMode(wp[n]._EDGE);

    break;
  }
}

void SpeedSectionManager::setJudge(Section *sc)
{

  Judge *judge = sc->selectJudge(wp[n].judge);

  switch (wp[n].judge)
  {
  case Section::TURNANGLE:

    if (jp[n].lflag == 1)
    {
      ((TurnAngleJudge *)judge)->init();
    }
    ((TurnAngleJudge *)judge)->setFinishAngle(jp[n].fangle);

    break;
  case Section::LENGTH:

    if (jp[n].lflag == 1)
    {
      ((LengthJudge *)judge)->init();
    }
    ((LengthJudge *)judge)->setFinLength(jp[n].flength);

    break;
  case Section::BRIGHTNESS:

    ((BrightnessJudge *)judge)->setBrightness(jp[n].bright1, jp[n].bright2);

    break;
  case Section::COLOR:

    ((ColorJudge *)judge)->setColor(jp[n].color1, jp[n].color2);

    break;
  }
}