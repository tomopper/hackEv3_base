#ifndef _SLALOM_SECTION_MANAGER_H_
#define _SLALOM_SECTION_MANAGER_H_
#include "SectionManager.h"

typedef struct _Param11
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


    int jflag;

    float fangle;
    float flength;
    float bright1;
    float bright2;
    float color1;
    float color2;

} wsParam;

class SlalomSectionManager : public SectionManager
{
    public:
        SlalomSectionManager();
        void init();

    protected:

    private:
        //int n;
        
        wsParam wp[100] = {
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 5, 0, true,Judge::UPDATE, 0, 32, 0, 0, 0, 0},
                        {0, Section::TAIL, Section::TAILANGLE, 0, 600, 0.5, 2.0, 0.04, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 10, 0, 0, 0, 0, 0}, // 600度目標で回すが、走行に制御を戻さないといけないので10度で終了
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 8, 0, true,Judge::UPDATE, 0, 8, 0, 0, 0, 0}, //昇段
                        {0, Section::TAIL, Section::TAILANGLE, 0, 0, 0.01, 0.0, 0.00, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 590, 0, 0, 0, 0, 0},// 尻尾をなめらかに本体の自重で落とす。早く走行に制御を戻すため、590度で終了
                        {0, Section::WALKER, Section::TAILANGLE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 1, 0, true,Judge::UPDATE, 100, 0 , 0, 0, 0, 0},// 微速前進しながら、尻尾が落ちるのを待つ
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 8, 0, true,Judge::UPDATE, 0, 15 , 0, 0, 0, 0}, //仕上げの前進
                            {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 10000 , 0, 0, 0, 0},  // stop

                        {-1,Section::ARM, Section::LENGTH, 0, 0, 4, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 10, 0, 0, 0, 0},
                      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0}};
        void setWalker(int n,Section *sc);
        void setJudge(int n,Section *sc);
        

};

#endif
