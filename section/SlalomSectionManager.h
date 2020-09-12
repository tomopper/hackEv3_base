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


    Judge::JUDGE_MODE jflag;

    float fangle;
    float flength;
    float bright1;
    float bright2;
    float color1;
    float color2;
    float count;

} wsParam;

class SlalomSectionManager : public SectionManager
{
    public:
        SlalomSectionManager();
        void init();

    protected:

    private:
        int n;
        wsParam wp[100] = {
                        {0, Section::ARM, Section::ARMANGLE, 0, -58, 1, 0, 0, 0, 0/*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, -58, 0, 0, 0, 0, 0, 0},
                        {0, Section::TRACER, Section::LENGTH, 5, 0, 1, 0.2, 0.1, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 30, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -5, 0, true,Judge::UPDATE, 0, -6, 0, 0, 0, 0, 0},
                        {0, Section::ARM, Section::ARMANGLE, 0, 30, 1, 0, 0, 0, 0/*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 15, 0, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 5, 0, true,Judge::UPDATE, 0, 22, 0, 0, 0, 0, 0},
                        {0, Section::TAIL, Section::TAILANGLE, 0, 600, 0.5, 2.0, 0.04, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 10, 0, 0, 0, 0, 0, 0}, // 600度目標で回すが、走行に制御を戻さないといけないので10度で終了
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 8, 0, true,Judge::UPDATE, 0, 1, 0, 0, 0, 0, 0}, //昇段
                        {0, Section::TAIL, Section::TAILANGLE, 0, 0, 0.01, 0.0, 0.00, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 570, 0, 0, 0, 0, 0, 0},// 尻尾をなめらかに本体の自重で落とす。早く走行に制御を戻すため、590度で終了
                        {0, Section::WALKER, Section::TAILANGLE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0.1, 0, true,Judge::UNUPDATE, 6, 0 , 0, 0, 0, 0, 0},// 微速前進しながら、尻尾が落ちるのを待つ
                        // {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 1, 0, true,Judge::UNUPDATE, 0, 1, 0, 0, 0, 0, 0}, //仕上げの前進
                        // {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 10000 , 0, 0, 0, 0, 0},  // stop
                        // {0, Section::VIRTUAL, Section::LENGTH, 5, 180, 2, 0, 0, 0, 0 /*setparam*/, 0, 30, 0, 0, true,Judge::UNUPDATE, 0, 45, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 5, 0, true,Judge::UPDATE, 0, 6, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::LENGTH, 5, 0, 3, 0, 0, 0, 0 /*setparam*/, 0, 40, 0, 0, true,Judge::UPDATE, 0, 16.4, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::LENGTH, 3, 0, 0.2, 0, 0, 0, 0 /*setparam*/, 0, -60, 0, 0, true,Judge::UPDATE, 0, 28.4, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::LENGTH, 3, 0, 0.2, 0, 0, 0, 0 /*setparam*/, 0, 60, 0, 0, true,Judge::UPDATE, 0, 26.5, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::LENGTH, 3, 0, 0.25, 0, 0, 0, 0 /*setparam*/, 0, -60, 0, 0, true,Judge::UPDATE, 0, 23, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 3, 0, true,Judge::UPDATE, 0, 17, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::TURNANGLE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 10, true,Judge::UPDATE, -28, 0, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 8, 0, true,Judge::UPDATE, 0, 40, 0, 0, 0, 0, 0},
                        {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};
        void setWalker(int n,Section *sc);
        void setJudge(int n,Section *sc);
        

};

#endif
