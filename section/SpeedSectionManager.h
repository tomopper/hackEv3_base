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
                   {0, Section::VIRTUAL, Section::TURNANGLE, 40, 0, 6, 0.2, 0.1, 1, 1 /*setparam*/, 0, 63, 0, 30, false, Judge::UPDATE, 88, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, 40, 0, 0.01, 0, 0, 1, 1 /*setparam*/, 0, 0, 30, 0, true, Judge::UPDATE, 0, 33, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 40, 0, 6, 0.2, 0.1, 1, 1 /*setparam*/, 0, 37, 0, 30, false, Judge::UPDATE, 85, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, 40, 0, 0.1, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 30, 0, true, Judge::UPDATE, 0, 13, 0, 0, 0, 0, 0},
                   //{0, Section::VIRTUAL, Section::LENGTH, 40, 0, 6, 0.2, 0.1, 1, 1 /*setparam*/, 0, 63, 0, 30, false, Judge::UPDATE, 0, 106.7, 0, 0, 0, 0, 0},
                   //{0, Section::TRACER, Section::LENGTH, 15, 0, 30, 0.3, 0.2, 1, 1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 20, 0, 0, 0, 0, 0},
                   //{0, Section::TRACER, Section::LENGTH, 42, 0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                   //{0, Section::TRACER, Section::LENGTH, 30, 0, 30, 0.3, 0.15, 0.85, 1 /*setparam*/, 0, 0, 0, 30, true, Judge::UNUPDATE, 0, 50, 0, 0, 0, 0, 0},
                   //{0, Section::TRACER, Section::LENGTH, 25, 0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 33, 0, 0, 0, 0, 0},
                   //{0, Section::TRACER, Section::LENGTH, 20, 0, 10, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 30, 0, false, Judge::UPDATE, 0, 2, 0, 0, 0, 0, 0},
                   //{0, Section::TRACER, Section::LENGTH, 10, 0, 10, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 30, 0, false, Judge::UNUPDATE, 0, 6, 0, 0, 0, 0, 0},
                   //{0, Section::ARM, Section::ARMANGLE, 0, -70, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, -69, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, -45, 0, 0.1, 0.02, 0.1, 1, 1 /*setparam*/, 180, 0, 30, 0, false, Judge::UNUPDATE, 0, -93, 0, 0, 0, 0, 0},
                   //{0, Section::WALKER, Section::LENGTH, 20, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, -30, 8, false, Judge::UPDATE, 0, -45, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, -40, 0, 6, 0, 0, 1, 1 /*setparam*/, 0, 37, 0, 0, false, Judge::UPDATE, -88, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, -40, 0, 0.2, 0.02, 0.01, 1, 1 /*setparam*/, 180, 0, 30, 0, false, Judge::UPDATE, 0, -15, 0, 0, 0, 0, 0},
                   //{0, Section::WALKER, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                   //{0, Section::TRACER, Section::LENGTH, 40, 0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, false, Judge::UPDATE, 0, 92, 0, 0, 0, 0, 0},
                   //{0, Section::TRACER, Section::LENGTH, 25, 0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, false, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                   //{0, Section::TRACER, Section::LENGTH, 42, 0, 15, 0.3, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, false, Judge::UNUPDATE, 0, 110, 0, 0, 0, 0, 0},
                   //{0, Section::TRACER, Section::TURNANGLE, 35, 0, 30, 0.3, 0.1, 1.4, 1 /*setparam*/, 0, 0, 0, 30, false, Judge::UPDATE, -90, 0, 0, 0, 0, 0, 0},
                   //{0, Section::TRACER, Section::LENGTH, 25, 0, 30, 0.3, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, false, Judge::UPDATE, 0, 14, 0, 0, 0, 0, 0},
                   //{0, Section::TRACER, Section::LENGTH, 42, 0, 15, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, false, Judge::UNUPDATE, 0, 89, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, 40, 0, 0, 0.02, 0.01, 1, 1 /*setparam*/, 0, 0, 30, 0, false, Judge::UPDATE, 0, 8, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 40, 0, 6, 0, 0, 1, 1 /*setparam*/, 0, 47, 0, 0, false, Judge::UPDATE, 85, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, 40, 0, 0.2, 0.02, 0.01, 1, 1 /*setparam*/, 0, 0, 30, 0, false, Judge::UPDATE, 0, 135, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 40, 0, 6, 0, 0, 1, 1 /*setparam*/, 0, -41, 0, 0, false, Judge::UPDATE, -86, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, 40, 0, 0.2, 0.02, 0.01, 1, 1 /*setparam*/, 0, 0, 30, 0, false, Judge::UPDATE, 0, 74, 0, 0, 0, 0, 0},
                   //{0, Section::TRACER, Section::COLOR, 35, 0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, false, Judge::UPDATE, 0, 0, 0, 0, 0, 0.01, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 100},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

  wParam b[100] = {{0, Section::WALKER, Section::LENGTH, 20, 0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, false, Judge::UPDATE, -90, 60, 0, 0, 58, 5, 10, false},
                   {0, Section::VIRTUAL2, Section::LENGTH, -15, 0, 2, 0, 0, 1, 1 /*setparam*/, 180, 0, 0, -30, true, Judge::UNUPDATE, -40, 8, 0, 0, 0, 0, 0, false},
                   {0, Section::WALKER, Section::TURNANGLE, -15, 0, 2, 0, 0, 0, 0 /*setparam*/, 180, 0, 0, 20, true, Judge::UNUPDATE, -70, 50, 0, 0, 0, 0, 0, false},
                   {0, Section::WALKER, Section::TURNANGLE, -15, 0, 2, 0, 0, 0, 0 /*setparam*/, 180, 0, 0, 5, true, Judge::UNUPDATE, -90, 50, 0, 0, 0, 0, 0, false},
                   {0, Section::WALKER, Section::STOP, -15, 0, 2, 0, 0, 1, 1 /*setparam*/, -85, 0, 0, 0, true, Judge::UPDATE, -90, 50, 0, 0, 0, 0, 50, false},
                   {0, Section::VIRTUAL2, Section::LENGTH, 15, 0, 20, 0, 0, 1, 1 /*setparam*/, -90, 0, 0, -30, true, Judge::UNUPDATE, -30, 35, 0, 0, 0, 0, 0, false},
                   {0, Section::TRACER, Section::LENGTH, 10, 0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, true, Judge::UNUPDATE, -90, 55, 0, 0, 58, 5, 10, false},
                   {0, Section::VIRTUAL2, Section::LENGTH, 15, 0, 20, 0, 0, 1, 1 /*setparam*/, -90, 0, 0, -30, true, Judge::UNUPDATE, -30, 75, 0, 0, 0, 0, 0, false},
                   {0, Section::TRACER, Section::LENGTH, 10, 0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, true, Judge::UNUPDATE, -90, 90, 0, 0, 58, 5, 10, false},
                   {0, Section::VIRTUAL2, Section::LENGTH, 15, 0, 20, 0, 0, 1, 1 /*setparam*/, -90, 0, 0, -30, true, Judge::UNUPDATE, -30, 120, 0, 0, 0, 0, 0, false},
                   {0, Section::WALKER, Section::TURNANGLE, -15, 0, 2, 0, 0, 0, 0 /*setparam*/, 180, 0, 0, -30, true, Judge::UNUPDATE, -10, 50, 0, 0, 0, 0, 0, false},
                   {0, Section::WALKER, Section::TURNANGLE, -15, 0, 2, 0, 0, 0, 0 /*setparam*/, 180, 0, 0, -10, true, Judge::UNUPDATE, 0, 50, 0, 0, 0, 0, 0, false},
                   {0, Section::WALKER, Section::STOP, -15, 0, 2, 0, 0, 1, 1 /*setparam*/, -85, 0, 0, 0, true, Judge::UPDATE, -90, 50, 0, 0, 0, 0, 50, false},
                   {0, Section::VIRTUAL2, Section::LENGTH, 15, 0, 2, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, -30, true, Judge::UNUPDATE, -40, 180, 0, 0, 0, 0, 0, false},
                   {0, Section::VIRTUAL2, Section::LENGTH, -15, 0, 2, 0, 0, 1, 1 /*setparam*/, 180, 0, 0, -30, true, Judge::UPDATE, -40, -20, 0, 0, 0, 0, 0, false},
                   {0, Section::WALKER, Section::STOP, -15, 0, 2, 0, 0, 1, 1 /*setparam*/, -85, 0, 0, 0, true, Judge::UNUPDATE, -90, 50, 0, 0, 0, 0, 50, false},
                   {0, Section::VIRTUAL2, Section::LENGTH, 15, 0, 20, 0, 0, 1, 1 /*setparam*/, -90, 0, 0, -30, true, Judge::UNUPDATE, -30, 20, 0, 0, 0, 0, 0, false},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0, false}};

  wParam *array[10] = {a, b};
  wParam *wp;

  void setWalker(Section *sc);
  void setJudge(Section *sc);
};
#endif
