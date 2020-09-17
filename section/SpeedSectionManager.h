#ifndef _SPEED_SECTION_MANAGER_H_
#define _SPEED_SECTION_MANAGER_H_
#include "SectionManager.h"

typedef struct _Param1
{

  int flag;
  Section::WALKER_NO walk;
  Section::JUDGE_NO judge;
  float speed;
  float target;
  float kp;
  float ki;
  float kd;
  float angleTarget;
  float anglekp;

  float absangle;
  float round;

  float forward;
  float turn;

  bool _EDGE; //true=left,false=right

  Judge::JUDGE_MODE jflag;

  float fangle;
  float flength;
  float bright1;
  float bright2;
  float color1;
  float color2;
  float count;
  bool vangle;

} wParam;

class SpeedSectionManager : public SectionManager
{
public:
  SpeedSectionManager();
  void init();

protected:
private:
  int n;

  //{-1の時終了, Section::使いたいwalker, Section::使いたいjudge, 速度, 0, pの値, dの値, iの値, 0, 0 ,
  ///*setparam*/, 直線仮想ライントレースの角度, 円仮想ライントレースの半径, 単純走行のパワー, 単純走法の曲がり具合, 線のどちらを進むか,
  //1の時現在地を更新可能, 終了角度, 終了距離,白黒割合 , 白黒計測フラグ, 色数値, 彩度数値,止まる秒数}

  //setparamの例,Virtual2->setParam(10,5, 0.2, 0.2,1,1)
  // tracer->setParam(30,0,30,0.2,0.1)
  //Virtual->setParam(20,2,0.2,0,1,1)
  //Walker->setCommand(0,10)

  #if defined(MAKE_RIGHT)
  const int _EDGE = LineTracer::LEFTEDGE;
#else
  const int _EDGE = LineTracer::RIGHTEDGE;
#endif

