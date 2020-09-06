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
    //1の時現在地を更新可能, 終了角度, 終了距離,白黒割合 , 白黒計測フラグ, 色数値, 彩度数値}
    
    
    //setparamの例,Virtual2->setParam(10,5, 0.2, 0.2,1,1)
    // tracer->setParam(30,0,30,0.2,0.1)
    //Virtual->setParam(20,2,0.2,0,1,1)
    //Walker->setCommand(0,10)
   wParam wp[100] = {{0, Section::WALKER, Section::TURNANGLE, 30, 0, 30, 0.2, 0.1, 0, 0 /*setparam*/, 0, 0, 0, 10, true,Judge::UPDATE, -45, 60, 0, 0, 0, 0},
 //                   {0, Section::WALKER, Section::TURNANGLE, 2, 0, 30, 0.2, 0.1, 0, 0 /*setparam*/, 0, 0, 0, -30, true,Judge::UNUPDATE, 90, 50, 0, 0, 0, 0},
                    {0, Section::VIRTUAL2, Section::LENGTH, 30, 0, 20, 0.2, 0.01, 0, 0 /*setparam*/, -90, 0, 0, 0, true,Judge::UPDATE, 0, 100, 0, 0, 0, 0}, // 前進
                    {0, Section::VIRTUAL2, Section::LENGTH, -30, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 90, 0, 0, 0, true,Judge::UNUPDATE, 0, 100, 0, 0, 0, 0}, //後進(慣性で進んでいる間はPID0にする)
                    {0, Section::VIRTUAL2, Section::LENGTH, -30, 0, 15, 0.2, 0.01, 0, 0 /*setparam*/, 90, 0, 0, 0, true,Judge::UNUPDATE, 0, 0, 0, 0, 0, 0}, //後進

                    {0, Section::WALKER, Section::LENGTH, 0, 0, 0,0,0, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UNUPDATE, 0, 50000, 0, 0, 0, 0}, //停止用
                      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0}};

  


    void setWalker(Section *sc);
    void setJudge(Section *sc);
};
#endif


