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
                        {0, Section::WALKER, Section::TURNANGLE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 22.5, true,Judge::UPDATE, -88, 0, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL2, Section::LENGTH, 40, 0, 0.01, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 70, 0, 0, 0, 0, 0},
                        {0, Section::TRACER, Section::LENGTH, 5, 0, 30, 0, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, true,Judge::UPDATE, 0, 25, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL2, Section::LENGTH, 30, 0, 0.01, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 85, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 20, 0, 1, 0, 0, 1.2, 1 /*setparam*/, 0, -30, 0, 0, true,Judge::UPDATE, -85, 0, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 25, 0, true,Judge::UPDATE, 0, 26, 0, 0, 0, 0, 0},
                        // {0, Section::VIRTUAL, Section::TURNANGLE, 7, 0, 1, 0, 0, 0, 0 /*setparam*/, 0, -5, 0, 0, true,Judge::UPDATE, -90, 0, 0, 0, 0, 0, 0},
                        // {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 30, 0, true,Judge::UPDATE, 0, 35, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 0, 0, 0, 0, 0, 550},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -40, 0, true,Judge::UPDATE, 0, -10, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::TURNANGLE, -30, 0, 6, 0, 0, 1.2, 1 /*setparam*/, 0, -30, 0, 0, true,Judge::UPDATE, 90, 0, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -60, 0, true,Judge::UPDATE, 0, -75, 0, 0, 0, 0, 0},
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
                        {0, Section::TRACER, Section::TURNANGLE, 30, 0, 30, 0, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, true,Judge::UPDATE, 85, 25, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::BRIGHTNESS, 20, 0, 30, 0, 0, 1.2, 1 /*setparam*/, 0, 32, 0, 0, true,Judge::UPDATE, -50, 0, -0.7, 0, 0, 0, 0},
                        {0, Section::TRACER, Section::LENGTH, 5, 0, 30, 0, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, true,Judge::UPDATE, -80, 12.5, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 10, 0, 30, 0, 0, 0.8, 1 /*setparam*/, 0, -16, 0, 0, true,Judge::UPDATE, -83, 0, -0.3, 0, 0, 0, 0},
                        // {0, Section::VIRTUAL, Section::BRIGHTNESS, 20, 0, 30, 0, 0, 0.8, 1 /*setparam*/, 0, 40, 0, 0, true,Judge::UPDATE, 85, 0, -0.4, 0, 0, 0, 0},
                        {0, Section::TRACER, Section::LENGTH, 5, 0, 30, 0, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, true,Judge::UPDATE, -85, 11, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL2, Section::LENGTH, 30, 0, 0.01, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 70, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 20, 0, 1, 0, 0, 1.2, 1 /*setparam*/, 0, 28, 0, 0, true,Judge::UPDATE, 85, 0, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 25, 0, true,Judge::UPDATE, 0, 29, 0, 0, 0, 0, 0},
                        // {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 17, 0, true,Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                        // {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 10, 0, true,Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                        // {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 5, 0, true,Judge::UPDATE, 0, 3, 0, 0, 0, 0, 0},
                        // {0, Section::VIRTUAL, Section::TURNANGLE, 7, 0, 1, 0, 0, 0, 0 /*setparam*/, 0, -5, 0, 0, true,Judge::UPDATE, -90, 0, 0, 0, 0, 0, 0},
                        // {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 30, 0, true,Judge::UPDATE, 0, 35, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 0, 0, 0, 0, 0, 555},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -40, 0, true,Judge::UPDATE, 0, -15, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::TURNANGLE, -30, 0, 6, 0, 0, 1.2, 1 /*setparam*/, 0, 30, 0, 0, true,Judge::UPDATE, -90, 0, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -60, 0, true,Judge::UPDATE, 0, -83, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::TURNANGLE, -30, 0, 6, 0, 0, 0.9, 1 /*setparam*/, 0, -30, 0, 0, true,Judge::UPDATE, 85, 0, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -30, 0, true,Judge::UPDATE, 0, -30, -0.7, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::BRIGHTNESS, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -30, 0, true,Judge::UPDATE, 0, 0, 0.5, 0, 0, 0, 0},
                        // {0, Section::WALKER, Section::TURNANGLE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, -10, true,Judge::UPDATE, 87, 0, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 10, 0, true,Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::TURNANGLE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 10, true,Judge::UPDATE, -87, 0, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -10, 0, true,Judge::UPDATE, 0, -10, 0, 0, 0, 0, 0},
                        // {0, Section::VIRTUAL, Section::TURNANGLE, 10, 0, 1, 0, 0, 1.2, 1 /*setparam*/, 0, -15, 0, 0, true,Judge::UPDATE, -88, 0, 0, 0, 0, 0, 0},
                        {0, Section::TRACER, Section::LENGTH, 5, 0, 25, 0, 0.1, 1, 1 /*setparam*/, 0, 0, 0, -30, true,Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                        // {0, Section::TRACER, Section::LENGTH, 2, 0, 25, 0, 0.1, 1, 1 /*setparam*/, 0, 0, 0, -30, false,Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                        {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};
        
         waParam a1[100] = {
                        // {0, Section::TRACER, Section::TURNANGLE, 30, 0, 30, 0.2, 0.135, 1, 1 /*setparam*/, 0, 0, 0, 30, false,Judge::UNUPDATE, 3, 25, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 20, 0, 30, 0, 0, 1.2, 1 /*setparam*/, 0, -28, 0, 0, true,Judge::UNUPDATE, -85, 0, -0.4, 0, 0, 0, 0},
                        {0, Section::TRACER, Section::COLOR, 6, 0, 30, 0, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, true,Judge::UNUPDATE, -85, 12.7, 0, 0, 141, 0.9, 0},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 7, 0, 30, 0, 0, 0.8, 1 /*setparam*/, 0, 10.5, 0, 0, true,Judge::UNUPDATE, 5, 0, -0.3, 0, 0, 0, 0},
                        // {0, Section::VIRTUAL, Section::BRIGHTNESS, 20, 0, 30, 0, 0, 0.8, 1 /*setparam*/, 0, 40, 0, 0, true,Judge::UPDATE, 85, 0, -0.4, 0, 0, 0, 0},
                        {0, Section::TRACER, Section::COLOR, 5, -0.7, 30, 0, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, true,Judge::UPDATE, -85, 12, 0, 0, 57, 0.9, 0},
                        {0, Section::WALKER, Section::LENGTH, 30, 0, 0.01, 0, 0, 1, 1 /*setparam*/, 0, -1, 30, 0, true,Judge::UPDATE, 0, 72.7, 0, 0, 0, 0, 0},
                        // {0, Section::VIRTUAL2, Section::LENGTH, 30, 0, 30, 0, 0.4, 1, 1 /*setparam*/, 0, 0, 30, 0, true,Judge::UNUPDATE, 0, 72, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 20, 0, 1, 0, 0, 1.2, 1 /*setparam*/, 0, -28, 0, 0, true,Judge::UNUPDATE, -88, 0, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 15, 0, true,Judge::UPDATE, 0, 24, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 0, 0, 0, 0, 0, 555},
                        {0, Section::ARM, Section::ARMANGLE, 0, -60, 20, 0, 0, 0, 0/*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, -58, 0, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -40, 0, true,Judge::UPDATE, 0, -10, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::TURNANGLE, -20, 0, 6, 0, 0, 1, 1 /*setparam*/, 0, -30, 0, 0, true,Judge::UNUPDATE, -1, 0, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -42, 0, true,Judge::UPDATE, 0, -91, 0, 0, 0, 0, 0},
                        // {0, Section::VIRTUAL2, Section::LENGTH, 12, 0, 30, 0, 0.8, 1, 1 /*setparam*/, 0, 0, 30, 0, true,Judge::UNUPDATE, 0, -90, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::TURNANGLE, -30, 0, 6, 0, 0, 1, 1 /*setparam*/, 0, 30, 0, 0, true,Judge::UNUPDATE, -85, 0, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -24, 0, true,Judge::UPDATE, 0, -30, -0.7, 0, 0, 0, 0},
                        {0, Section::ARM, Section::LENGTH, 0, -50, 3, 0, 0, 0, 0/*setparam*/, 0, 0, 0, 0, true,Judge::UNUPDATE, 6, -35, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::BRIGHTNESS, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -10, 0, true,Judge::UPDATE, 0, 0, 0.3, 0, 0, 0, 0},
                        // {0, Section::WALKER, Section::TURNANGLE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, -10, true,Judge::UPDATE, 87, 0, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 8, 0, true,Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::TURNANGLE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, -10, true,Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0},
                        // {0, Section::WALKER, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -5, 0, true,Judge::UPDATE, 0, -12.5, 0, 0, 0, 0, 0},
                        // {0, Section::VIRTUAL, Section::TURNANGLE, 10, 0, 1, 0, 0, 1.2, 1 /*setparam*/, 0, -15, 0, 0, true,Judge::UPDATE, -88, 0, 0, 0, 0, 0, 0},
                        {0, Section::TRACER, Section::LENGTH, 4, 0, 30, 0, 0.1, 1, 1 /*setparam*/, 0, 0, 0, -30, false,Judge::UNUPDATE, 0, 10.5, 0, 0, 0, 0, 0},
                        // {0, Section::TRACER, Section::LENGTH, 2, 0, 25, 0, 0.1, 1, 1 /*setparam*/, 0, 0, 0, -30, false,Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                        {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

         waParam b1[100] = {
                        {0, Section::TRACER, Section::TURNANGLE, 30, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 30, true,Judge::UNUPDATE, -10, 25, 0, 0, 0, 0, 0},
                        {0, Section::TRACER, Section::LENGTH, 30, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 30, true,Judge::UPDATE, 10, 5, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 20, 0, 30, 0, 0.3, 1, 1 /*setparam*/, 0, 30, 0, 0, true,Judge::UNUPDATE, 85, 0, -0.4, 0, 0, 0, 0},
                        {0, Section::TRACER, Section::COLOR, 6, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 30, false,Judge::UNUPDATE, -85, 12.7, 0, 0, 141, 0.9, 0},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 10, 0, 30, 0, 0, 1/0.8, 1 /*setparam*/, 0, -11, 0, 0, true,Judge::UNUPDATE, -9, 0, -0.3, 0, 0, 0, 0},
                        // {0, Section::VIRTUAL, Section::BRIGHTNESS, 20, 0, 30, 0, 0, 0.8, 1 /*setparam*/, 0, 40, 0, 0, true,Judge::UPDATE, 85, 0, -0.4, 0, 0, 0, 0},
                        {0, Section::TRACER, Section::COLOR, 5, -0.7, 30, 0, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, false,Judge::UPDATE, -85, 12, 0, 0, 57, 0.9, 0},
                        {0, Section::WALKER, Section::LENGTH, 30, 0, 0.01, 0, 0, 1, 1 /*setparam*/, 0, -1, 30, 0, true,Judge::UPDATE, 0, 79, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 20, 0, 1, 0, 0, 1/1.2, 1 /*setparam*/, 0, 28, 0, 0, true,Judge::UNUPDATE, 88, 0, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 15, 0, true,Judge::UPDATE, 0, 30, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 0, 0, 0, 0, 0, 555},
                        {0, Section::ARM, Section::ARMANGLE, 0, -60, 20, 0, 0, 0, 0/*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, -58, 0, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -40, 0, true,Judge::UPDATE, 0, -10, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::TURNANGLE, -30, 0, 6, 0, 0, 1, 1 /*setparam*/, 0, 30, 0, 0, true,Judge::UNUPDATE, 5, 0, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -42, 0, true,Judge::UPDATE, 0, -90, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::TURNANGLE, -30, 0, 6, 0, 0, 1, 1 /*setparam*/, 0, -30, 0, 0, true,Judge::UNUPDATE, 85, 0, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -20, 0, true,Judge::UPDATE, 0, -30, -0.7, 0, 0, 0, 0},
                        {0, Section::ARM, Section::LENGTH, 0, -50, 3, 0, 0, 0, 0/*setparam*/, 0, 0, 0, 0, true,Judge::UNUPDATE, 6, -34, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::BRIGHTNESS, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -10, 0, true,Judge::UPDATE, 0, 0, 0.3, 0, 0, 0, 0},
                        // {0, Section::WALKER, Section::TURNANGLE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, -10, true,Judge::UPDATE, 87, 0, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 8, 0, true,Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::TURNANGLE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 10, true,Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0},
                        // {0, Section::WALKER, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -5, 0, true,Judge::UPDATE, 0, -10, 0, 0, 0, 0, 0},
                        // {0, Section::VIRTUAL, Section::TURNANGLE, 10, 0, 1, 0, 0, 1.2, 1 /*setparam*/, 0, -15, 0, 0, true,Judge::UPDATE, -88, 0, 0, 0, 0, 0, 0},
                        {0, Section::TRACER, Section::LENGTH, 4, 0, 30, 0, 0.1, 1, 1 /*setparam*/, 0, 0, 0, -30, true,Judge::UNUPDATE, 0, 10, 0, 0, 0, 0, 0},
                        // {0, Section::TRACER, Section::LENGTH, 2, 0, 25, 0, 0.1, 1, 1 /*setparam*/, 0, 0, 0, -30, false,Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                        {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

        waParam *array[10]={a1,b1};
        waParam *wp;
        void setWalker(Section *sc);
        void setJudge(Section *sc);
};

#endif
