#include "SpeedSectionManager.h"
#include "Section.h"

struct Param
{
    float speed;
    float target;
    float kp;
    float ki;
    float kd;
    float angleTarget;
    float anglekp;

};

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
/*  LineTracer* tracer = (LineTracer*)sc->selectWalker(Section::TRACER);
    tracer->setParam(30, 0 ,  30, 0.2, 0.1 );
    tracer->setEdgeMode(_EDGE);
    LengthJudge* Length = (LengthJudge*)sc->selectJudge(Section::LENGTH);
    Length->setStartLength();
    Length->setFinLength(110);
     addSection(sc);
*/
  //  sc = new Section();
    VirtualLineTracer* Virtual = (VirtualLineTracer*)sc->selectWalker(Section::VIRTUAL);

    Virtual->setCenterPosition(0,10);
    Virtual->setRound(-30);
    Virtual->setParam(10,50, 10, 0,1,1);
    LengthJudge* Length = (LengthJudge*)sc->selectJudge(Section::LENGTH);
    Length->setStartLength();
    Length->setFinLength(10000);



    addSection(sc);
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

