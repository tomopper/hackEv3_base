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
  const int _EDGE = LineTracer::RIGHTEDGE;
  const int sign=-1;
#else
  const int _EDGE = LineTracer::LEFTEDGE;
  const int sign=1;
#endif

wParam base[100] = {
                    {0, Section::TRACER, Section::LENGTH, 40, 0, 45, 15.0, 4.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 530, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 38, 0, 45, 10.0, 4.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UNUPDATE, 0, 605, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 40, 0, 45, 15.0, 4.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UNUPDATE, 0, 1112, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 20, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0, 55, 0.35, 0 , 0 },  //黄色
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 20, 0, _EDGE, Judge::UPDATE, 00, 12, 0, 0, 0, 0.0, 0 , 0 },  //黄色
                   {0, Section::TRACER, Section::LENGTH, 20, 0, 15, 10.0, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 00, 43, 0, 0,0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 10, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0, 138, 0.35, 0 , 0 },  //緑色
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 20, 5.0, 2.0, 0, 0 /*setparam*/, 0, -12.5*sign, 0, 0, false, Judge::UPDATE, -90*sign, 0, 0, 0, 0, 0, 0},


//                   {0, Section::TRACER, Section::LENGTH, 10, 0, 15, .8, 0.5, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 00, 14, 0, 0,0, 0, 0},
//                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 10, 0, _EDGE, Judge::UPDATE, 00, 64, 0, 0, 0,0 , 0 , 0 },  //緑色

                   {0, Section::VIRTUAL2, Section::LENGTH, 10, 0,15, 5.0, 0.5, 1, 1 /*setparam*/, -90*sign, 0, 0, 0, false, Judge::UPDATE, 0, 77, 0, 0, 0, 0, 0}, //下り
                   
                   
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -5, 0, _EDGE, Judge::UPDATE, 00, -10, 0, 0, 0,0 , 0 , 0 },  //緑色

                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 100000, 0, 0,0, 0, 0},  //黄色

                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0},
};

float kp=25.0;
float vkp=10.0,vki=2.0,vkd=1.0;
wParam sc_l[100] = {
                    {0, Section::TRACER, Section::LENGTH, 40, 0, kp, 5.0, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 255, 0, 0, 0, 0, 0},
                    {0, Section::VIRTUAL2, Section::LENGTH, 40, 0, vkp, vki, vkd, 0, 0 /*setparam*/, 90*sign, 0, 00, 0, _EDGE, Judge::UNUPDATE, 0, 285, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 35, 0,vkp, vki, vkd, 0, 0 /*setparam*/, 0, 18*sign, 0, 0, false, Judge::UPDATE, 160*sign, 0, 0, 0, 0, 0, 0},  // 左
                    {0, Section::VIRTUAL2, Section::LENGTH, 35, 0, vkp, vki, vkd, 0, 0 /*setparam*/, 160*sign, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 42, 0, 0, 0, 0, 0},

                   {0, Section::VIRTUAL, Section::TURNANGLE, 35, 0,vkp, vki, vkd, 0, 0 /*setparam*/, 0, -30*sign, 0, 0, false, Judge::UNUPDATE, 90*sign, 0, 0, 0, 0, 0, 0}, //右
                    {0, Section::VIRTUAL2, Section::LENGTH, 35, 0, vkp, vki, vkd, 0, 0 /*setparam*/, -90*sign, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 11, 0, 0, 0, 0, 0},

                   {0, Section::VIRTUAL, Section::TURNANGLE, 35, 0,vkp, vki, vkd, 0, 0 /*setparam*/, 0, -28*sign, 0, 0, false, Judge::UNUPDATE, -20*sign, 0, 0, 0, 0, 0, 0}, //右
                    {0, Section::VIRTUAL2, Section::LENGTH, 35, 0, vkp, vki, vkd, 0, 0 /*setparam*/, -18*sign, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 4, 0, 0, 0, 0, 0},

                   {0, Section::VIRTUAL, Section::TURNANGLE, 35, 0,vkp, vki, vkd, 0, 0 /*setparam*/, 0, 19*sign, 0, 0, false, Judge::UNUPDATE, 90*sign, 0, 0, 0, 0, 0, 0}, //左
                    {0, Section::VIRTUAL2, Section::LENGTH, 35, 0, vkp, vki, vkd, 0, 0 /*setparam*/, 90*sign, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 19, 0, 0, 0, 0, 0},

                    {0, Section::VIRTUAL, Section::TURNANGLE, 35, 0,vkp, vki, vkd, 0, 0 /*setparam*/, 0, 23*sign, 0, 0, false, Judge::UNUPDATE, 160*sign, 0, 0, 0, 0, 0, 0}, //左
                    {0, Section::VIRTUAL2, Section::LENGTH, 35, 0, vkp, vki, vkd, 0, 0 /*setparam*/, 160*sign, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 22, 0, 0, 0, 0, 0},

                    {0, Section::VIRTUAL, Section::TURNANGLE, 30, 0,vkp, vki, vkd, 0, 0 /*setparam*/, 0, -24*sign, 0, 0, false, Judge::UNUPDATE, -5.0*sign, 0, 0, 0, 0, 0, 0}, //右
//                    {0, Section::VIRTUAL2, Section::BRIGHTNESS, 40, 0, 45, 10.0, 8.0, 0, 0 /*setparam*/, -5.0*sign, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 0, 0.5, 0., 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 40, 0, 8, 0.0, 8.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 50, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 40, 0, 15, 0.0, 5.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 150, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::TURNANGLE, 40, 0, 45, 15.0, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, -45*sign, 0, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 40, 0, 45, 15.0, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 80, 0, 0, 0, 0, 0},

                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 20, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0, 55, 0.35, 0 , 0 },  //黄色
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 20, 0, _EDGE, Judge::UPDATE, 00, 12, 0, 0, 0, 0.0, 0 , 0 },  //黄色
                   {0, Section::TRACER, Section::LENGTH, 20, 0, 15, 10.0, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 00, 43, 0, 0,0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 10, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0, 138, 0.35, 0 , 0 },  //緑色
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 20, 5.0, 2.0, 0, 0 /*setparam*/, 0, -12.5*sign, 0, 0, false, Judge::UPDATE, -90*sign, 0, 0, 0, 0, 0, 0},


