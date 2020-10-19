#include "BingoSectionManager.h"



BingoSectionManager::BingoSectionManager() : SectionManager()
{

  // test用初期化

  mState=INIT;
  mBingo = (Bingo*)(new Bingo());
 
  
}

void BingoSectionManager::setWalker(Section *sc)
{

  Walker *walk = sc->selectWalker(wp[n].walk);

  switch (wp[n].walk)
  {
  case Section::VIRTUAL2:
    syslog(LOG_NOTICE,"VIRTUAL2:%d %d",(int)wp[n].speed,(int)wp[n].kp);
    ((VirtualLineTracer2 *)walk)->setAbsTurnAngle(wp[n].absangle);
     ((VirtualLineTracer2 *)walk)->setvangle(wp[n].vangle);
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

void BingoSectionManager::setJudge(Section *sc)
{

  Judge *judge = sc->selectJudge(wp[n].judge);

  switch (wp[n].judge)
  {
  case Section::TURNANGLE:
    ((TurnAngleJudge *)judge)->setupdate(wp[n].jflag);
    ((TurnAngleJudge *)judge)->setFinishAngle(wp[n].fangle);
    break;
  case Section::LENGTH:
     ((LengthJudge *)judge)->setFinLength(wp[n].flength);
      ((LengthJudge *)judge)->setupdate(wp[n].jflag);
    break;
  case Section::BRIGHTNESS:
    ((BrightnessJudge *)judge)->setBrightness(wp[n].bright1, wp[n].bright2);
    break;
  case Section::COLOR:
    ((ColorJudge *)judge)->setColor(wp[n].color1, wp[n].color2);
    break;
      case Section::STOP:
    ((Stop *)judge)->setCount(wp[n].count);
    break;
  }
}
void BingoSectionManager::init(int i){

    
       
    if(_EDGE==0){

       wp=array[i2];
    }
    else{
    
       wp=array[i2+10];
    }
     
      wp=array[i];
      for (n = 0; wp[n].flag != -1; n++)
      {

        Section *sc = new Section();

        setWalker(sc);
        setJudge(sc);

        addSection(sc);
      }
    



}


bool BingoSectionManager::exe_run()
{
    if(mSection[mSectionIdx]==nullptr)
        return true;
  //  if(mSectionIdx==0)
    // msg_log("0");
    //if(mSectionIdx==1)
    // msg_log("1");
    if(mSection[mSectionIdx]->run())
        mSectionIdx++;
    return false;
}
bool BingoSectionManager::run(){
 
  bool ex;
   return true;
  switch(mState){
    case INIT:
        init(i2);
        mState=RUN;
    case RUN:
        ex=exe_run();
      
        mState=NUMBER;
    break;
    case NUMBER:
      exe_number();
      mState=INIT;
    break;
  }

  return  ex;
}

bool BingoSectionManager::exe_number(){
    i2=ETRoboc_getCourceInfo(ETROBOC_COURSE_INFO_BLOCK_NUMBER);
}


