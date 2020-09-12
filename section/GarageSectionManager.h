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
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 15, 0, true,Judge::UPDATE, 0, 217, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::TURNANGLE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 5, true,Judge::UPDATE, -85, 0, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 5, 0, true,Judge::UPDATE, 0, 50, 0, 0, 0, 0, 0},
                        // {0, Section::WALKER, Section::TURNANGLE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0.5, true,Judge::UPDATE, 1, 0, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 0, 0, 0, 0, 0, 300},
                        {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};
        void setWalker(int n,Section *sc);
        void setJudge(int n,Section *sc);
};

#endif
