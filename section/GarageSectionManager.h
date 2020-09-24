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
        #if defined(MAKE_RIGHT)
            const int _EDGE = LineTracer::LEFTEDGE;
        #else
            const int _EDGE = LineTracer::RIGHTEDGE;
        #endif
        int n;
        waParam a[100] = {
                        // {0, Section::TRACER, Section::COLOR, 20, 0, 25, 0.2, 0.1, 0, 0 /*setparam*/, 0, 0, 0, 30, false,Judge::UPDATE, 0, 0, 0, 0, 208, 8, 0}, //スピードコースからの遷移を想定
                        // {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 15, 0, true,Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                        // {0, Section::WALKER, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 0, 0, 0, 0, 0, 1000},
                        // {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 10, 0, true,Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::TURNANGLE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 10, true,Judge::UPDATE, -87, 0, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL2, Section::LENGTH, 40, 0, 0.01, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 70, 0, 0, 0, 0, 0},
                        {0, Section::TRACER, Section::LENGTH, 5, 0, 30, 0, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, true,Judge::UNUPDATE, 0, 95, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL2, Section::LENGTH, 30, 0, 0.01, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true,Judge::UNUPDATE, 0, 192, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 10, 0, 1, 0, 0, 1.2, 1 /*setparam*/, 0, -45, 0, 0, true,Judge::UPDATE, -88, 0, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 10, 0, true,Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                        // {0, Section::VIRTUAL, Section::TURNANGLE, 7, 0, 1, 0, 0, 0, 0 /*setparam*/, 0, -5, 0, 0, true,Judge::UPDATE, -90, 0, 0, 0, 0, 0, 0},
                        // {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 30, 0, true,Judge::UPDATE, 0, 35, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 0, 0, 0, 0, 0, 500},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -40, 0, true,Judge::UPDATE, 0, -10, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::TURNANGLE, -30, 0, 6, 0, 0, 1.2, 1 /*setparam*/, 0, -30, 0, 0, true,Judge::UPDATE, 90, 0, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -60, 0, true,Judge::UPDATE, 0, -90, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::TURNANGLE, -30, 0, 6, 0, 0, 0.9, 1 /*setparam*/, 0, 30, 0, 0, true,Judge::UPDATE, -85, 0, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::BRIGHTNESS, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -30, 0, true,Judge::UPDATE, 0, 0, -0.7, 0, 0, 0, 0},
                        // {0, Section::WALKER, Section::TURNANGLE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, -10, true,Judge::UPDATE, 87, 0, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 10, 0, true,Judge::UPDATE, 0, 7, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::TURNANGLE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, -10, true,Judge::UPDATE, 87, 0, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -10, 0, true,Judge::UPDATE, 0, -10, 0, 0, 0, 0, 0},
                        // {0, Section::VIRTUAL, Section::TURNANGLE, 10, 0, 1, 0, 0, 1.2, 1 /*setparam*/, 0, -15, 0, 0, true,Judge::UPDATE, -88, 0, 0, 0, 0, 0, 0},
                        {0, Section::TRACER, Section::LENGTH, 5, 0, 25, 0, 0.1, 1, 1 /*setparam*/, 0, 0, 0, -30, false,Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                        // {0, Section::TRACER, Section::LENGTH, 2, 0, 25, 0, 0.1, 1, 1 /*setparam*/, 0, 0, 0, -30, false,Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                        {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

        waParam b[100] = {
                        // {0, Section::TRACER, Section::COLOR, 20, 0, 25, 0.2, 0.1, 0, 0 /*setparam*/, 0, 0, 0, 30, false,Judge::UPDATE, 0, 0, 0, 0, 208, 8, 0}, //スピードコースからの遷移を想定
                        // {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 15, 0, true,Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                        // {0, Section::WALKER, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 0, 0, 0, 0, 0, 1000},
                        // {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 15, 0, true,Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::TURNANGLE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, -10, true,Judge::UPDATE, 89, 0, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL2, Section::LENGTH, 40, 0, 0.01, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 80, 0, 0, 0, 0, 0},
                        {0, Section::TRACER, Section::LENGTH, 5, 0, 25, 0.2, 0.1, 0, 0 /*setparam*/, 0, 0, 0, 30, true,Judge::UNUPDATE, 0, 100, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL2, Section::LENGTH, 30, 0, 0.01, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UNUPDATE, 0, 200, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 10, 0, 1, 0, 0, 0, 0 /*setparam*/, 0, 15, 0, 0, true,Judge::UPDATE, 90, 0, 0, 0, 0, 0, 0},
                        // {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 10, 0, true,Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                        // {0, Section::VIRTUAL, Section::TURNANGLE, 7, 0, 1, 0, 0, 0, 0 /*setparam*/, 0, -5, 0, 0, true,Judge::UPDATE, -90, 0, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 30, 0, true,Judge::UPDATE, 0, 35, 0, 0, 0, 0, 0},
                        // {0, Section::WALKER, Section::TURNANGLE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0.5, true,Judge::UPDATE, 1, 0, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 0, 0, 0, 0, 0, 500},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -40, 0, true,Judge::UPDATE, 0, -10, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::TURNANGLE, -30, 0, 6, 0, 0, 0, 0 /*setparam*/, 0, 30, 0, 0, true,Judge::UPDATE, -91, 0, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -60, 0, true,Judge::UPDATE, 0, -100, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::TURNANGLE, -30, 0, 6, 0, 0, 0, 0 /*setparam*/, 0, -30, 0, 0, true,Judge::UPDATE, 90, 0, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::BRIGHTNESS, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -30, 0, true,Judge::UPDATE, 0, 0, 0.5, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::TURNANGLE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, -10, true,Judge::UPDATE, 87, 0, 0, 0, 0, 0, 0},
                        {0, Section::TRACER, Section::LENGTH, 5, 0, 25, 0.2, 0.1, 0, 0 /*setparam*/, 0, 0, 0, -30, true,Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                        {0, Section::TRACER, Section::LENGTH, 2, 0, 25, 0.2, 0.1, 0, 0 /*setparam*/, 0, 0, 0, 30, true,Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                        {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

        waParam *array[10]={a,b};
        waParam *wp;
        void setWalker(Section *sc);
        void setJudge(Section *sc);
};

#endif
