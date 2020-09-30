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

  //{-1の時終了, Section::使いたいwalker, Section::使いたいjudge, 速度, 0, pの値, iの値, dの値, 0, 0 ,
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

  wParam a[100] = {{0, Section::VIRTUAL2, Section::LENGTH, 40, 0, 10, 0, 0, 1, 1 /*setparam*/, 0, 0, 30, 0, false, Judge::UPDATE, 0, 54, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 40, 0, 6, 0.1, 0.1, 1, 1 /*setparam*/, 0, 61, 0, 30, false, Judge::UPDATE, 86, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, 40, 0, 10, 0, 0, 1, 1 /*setparam*/, 88, 0, 30, 0, false, Judge::UNUPDATE, 0, 186, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 40, 0, 30, 0.1, 0.1, 1, 1 /*setparam*/, 0, 30, 0, 30, false, Judge::UNUPDATE, 170, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, 40, 0, 10, 0.01, 0.2, 1, 1 /*setparam*/, 178, 0, 30, 0, false, Judge::UNUPDATE, 0, 245, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, -45, 0, 10, 0.01, 0.2, 1, 1 /*setparam*/, -2, 0, 30, 0, false, Judge::UNUPDATE, 0, 150, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, -40, 0, 6, 0, 0, 1, 1 /*setparam*/, 0, 40, 0, 0, false, Judge::UNUPDATE, 90, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, -40, 0, 10, 0.02, 0.01, 1, 1 /*setparam*/, -88, 0, 30, 0, false, Judge::UNUPDATE, 0, 80, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, 40, 0, 10, 0.02, 0.01, 1, 1 /*setparam*/, 89, 0, 30, 0, false, Judge::UNUPDATE, 0, 90, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 40, 0, 6, 0, 0, 1, 1 /*setparam*/, 0, 32, 0, 0, false, Judge::UNUPDATE, 180, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, 40, 0, 10, 0.02, 0.01, 1, 1 /*setparam*/, 176, 0, 30, 0, false, Judge::UNUPDATE, 0, 295, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 40, 0, 6, 0, 0, 1, 1 /*setparam*/, 0, -30, 0, 0, false, Judge::UNUPDATE, 90, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, 40, 0, 10, 0.02, 0.01, 1, 1 /*setparam*/, 88, 0, 30, 0, false, Judge::UNUPDATE, 0, 470, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::TURNANGLE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 30, false, Judge::UNUPDATE, 60, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::BRIGHTNESS, 20, 0, 10, 0.02, 0.01, 1, 1 /*setparam*/, 0, 0, 30, 0, false, Judge::UNUPDATE, 0, 0, -0.3, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 10, 0, 30, 0.2, 0.2, 1, 1 /*setparam*/, 0, 0, 30, 0, false, Judge::UNUPDATE, 0, 0, 0, 0, 207, 0.35, 0},
                   //{0, Section::WALKER, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 100},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

  wParam b[100] = {{0, Section::VIRTUAL2, Section::LENGTH, 40, 0, 10, 0, 0, 1, 1 /*setparam*/, 0, 0, 30, 0, true, Judge::UPDATE, 0, 57.7, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 40, 0, 6, 0.2, 0.1, 1, 1 /*setparam*/, 0, -63, 0, 30, false, Judge::UPDATE, -88, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, 40, 0, 10, 0, 0, 1, 1 /*setparam*/, 0, 0, 30, 0, true, Judge::UPDATE, 0, 33, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 40, 0, 6, 0.2, 0.1, 1, 1 /*setparam*/, 0, -33, 0, 30, false, Judge::UPDATE, -84, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, 40, 0, 10, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 30, 0, true, Judge::UPDATE, 0, 17, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, -45, 0, 10, 0.02, 0.1, 1, 1 /*setparam*/, 180, 0, 30, 0, false, Judge::UNUPDATE, 0, -85, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, -40, 0, 6, 0, 0, 1, 1 /*setparam*/, 0, -34, 0, 0, false, Judge::UPDATE, 86, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, -40, 0, 10, 0.02, 0.01, 1, 1 /*setparam*/, 180, 0, 30, 0, false, Judge::UPDATE, 0, -15, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, 40, 0, 0, 10, 0.01, 1, 1 /*setparam*/, 0, 0, 30, 0, false, Judge::UPDATE, 0, 8, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 40, 0, 6, 0, 0, 1, 1 /*setparam*/, 0, -36, 0, 0, false, Judge::UPDATE, -82, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, 40, 0, 0.2, 0.02, 0.01, 1, 1 /*setparam*/, 0, 0, 30, 0, false, Judge::UPDATE, 0, 144, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 40, 0, 6, 0, 0, 1, 1 /*setparam*/, 0, 38, 0, 0, false, Judge::UPDATE, 86, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, 40, 0, 0.2, 0.02, 0.01, 1, 1 /*setparam*/, 0, 0, 30, 0, false, Judge::UPDATE, 0, 130, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::TURNANGLE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, -30, false, Judge::UPDATE, 75, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::BRIGHTNESS, 40, 0, 0.2, 0.02, 0.01, 1, 1 /*setparam*/, 0, 0, 30, 0, false, Judge::UPDATE, 0, 0, -0.3, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 15, 0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 30, 0, true, Judge::UPDATE, 0, 0, 0, 0, 207, 0.35, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 100},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

  wParam sp[100] = {{0, Section::TRACER, Section::LENGTH, 10, 0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, false, Judge::UPDATE, 0, 5, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 32, 0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, false, Judge::UPDATE, 0, 65, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 30, 0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, false, Judge::UPDATE, 0, 100, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 35, 0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, false, Judge::UPDATE, 0, 50, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 30, 0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, false, Judge::UPDATE, 0, 100, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 35, 0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, false, Judge::UPDATE, 0, 70, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 30, 0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, false, Judge::UPDATE, 0, 40, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 35, 0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, false, Judge::UPDATE, 0, 70, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 30, 0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, false, Judge::UPDATE, 0, 30, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 35, 0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, false, Judge::UPDATE, 0, 40, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 30, 0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, false, Judge::UPDATE, 0, 60, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 35, 0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, false, Judge::UPDATE, 0, 60, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 30, 0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, false, Judge::UPDATE, 0, 70, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 30, 0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, false, Judge::UPDATE, 0, 150, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 20, 0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, false, Judge::UPDATE, 0, 40, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 15, 0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, false, Judge::UPDATE, 0, 40, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::COLOR, 40, 0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, false, Judge::UPDATE, 0, 0, 0, 0, 207, 0.35, 0, false},
                    //{0, Section::TRACER, Section::LENGTH, 35, 0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, false, Judge::UPDATE, 0, 100, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0}};

  void setWalker(Section *sc);
  void setJudge(Section *sc);

  wParam *array[10] = {a, b};
  wParam *wp;
};
#endif
