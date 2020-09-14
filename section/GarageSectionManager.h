#ifndef _GARAGE_SECTION_MANAGER_H_
#define _GARAGE_SECTION_MANAGER_H_
#include "SectionManager.h"

typedef struct _Param14
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

} waParam;

class GarageSectionManager : public SectionManager
{
    public :
        GarageSectionManager();
        void init();
    private :
        int n;
        waParam wp[100] = {
                        // {0, Section::TRACER, Section::COLOR, 20, 0, 25, 0.2, 0.1, 0, 0 /*setparam*/, 0, 0, 0, 30, false,Judge::UPDATE, 0, 0, 0, 0, 208, 8, 0}, //スピードコースからの遷移を想定
                        // {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 15, 0, true,Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                        // {0, Section::WALKER, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 0, 0, 0, 0, 0, 1000},
                        // {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 15, 0, true,Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                        // {0, Section::WALKER, Section::TURNANGLE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 10, true,Judge::UPDATE, -89, 0, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL2, Section::LENGTH, 40, 0, 0.01, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 80, 0, 0, 0, 0, 0},
                        {0, Section::TRACER, Section::LENGTH, 8, 0, 25, 0.2, 0.1, 0, 0 /*setparam*/, 0, 0, 0, 30, false,Judge::UNUPDATE, 0, 100, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL2, Section::LENGTH, 40, 0, 0.01, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UNUPDATE, 0, 206, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 10, 0, true,Judge::UNUPDATE, 0, 212, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 7, 0, 1, 0, 0, 0, 0 /*setparam*/, 0, -5, 0, 0, true,Judge::UPDATE, -90, 0, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 30, 0, true,Judge::UPDATE, 0, 37, 0, 0, 0, 0, 0},
                        // {0, Section::WALKER, Section::TURNANGLE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0.5, true,Judge::UPDATE, 1, 0, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 0, 0, 0, 0, 0, 450},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -40, 0, true,Judge::UPDATE, 0, -10, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::TURNANGLE, -30, 0, 6, 0, 0, 0, 0 /*setparam*/, 0, -30, 0, 0, true,Judge::UPDATE, 91, 0, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -40, 0, true,Judge::UPDATE, 0, -116, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::TURNANGLE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, -13, true,Judge::UPDATE, 85, 0, 0, 0, 0, 0, 0},
                        {0, Section::TRACER, Section::LENGTH, 5, 0, 25, 0.2, 0.1, 0, 0 /*setparam*/, 0, 0, 0, 30, false,Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 40, 0, true,Judge::UNUPDATE, 0, 48, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::TURNANGLE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 5, true,Judge::UPDATE, -85, 0, 0, 0, 0, 0, 0},
                        {0, Section::TRACER, Section::LENGTH, 2, 0, 25, 0.2, 0.1, 0, 0 /*setparam*/, 0, 0, 0, 30, false,Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                        {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};
        void setWalker(int n,Section *sc);
        void setJudge(int n,Section *sc);
};

#endif
