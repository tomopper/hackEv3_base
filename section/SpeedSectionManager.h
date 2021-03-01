#ifndef _SPEED_SECTION_MANAGER_H_
#define _SPEED_SECTION_MANAGER_H_

#include "ev3api.h"
#include "SectionManager.h"
#include <Motor.h>
#include "HBTtask.h"

#include "global.h"

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
  bool init();

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

  //{-1の時終了, Section::使いたいwalker, Section::使いたいjudge, 速度, 0, pの値, dの値, iの値, 0, 0 ,
  ///*setparam*/, 直線仮想ライントレースの角度, 円仮想ライントレースの半径, 単純走行のパワー, 単純走法の曲がり具合, 線のどちらを進むか,
  //1の時現在地を更新可能, 終了角度, 終了距離,白黒割合 , 白黒計測フラグ, 色数値, 彩度数値,止まる秒数}

  //setparamの例,Virtual2->setParam(10,5, 0.2, 0.2,1,1)
  // tracer->setParam(30,0,30,0.2,0.1)
  //Virtual->setParam(20,2,0.2,0,1,1)
  //Walker->setCommand(0,10)
  int num = 0;

  wParam a2[100] = {{0, Section::VIRTUAL2, Section::LENGTH, 10, 0, 18.0, 19.5, 18.0, 0, 0 /*setparam*/, 0/*absangle*/, 0, 0, 0/*単純走法の曲がり具合*/, false, Judge::UPDATE, 0, 100, 0, 0, 0, 0, 0},
                    {-1, Section::VIRTUAL2, Section::LENGTH, 0, 0, 18.0, 19.5, 18.0, 0, 0 /*setparam*/, 0/*absangle*/, 0, 0, 0/*単純走法の曲がり具合*/, false, Judge::UPDATE, 0, 1000000, 0, 0, 0, 0, 0},
                    {-1, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};
//  wParam a[100] = {
    //{0, Section::WALKER, Section::TURNANGLE, -15, 0,2, 0, 0, 1,1 /*setparam*/, 180, 0, 0, -30, true,Judge::UNUPDATE, 90, 50, 0, 0, 0, 0,0,false},
//      {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0, false},
//      {-1, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0, false}};

//  wParam b[100] = {
      //{0, Section::WALKER, Section::LENGTH, 40, 0, 2, 0, 0, 1,1 /*setparam*/, -85, 0, 40, 0, true,Judge::UPDATE, -80, 50, 0, 0, 0, 0,600,false},
//      {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 0, false},
//     {-1, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, false, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

//  wParam c[100] = {

//      {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 0, false},
//      {-1, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, false, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};
//  wParam wp1[100] = {

//      {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 0, false},
//      {-1, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

//  wParam wp2[100] = {

//      {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 0, false},
//      {-1, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, false, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0, false}};

  void setWalker(Section *sc);
  void setJudge(Section *sc);

  wParam *array[10] = {a2, /*wp2*/};
  wParam *wp;

};
#endif