//                   {0, Section::TRACER, Section::LENGTH, 10, 0, 15, .8, 0.5, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 00, 14, 0, 0,0, 0, 0},
//                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 10, 0, _EDGE, Judge::UPDATE, 00, 64, 0, 0, 0,0 , 0 , 0 },  //緑色

                   {0, Section::VIRTUAL2, Section::LENGTH, 10, 0,15, 5.0, 0.5, 1, 1 /*setparam*/, -90*sign, 0, 0, 0, false, Judge::UPDATE, 0, 77, 0, 0, 0, 0, 0}, //下り
                   
                   
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -5, 0, _EDGE, Judge::UPDATE, 00, -10, 0, 0, 0,0 , 0 , 0 },  //緑色

                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 100000, 0, 0,0, 0, 0},  //黄色

                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0},
};
  
  wParam a[100] = {{0, Section::VIRTUAL2, Section::LENGTH, 40, 0, 10, 0, 0, 1, 1 /*setparam*/, 0, 0, 30, 0, false, Judge::UPDATE, 0, 54, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 40, 0, 6, 0.1, 0.1, 1, 1 /*setparam*/, 0, 61, 0, 30, false, Judge::UPDATE, 86, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, 40, 0, 10, 0, 0, 1, 1 /*setparam*/, 88, 0, 30, 0, false, Judge::UNUPDATE, 0, 186, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 40, 0, 30, 0.1, 0.1, 1, 1 /*setparam*/, 0, 30, 0, 30, false, Judge::UNUPDATE, 170, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, 40, 0, 10, 0.01, 0.2, 1, 1 /*setparam*/, 178, 0, 30, 0, false, Judge::UNUPDATE, 0, 245, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, -45, 0, 0, 0, 0, 1, 1 /*setparam*/, -2, 0, 30, 0, false, Judge::UNUPDATE, 0, 240, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, -45, 0, 10, 0.01, 0.2, 1, 1 /*setparam*/, -2, 0, 30, 0, false, Judge::UNUPDATE, 0, 150, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, -40, 0, 6, 0, 0, 1, 1 /*setparam*/, 0, 40, 0, 0, false, Judge::UNUPDATE, 90, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, -40, 0, 10, 0.02, 0.01, 1, 1 /*setparam*/, -88, 0, 30, 0, false, Judge::UNUPDATE, 0, 80, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, 40, 0, 1, 0.1, 0.1, 1, 1 /*setparam*/, 89, 0, 30, 0, false, Judge::UNUPDATE, 0, 90, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 40, 0, 6, 0, 0, 1, 1 /*setparam*/, 0, 32, 0, 0, false, Judge::UNUPDATE, 176, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, 40, 0, 10, 0.02, 0.01, 1, 1 /*setparam*/, 176, 0, 30, 0, false, Judge::UNUPDATE, 0, 298, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 40, 0, 6, 0, 0, 1, 1 /*setparam*/, 0, -30, 0, 0, false, Judge::UNUPDATE, 94, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, 40, 0, 10, 0.02, 0.01, 1, 1 /*setparam*/, 90, 0, 30, 0, false, Judge::UNUPDATE, 0, 471, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::TURNANGLE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 30, false, Judge::UNUPDATE, 60, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::BRIGHTNESS, 20, 0, 10, 0.02, 0.01, 1, 1 /*setparam*/, 0, 0, 30, 0, false, Judge::UNUPDATE, 0, 0, -0.3, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::LENGTH, 10, 0, 30, 0.2, 0.2, 1, 1 /*setparam*/, 0, 0, 30, 0, false, Judge::UPDATE, 0, 7, 0, 0, 207, 0.35, 0},
                   {0, Section::TRACER, Section::COLOR, 10, 0, 30, 0.2, 0.2, 1, 1 /*setparam*/, 0, 0, 30, 0, false, Judge::UNUPDATE, 0, 0, 0, 0, 207, 0.35, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

  wParam b[100] = {   
  
                      {0, Section::TRACER, Section::LENGTH, 25, 0, 10, 0, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 5, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 42, 0, 10, 0, 0.1, 1,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 65, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 40, 0, 30, 0.8, 0.1, 1/0.7,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 100, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 42, 0, 20, 0.8, 0.1, 1,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 45, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 35, 0, 30, 0.8, 0.1, 1/1.3,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 45, 0, 0, 0, 0,0,false},
                       {0, Section::TRACER, Section::LENGTH, 35, 0, 30, 0.8, 0.1, 1/1.6,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 45, 0, 0, 0, 0,0,false},
                       {0, Section::TRACER, Section::LENGTH, 30, 0, 30, 0.8, 0.2, 1/1.6,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 15, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 40, 0, 30, 0, 0.9, 1,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 55, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 35, 0, 30, 0, 0.8, 1.1,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 5, 0, 0, 0, 0,0,false},
                       {0, Section::TRACER, Section::LENGTH, 35, 0, 30, 0, 0.8, 1/1.6,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 35, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 40, 0, 30, 0, 0.8, 1,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 63, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 35, 0, 30, 0, 0.8, 1/0.7,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 70, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 40, 0, 30, 0, 0.8, 1,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 40, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 43, 0, 30, 0, 0.8, 1/0.7,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 30, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 43, 0, 20, 0, 0.8, 1/0.85,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 10, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 43, 0, 20, 0, 0.8, 1,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 50, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 35, 0, 30, 0, 0.8, 1/0.7,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 60, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 40, 0, 20, 0, 0.8, 1,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 15, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 42, 0, 25, 0, 0.8, 1,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 110, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 40, 0, 20, 0, 0.8, 1,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 25, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 30, 0, 30, 0, 0.8, 1/1.5,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 35, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 30, 0, 30, 0, 0.8, 1/1.6,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 10, 0, 0, 0, 0,0,false},
                      
                      {0, Section::TRACER, Section::LENGTH, 42, 0, 30, 0, 0.8, 1,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0,85, 0, 0, 0, 0,0,false},
                      
    
                      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, false, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0,0,false}};

  void setWalker(Section *sc);
  void setJudge(Section *sc);

  wParam *array[10] = {sc_l, b};
  wParam *wp;
};
#endif
