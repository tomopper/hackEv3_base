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
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 20, 5.0, 2.0, 0, 0 /*setparam*/, 0, -11.5*sign, 0, 0, false, Judge::UPDATE, -90*sign, 0, 0, 0, 0, 0, 0},


//                   {0, Section::TRACER, Section::LENGTH, 10, 0, 15, .8, 0.5, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 00, 14, 0, 0,0, 0, 0},
//                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 10, 0, _EDGE, Judge::UPDATE, 00, 64, 0, 0, 0,0 , 0 , 0 },  //緑色

                   {0, Section::VIRTUAL2, Section::LENGTH, 10, 0,60, 12.0, 5.0, 1, 1 /*setparam*/, -90*sign, 0, 0, 0, false, Judge::UPDATE, 0, 78, 0, 0, 0, 0, 0}, //下り
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -5, 0, _EDGE, Judge::UPDATE, 00, -10, 0, 0, 0,0 , 0 , 0 },  //緑色

                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 100000, 0, 0,0, 0, 0},  //黄色

                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0},
};
wParam outer[100] = {
                    {0, Section::TRACER, Section::LENGTH, 40, 0, 45, 15.0, 4.0, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UPDATE, 0, 600, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::TURNANGLE, 40, 0, 45, 15.0, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UPDATE, -45*sign, 0, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 40, 0, 45, 15.0, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UPDATE, 0, 80, 0, 0, 0, 0, 0},

                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 20, 0, !_EDGE, Judge::UPDATE, 00, 0, 0, 0, 55, 0.35, 0 , 0 },  //黄色
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 20, 0, !_EDGE, Judge::UPDATE, 00, 12, 0, 0, 0, 0.0, 0 , 0 },  //黄色
                   {0, Section::TRACER, Section::LENGTH, 20, 0, 15, 10.0, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UPDATE, 00, 43, 0, 0,0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 10, 0, !_EDGE, Judge::UPDATE, 00, 0, 0, 0, 138, 0.35, 0 , 0 },  //緑色
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 20, 5.0, 2.0, 0, 0 /*setparam*/, 0, -11.5*sign, 0, 0, false, Judge::UPDATE, -90*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, 10, 0,60, 12.0, 5.0, 1, 1 /*setparam*/, -90*sign, 0, 0, 0, false, Judge::UPDATE, 0, 76, 0, 0, 0, 0, 0}, //下り
                                      
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -5, 0, !_EDGE, Judge::UPDATE, 00, -10, 0, 0, 0,0 , 0 , 0 },  //緑色

                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 00, 100000, 0, 0,0, 0, 0},  //黄色

                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0},
};
float kp=60.0;
float vkp=38.0,vki=40.0,vkd=3.5;
float vkp2=30.0,vki2=10.0,vkd2=5.0;
//float vkp=0.0,vki=0.0,vkd=0.0;

float YELLOW = 55;
float GREEN = 138;
float RED = 5;
float BLUE = 207;

float bspd=16;

