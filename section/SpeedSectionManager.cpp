#include "SpeedSectionManager.h"
#include "Section.h"
#include "util.h"
#include "ev3api.h"
#include <Motor.h>
#include "HBTtask.h"
#include "global.h"

#include "math.h"
#define PI 3.14159265359

SpeedSectionManager::SpeedSectionManager() : SectionManager()
{

}

void SpeedSectionManager::setWalker(Section *sc)
{

  Walker *walk = sc->selectWalker(wp[n].walk);
  
  switch (wp[n].walk)
  {
  case Section::VIRTUAL2:
    syslog(LOG_NOTICE,"VIRTUAL2:%d %d",(int)wp[n].speed,(int)wp[n].kp);
    ((VirtualLineTracer2 *)walk)->setAbsTurnAngle(wp[n].absangle);
     ((VirtualLineTracer2 *)walk)->setvangle(wp[n].vangle);
    ((VirtualLineTracer2 *)walk)->setParam(wp[n].speed, wp[n].kp, wp[n].ki, wp[n].kd, wp[n].angleTarget, wp[n].anglekp);

    //((VirtualLineTracer2 *)walk)->setAbsTurnAngle(0);
     //((VirtualLineTracer2 *)walk)->setvangle(wp[n].vangle);
    //((VirtualLineTracer2 *)walk)->setParam(30, 18.0, 19.0, 18.5, 0, 0);
    break;
  case Section::WALKER:

    //tslp_tsk(10000);,

    syslog(LOG_NOTICE,"WAKER2222:%d %d %d",n,(int)wp[n].forward,(int)wp[n].turn);

    ((SimpleWalker *)walk)->setCommandV(wp[n].forward, wp[n].turn);

    break;
  case Section::VIRTUAL:

    //tslp_tsk(10000);

    ((VirtualLineTracer *)walk)->setRound(wp[n].round);
    ((VirtualLineTracer *)walk)->setParam(wp[n].speed, wp[n].kp, wp[n].ki, wp[n].kd, wp[n].angleTarget, wp[n].anglekp); //(20,2, 0.2, 0,1,1)

    break;
  case Section::TRACER:

    //tslp_tsk(10000);

    ((LineTracer *)walk)->setParam(wp[n].speed, wp[n].target, wp[n].kp, wp[n].ki, wp[n].kd, wp[n].angleTarget, wp[n].anglekp); //(30, 0 ,  30, 0.2, 0.1 )
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

bool SpeedSectionManager::init(){

    reset();
    static char buf[256];
    sprintf(buf,"%d,EDGE",_EDGE);
    msg_log(buf);
    if(_EDGE==0){
      wp = array[0];
    }
    else{
      wp = array[1];
    }

    double cita = atan(getLength());
    double fir = 180/PI;
		cita = cita/fir;

    setAbsangle(cita);

    switch(getFlag())
    {
      case 0://forward
          a2[0].forward = getFwd();
          a2[0].absangle = getAbsangle();
          msg_f("forward",4);
          break;
      case 1://赤い停止線
          a2[0].flength = getLength();
          a2[1].absangle = 90;
          msg_f("redstop",4);
          break;
      default:
          break;
    }
    
    for (n = 0; wp[n].flag != -1; n++)
    {
      //a2[0].forward = getFwd();
      //a2[0].absangle = getAbsangle();

      Section *sc = new Section();            

      setWalker(sc);
      setJudge(sc);

     addSection(sc);
    }
    
    if (getSendchar2() == 'G')
    {
      setSendchar('R');
      return true;
    }
    return false;

   /*
   n = 0;
   if (getSendchar2() == 'G')
   {

     a2[0].absangle = getAbsangle();

     Section *sc = new Section();

     setWalker(sc);
     setJudge(sc);

     addSection(sc);
     return true;
   }
   return false;
   */
}