  wParam a[100] = {{0, Section::VIRTUAL2, Section::LENGTH, 40, 0, 0.01, 0, 0, 1, 1 /*setparam*/, 0, 0, 30, 0, true, Judge::UPDATE, 0, 57.7, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::LENGTH, 30, 0, 6, 0.2, 0.1, 0, 0 /*setparam*/, 0, 63, 0, 30, false, Judge::UPDATE, 0, 107.5, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::LENGTH, 15, 0, 30, 0.3, 0.2, 1, 1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::LENGTH, 25, 0, 20, 0.3, 0.2, 1, 1 /*setparam*/, 0, 0, 0, 30, true, Judge::UNUPDATE, 0, 15, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::LENGTH, 35, 0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 25, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::LENGTH, 20, 0, 30, 0.2, 0.1, 0.8, 1 /*setparam*/, 0, 0, 0, 30, true, Judge::UNUPDATE, 0, 90, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, 20, 0, 0.1, 0, 0, 0, 0 /*setparam*/, 0, 0, 30, 0, true, Judge::UPDATE, 0, 2, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, 10, 0, 0.1, 0, 0, 0, 0 /*setparam*/, 0, 0, 30, 0, true, Judge::UNUPDATE, 0, 4, 0, 0, 0, 0, 0},
                   //{0, Section::ARM, Section::ARMANGLE, 0, -70, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, -69, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, -10, 0, 0.1, 0.02, 0.1, 1, 1 /*setparam*/, 180, 0, 30, 0, false, Judge::UPDATE, 0, -2, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, -20, 0, 0.1, 0.02, 0.1, 1, 1 /*setparam*/, 180, 0, 30, 0, false, Judge::UPDATE, 0, -2, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, -40, 0, 0.1, 0.02, 0.1, 1, 1 /*setparam*/, 180, 0, 30, 0, false, Judge::UNUPDATE, 0, -118, 0, 0, 0, 0, 0},
                   //{0, Section::WALKER, Section::LENGTH, 20, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -30, 8, false, Judge::UPDATE, 0, -45, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, -20, 0, 8, 0, 0, 0, 0 /*setparam*/, 0, 37, 0, 0, false, Judge::UPDATE, -90, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, -18, 0, 0, 0, 0, 1, 1 /*setparam*/, 180, 0, 30, 0, false, Judge::UPDATE, 0, -3, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, -25, 0, 0.2, 0.02, 0.01, 1, 1 /*setparam*/, 180, 0, 30, 0, false, Judge::UNUPDATE, 0, -23, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::LENGTH, 10, 0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, false, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::LENGTH, 20, 0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, false, Judge::UNUPDATE, 0, 90, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::LENGTH, 40, 0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, false, Judge::UNUPDATE, 0, 220, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::TURNANGLE, 25, 0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, false, Judge::UPDATE, -87, 0, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::LENGTH, 35, 0, 15, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, false, Judge::UPDATE, 0, 87.5, 0, 0, 0, 0, 0},
                   //{0, Section::TRACER, Section::COLOR, 35, 0, 30, 0.2, 0.1, 0, 0 /*setparam*/, 0, 0, 0, 30, false, Judge::UPDATE, 0, 0, 0, 0, 0, 0.01, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 100},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

  wParam b[100] = {{0, Section::VIRTUAL2, Section::LENGTH, 40, 0, 0.01, 0, 0, 0, 0 /*setparam*/, 0, 0, 30, 0, true, Judge::UPDATE, 0, 57.7, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::LENGTH, 30, 0, 6, 0.2, 0.1, 0, 0 /*setparam*/, 0, -63, 0, 30, false, Judge::UPDATE, 0, 106.5, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::LENGTH, 15, 0, 30, 0.3, 0.2, 0, 0 /*setparam*/, 0, 0, 0, 30, false, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::LENGTH, 25, 0, 20, 0.3, 0.2, 0, 0 /*setparam*/, 0, 0, 0, 30, false, Judge::UNUPDATE, 0, 15, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::LENGTH, 35, 0, 30, 0.2, 0.1, 0, 0 /*setparam*/, 0, 0, 0, 30, false, Judge::UPDATE, 0, 25, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::LENGTH, 25, 0, 30, 0.2, 0.1, 0, 0 /*setparam*/, 0, 0, 0, 30, false, Judge::UNUPDATE, 0, 90, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, 20, 0, 0.1, 0, 0, 0, 0 /*setparam*/, 0, 0, 30, 0, false, Judge::UPDATE, 0, 2, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, 10, 0, 0.1, 0, 0, 0, 0 /*setparam*/, 0, 0, 30, 0, false, Judge::UNUPDATE, 0, 5, 0, 0, 0, 0, 0},
                   //{0, Section::ARM, Section::ARMANGLE, 0, -70, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, -69, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, -10, 0, 0.1, 0.02, 0.1, 0, 0 /*setparam*/, 180, 0, 30, 0, false, Judge::UPDATE, 0, -2, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, -20, 0, 0.1, 0.02, 0.1, 0, 0 /*setparam*/, 180, 0, 30, 0, false, Judge::UPDATE, 0, -2, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, -40, 0, 0.1, 0.02, 0.1, 0, 0 /*setparam*/, 180, 0, 30, 0, false, Judge::UNUPDATE, 0, -118, 0, 0, 0, 0, 0},
                   //{0, Section::WALKER, Section::LENGTH, 20, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -30, 8, false, Judge::UPDATE, 0, -45, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, -20, 0, 6, 0, 0, 0, 0 /*setparam*/, 0, -37, 0, 0, false, Judge::UPDATE, 88, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, -18, 0, 0, 0, 0, 0, 0 /*setparam*/, 180, 0, 30, 0, false, Judge::UPDATE, 0, -3, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, -25, 0, 0.2, 0.02, 0.01, 0, 0 /*setparam*/, 180, 0, 30, 0, false, Judge::UNUPDATE, 0, -20, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::LENGTH, 10, 0, 30, 0.2, 0.1, 0, 0 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 3, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::LENGTH, 20, 0, 30, 0.2, 0.1, 0, 0 /*setparam*/, 0, 0, 0, 30, true, Judge::UNUPDATE, 0, 90, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::LENGTH, 40, 0, 30, 0.2, 0.1, 0, 0 /*setparam*/, 0, 0, 0, 30, true, Judge::UNUPDATE, 0, 220, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::TURNANGLE, 25, 0, 30, 0.2, 0.1, 0, 0 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 90, 0, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::LENGTH, 35, 0, 15, 0.2, 0.1, 0, 0 /*setparam*/, 0, 0, 0, 30, false, Judge::UPDATE, 0, 87, 0, 0, 0, 0, 0},
                   //{0, Section::TRACER, Section::COLOR, 35, 0, 30, 0.2, 0.1, 0, 0 /*setparam*/, 0, 0, 0, 30, false, Judge::UPDATE, 0, 0, 0, 0, 0, 0.01, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 100},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

  wParam *array[10] = {a,b};
  wParam *wp;

  void setWalker(Section *sc);
  void setJudge(Section *sc);
};
#endif