wParam sc_l[150] = {

                    // {0, Section::TRACER, Section::TURNANGLE, 39, 0, kp, 35.0, 2.95, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 5*sign, 0, 0, 0, 0, 0, 0},
                    // {0, Section::TRACER, Section::TURNANGLE, 33, 0, kp, 90.0, 6.8, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UNUPDATE, 85*sign, 0, 0, 0, 0, 0, 0},
                    // {0, Section::TRACER, Section::LENGTH, 39, 0, kp, 20.0, 2.95, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 45, 0, 0, 0, 0, 0},
                    // {0, Section::WALKER, Section::LENGTH, 39, 0,  vkp, vki, vkd,  0, 0 /*setparam*/, 90*sign , 0 , 39, 0, _EDGE, Judge::UNUPDATE, 0, 55, 0, 0, 0, 0, 0},
                    // {0, Section::VIRTUAL, Section::TURNANGLE, 32, 0, vkp, vki, vkd,  0.5, 1.0/*setparam*/, 0, 20*sign, 0, 0, false, Judge::UPDATE, 156*sign, 0, 0, 0, 0, 0, 0},  // 左
                    // {0, Section::VIRTUAL2, Section::LENGTH, 32, 0, vkp2, vki2, vkd2, 0, 0 /*setparam*/, 166*sign, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 34, 0, 0, 0, 0, 0},

                    // {0, Section::VIRTUAL, Section::TURNANGLE, 32, 0,vkp, vki, vkd, 0.6, 1.0 /*setparam*/, 0, -29*sign, 0, 0, false, Judge::UNUPDATE, 90*sign, 0, 0, 0, 0, 0, 0}, //右
                    // {0, Section::VIRTUAL2, Section::LENGTH, 35, 0, vkp2, vki2, vkd2, 0, 0 /*setparam*/,  90*sign, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 17, 0, 0, 0, 0, 0},

                    // {0, Section::VIRTUAL, Section::TURNANGLE, 32, 0,vkp, vki, vkd, 0.6, 1.0 /*setparam*/, 0, -24*sign, 0, 0, false, Judge::UNUPDATE, -15*sign, 0, 0, 0, 0, 0, 0}, //右
                    // {0, Section::VIRTUAL2, Section::LENGTH, 35, 0, vkp2, vki2, vkd2, 0, 0 /*setparam*/, -20*sign, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 4, 0, 0, 0, 0, 0},

                    // {0, Section::VIRTUAL, Section::TURNANGLE, 31, 0,vkp, vki, vkd, 0.55, 1.0 /*setparam*/, 0, 18.0*sign, 0, 0, false, Judge::UNUPDATE, 82*sign, 0, 0, 0, 0, 0, 0}, //左
                    // {0, Section::VIRTUAL2, Section::LENGTH, 35, 0, vkp2, vki2, vkd2, 0, 0 /*setparam*/, 84*sign, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 24, 0, 0, 0, 0, 0},

                    // {0, Section::VIRTUAL, Section::TURNANGLE, 31, 0,vkp, vki, vkd, 0.55, 1.0 /*setparam*/, 0, 22*sign, 0, 0, false, Judge::UNUPDATE, 160*sign, 0, 0, 0, 0, 0, 0}, //左
                    // {0, Section::VIRTUAL2, Section::LENGTH, 35, 0, vkp2, vki2, vkd2, 0, 0 /*setparam*/, 167*sign, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 19, 0, 0, 0, 0, 0},

                    // {0, Section::VIRTUAL, Section::TURNANGLE, 32, 0,vkp, vki, vkd, 0.55, 1.0 /*setparam*/, 0, -23.5*sign, 0, 0, false, Judge::UNUPDATE, -1.0*sign, 0, 0, 0, 0, 0, 0}, //右
                    // {0, Section::TRACER, Section::LENGTH, 39, 0, 7, 0.0, 9.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 50, 0, 0, 0, 0, 0},
                  
                    // 最終コーナーへ
                    // {0, Section::TRACER, Section::LENGTH, 39, 0, kp, 40, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 100, 0, 0, 0, 0, 0},
                    // {0, Section::TRACER, Section::TURNANGLE, 30, 0, 30, 15.0, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, -30*sign, 0, 0, 0, 0, 0, 0},
                    // {0, Section::TRACER, Section::LENGTH, 30, 0, kp, 15.0, 2.5, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 70, 0, 0, 0, 0, 0},

                    // 外側コース
                   {0, Section::TRACER, Section::LENGTH, 39, 0, kp, 35.0, 2.95, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UPDATE, 0, 550, 0, 0, 0, 0, 0},
                    // 最終コーナーへ
                    {0, Section::TRACER, Section::LENGTH, 39, 0, kp, 40, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UPDATE, 0, 100, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::TURNANGLE, 30, 0, 30, 15.0, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UPDATE, -30*sign, 0, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 30, 0, kp, 15.0, 2.5, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UPDATE, 0, 70, 0, 0, 0, 0, 0},


                      // スラロームテスト
                      // {0, Section::TRACER, Section::LENGTH, 5, -0.0, 18, 8.0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 12, 0, 0, 138, 0.35, 0 , 0 },  
                      // {0, Section::ARM, Section::ARMANGLE, 0, -60, 1.5, 0, 0, 0, 0/*setparam*/, 0, 0, 0, 0, _EDGE,Judge::UPDATE, -58, 0, 0, 0, 0, 0, 0},

                      // {0, Section::WALKER, Section::LENGTH, 7, 0, 0, 0.2, 0.8, 1, 1 /*setparam*/, 0, 0, 4, 0, _EDGE,Judge::UPDATE, 0, 12, 0, 0, 0, 0, 0},
                      // {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -5, 0, _EDGE,Judge::UPDATE, 0, -0.5, 0, 0, 0, 0, 0},
                      // {0, Section::ARM, Section::ARMANGLE, 0, 30, 1, 0, 0, 0, 0/*setparam*/, 0, 0, 0, 0, _EDGE,Judge::UPDATE, 9.5, 0, 0, 0, 0, 0, 0},
                      // {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 13, 0, _EDGE,Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},
                      // {0, Section::TAIL, Section::TAILANGLE, 0, 600, 0.1, 0.1, 0.01, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE,Judge::UPDATE, 12, 0, 0, 0, 0, 0, 0}, // 600度目標で回すが、走行に制御を戻さないといけないので10度で終了
                      // {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 5, 0, _EDGE,Judge::UPDATE, 0, 16, 0, 0, 0, 0, 0}, //昇段
                      // {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 1, 0, _EDGE,Judge::UNUPDATE, 0, 16.5, 0, 0, 0, 0, 0},
                      // {0, Section::TAIL, Section::TAILANGLE, 0, 0, 1, 0.0, 0.00, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE,Judge::UPDATE, 6, 0, 0, 0, 0, 0, 0},// 尻尾をなめらかに本体の自重で落とす。早く走行に制御を戻すため、590度で終了
                      // {0, Section::ARM, Section::ARMANGLE, 0, -50, 2, 0, 0, 0, 0/*setparam*/, 0, 0, 0, 0, _EDGE,Judge::UPDATE, -50, 0, 0, 0, 0, 0, 0},

                      // {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -5, 0, _EDGE,Judge::UNUPDATE, 0, 16-2, 0, 0, 0, 0, 0},
                      // {0, Section::TRACER, Section::LENGTH, 3, -0.3, 20, 8, 0.1, 1, 1 /*setparam*/, 0, 0, 0, -30, _EDGE,Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                      // {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, -15, 0, 0, _EDGE,Judge::UPDATE, -35, 0, 0, 0, 0, 0, 0},
                      // {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, +19, 0, 0, _EDGE,Judge::UNUPDATE, +38.5, 0, 0, 0, 0, 0, 0},
                      // {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, -18, 0, 0, _EDGE,Judge::UNUPDATE, -35, 0, 0, 0, 0, 0, 0},
                      // {0, Section::VIRTUAL2, Section::LENGTH, 5, 0, 25, 10, 0, 1, 1/*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 1, 0, 0, 0, 0, 0},
                      // {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, +16, 0, 0, _EDGE,Judge::UNUPDATE, +20, 0, 0, 0, 0, 0, 0},

                      //     // スラロームpatern 1
                      //       {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, -16, 0, 0, _EDGE,Judge::UNUPDATE, -50, 0, 0, 0, 0, 0, 0},
                      //      {0, Section::VIRTUAL2, Section::BRIGHTNESS, 5, 0, 25, 10, 0, 1, 1/*setparam*/, -50, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                      //       {0, Section::WALKER, Section::LENGTH, 7, 0, 0, 0.2, 0.8, 1, 1 /*setparam*/, 0, 0, 5, 0, _EDGE,Judge::UPDATE, 0, 12, 0, 0, 0, 0, 0},   
                      //       {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, -16, 0, 0, _EDGE,Judge::UNUPDATE, -92, 0, 0, 0, 0, 0, 0},
                      //       {0, Section::WALKER, Section::LENGTH, 7, 0, 0, 0.2, 0.8, 1, 1 /*setparam*/, 0, 0, 5, 0, _EDGE,Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},   //降段
                      //       {0, Section::TRACER, Section::LENGTH, 7, 0, 25, 0, 1.5, 1, 1 /*setparam*/, 0, 0, 5, 0, _EDGE,Judge::UPDATE, 0, 19, 0, 0, 0, 0, 0},

                      //     //スラロームpatern2
                      //     //   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, -16, 0, 0, _EDGE,Judge::UNUPDATE, -110, 0, 0, 0, 0, 0, 0},
                      //     //  {0, Section::VIRTUAL2, Section::LENGTH, 5, 0, 25, 10, 0, 1, 1/*setparam*/, -110, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                      //     //   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, 16, 0, 0, _EDGE,Judge::UNUPDATE, -40, 0, 0, 0, 0, 0, 0},
                      //     //   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, -30, 0, 0, _EDGE,Judge::UNUPDATE, -60, 0, 0, 0, 0, 0, 0},
                      //     //   //{0, Section::WALKER, Section::LENGTH, 7, 0, 0, 0.2, 0.8, 1, 1 /*setparam*/, 0, 0, 5, 0, _EDGE,Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},   //降段
                      //     //   {0, Section::WALKER, Section::BRIGHTNESS, 0, -0.7, 10, 0, 0, 1, 1 /*setparam*/, 0, 0, 5, 0, _EDGE,Judge::UPDATE, 0, 0, -0.10, 0, 0, 0, 0},
                      //     //   {0, Section::TRACER, Section::LENGTH, 7, 0, 30, 0, 1.5, 1, 1 /*setparam*/, 0, 0, 5, 0, !_EDGE,Judge::UPDATE, 0, 22, 0, 0, 0, 0, 0},
                      // //ガレージ停止
                      //     {0, Section::WALKER, Section::SONER, 7, 0, 10, 0.2, 0.8, 1, 1 /*setparam*/, 0, 0, 10, 0, !_EDGE,Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                      //               {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 00, 10000, 0, 0, 138, 0.35, 0 , 0 },  
                      // スラローム終了

                    // entry 入り口 / advanced センター置き
                   {0, Section::TRACER, Section::LENGTH, 35, 0, kp, 4.0, 2.5, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UNUPDATE, 0, 95, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 20, 0, !_EDGE, Judge::UPDATE, 00, 0, 0, 0, 55, 0.35, 0 , 0 },  //黄色
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 20, 0, !_EDGE, Judge::UPDATE, 00, 12, 0, 0, 0, 0.0, 0 , 0 },  //黄色
                   {0, Section::TRACER, Section::LENGTH, 25, 0, 15, 5.0, 2.0, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UPDATE, 00, 35, 0, 0,0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 10, 0, !_EDGE, Judge::UPDATE, 00, 0, 0, 0, 138, 0.35, 0 , 0 },  //緑色
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 20, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -9.8*sign, 0, 0, false, Judge::UPDATE, -90*sign, 0, 0, 0, 0, 0, 0},

                  // entry ブロック置き
                  //  //{0, Section::VIRTUAL2, Section::LENGTH, 10, 0,40, 10.0, 5.0, 1, 1 /*setparam*/, -90*sign, 0, 0, 0, false, Judge::UPDATE, 0, 78, 0, 0, 0, 0, 0}, //下り  entry
                  //  // etry 超音波センサーテスト
                  //  {0, Section::VIRTUAL2, Section::SONER, 5, 0,40, 10.0, 5.0, 1, 1 /*setparam*/, -90*sign, 0, 0, 0, false, Judge::UPDATE, 0, 31, 0, 0, 0, 0, 0}, //下り  entry

                  // advanced センター置き
                  {0, Section::TRACER, Section::LENGTH, 10, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0}, //下り  advanced
                  {0, Section::WALKER, Section::LENGTH, 00, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 15, 0, false, Judge::UNUPDATE, 0, 55, 0, 0, 0, 0, 0}, //下り  advanced
                  {0, Section::VIRTUAL, Section::TURNANGLE, 10, 0, 20, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -11.5*sign, 0, 0, false, Judge::UPDATE, -89*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::VIRTUAL2, Section::LENGTH, 25, 0,30, 15.0, 5.0, 1, 1 /*setparam*/, -90*sign, 0, 0, 0, false, Judge::UPDATE, 0, 55, 0, 0, 0, 0, 0}, //下り  advanced
                  {0, Section::VIRTUAL2, Section::LENGTH, 5, 0,30, 15.0, 5.0, 1, 1 /*setparam*/, -90*sign, 0, 0, 0, false, Judge::UNUPDATE, 0, 66, 0, 0, 0, 0, 0}, //下り  advanced
                  //センター置き終了
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -5, 0, _EDGE, Judge::UPDATE, 00, -4, 0, 0, 0,0 , 0 , 0 },  


                  // advanced ビンゴテスト
                  {0, Section::WALKER, Section::TURNANGLE,0, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 10, false, Judge::UPDATE, -89, 0, 0, 0, 0, 0, 0}, //下り  advanced
                  {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -5, 0, _EDGE, Judge::UPDATE, 00, -10, 0, 0,  0,0 , 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, 8, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 5, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 10, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  YELLOW,0.35, 0, 0},
                   // 設置（左） 
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, bspd, 0, 20, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false, Judge::UPDATE, 50*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,5}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, -10, 0, 20, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false, Judge::UNUPDATE, 0*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,1}, 
                    //設置完了
                  {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 23, 0, 0, 0, 0, 0}, 
                  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  YELLOW,0.35, 0, 0}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, bspd, 0, 20, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 11.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0}, 
                  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  GREEN,0.35, 0, 0}, 
                   // 設置（左） 
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, bspd, 0, 20, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false, Judge::UPDATE, 50*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,5}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, -10, 0, 20, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false, Judge::UNUPDATE, 0*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,1}, 
                    //設置完了
                    // 前方交点まで
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 23, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  GREEN,0.35, 0, 0}, 
                  //旋回（左）後交点まで
                   {0, Section::VIRTUAL, Section::TURNANGLE, bspd, 0, 20, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 11.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 12, 0, 0, 0, 0, 0}, 
                  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  GREEN,0.35, 0, 0}, 
                   // 設置（左） 
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, bspd, 0, 20, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false, Judge::UPDATE, 50*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,5}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, -10, 0, 20, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false, Judge::UNUPDATE, 0*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,1}, 
                    // 前方交点まで
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 20, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  BLUE,0.35, 0, 0}, 
                    // 前方交点まで
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 20, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  BLUE,0.35, 0, 0}, 
                  //旋回（左）後交点まで
                   {0, Section::VIRTUAL, Section::TURNANGLE, bspd, 0, 20, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 11.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 12, 0, 0, 0, 0, 0}, 
                  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  BLUE,0.35, 0, 0}, 
                   // 設置（左） 
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, bspd, 0, 20, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false, Judge::UPDATE, 50*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,5}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, -10, 0, 20, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false, Judge::UNUPDATE, 0*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,1}, 
                    // 前方交点まで
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 20, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  RED,0.35, 0, 0}, 
                   // 設置（左） 
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, bspd, 0, 20, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false, Judge::UPDATE, 50*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,5}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, -10, 0, 20, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false, Judge::UNUPDATE, 0*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,1}, 
                    // 前方交点まで
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 23, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  RED,0.35, 0, 0}, 
                  //旋回（左）後交点まで
                   {0, Section::VIRTUAL, Section::TURNANGLE, 10, 0, 20, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 11.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 12, 0, 0, 0, 0, 0}, 
                  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  RED,0.35, 0, 0}, 
                   // 設置（左） 
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, bspd, 0, 20, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false, Judge::UPDATE, 50*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,5}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, -10, 0, 20, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false, Judge::UNUPDATE, 0*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,1}, 
                    // 前方交点まで
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 20, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  YELLOW,0.35, 0, 0}, 
                    // 前方交点まで
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 20, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  YELLOW,0.35, 0, 0}, 
                  //旋回（左）後設置
                   {0, Section::VIRTUAL, Section::TURNANGLE, 10, 0, 20, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::VIRTUAL, Section::TURNANGLE, 10, 0, 20, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 10.5*sign, 0, 0, false, Judge::UNUPDATE, (90+80)*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::VIRTUAL, Section::TURNANGLE, -10, 0, 20, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 10.5*sign, 0, 0, false, Judge::UNUPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                    // 前方交点まで
                  {0, Section::TRACER, Section::LENGTH, 10, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  YELLOW,0.35, 0, 0}, 
                    // 前方交点まで
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 20, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  GREEN,0.35, 0, 0}, 
                  //旋回（左）後交点まで
                   {0, Section::VIRTUAL, Section::TURNANGLE, 10, 0, 20, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 11.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 12, 0, 0, 0, 0, 0}, 
                  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  GREEN,0.35, 0, 0}, 
                    // 前方交点まで
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 20, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  BLUE,0.35, 0, 0}, 
                   // 設置（右） 
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, bspd, 0, 20, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false, Judge::UPDATE, -50*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,5}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, -10, 0, 20, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false, Judge::UNUPDATE, 0*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,1}, 



                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 100000, 0, 0,0, 0, 0}, 

                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0},

};
  
  wParam a[50] = {{0, Section::VIRTUAL2, Section::LENGTH, 40, 0, 10, 0, 0, 1, 1 /*setparam*/, 0, 0, 30, 0, false, Judge::UPDATE, 0, 54, 0, 0, 0, 0, 0},
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
