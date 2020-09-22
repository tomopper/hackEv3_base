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
        #if defined(MAKE_RIGHT)
            const int _EDGE = LineTracer::LEFTEDGE;
        #else
            const int _EDGE = LineTracer::RIGHTEDGE;
        #endif
        
        int n;
        wsParam a[100] = {
                        // {0, Section::ARM, Section::ARMANGLE, 0, 30, 1, 0, 0, 0, 0/*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 9.5, 0, 0, 0, 0, 0, 0},
                        // {0, Section::WALKER, Section::GYRO, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 50, 0, true,Judge::UPDATE, -10, 50, 0, 0, 0, 0, 0}, //test用
                        {0, Section::ARM, Section::ARMANGLE, 0, -58, 1.5, 0, 0, 0, 0/*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, -58, 0, 0, 0, 0, 0, 0},
                        {0, Section::TRACER, Section::LENGTH, 5, 0, 1, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 20, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -5, 0, true,Judge::UPDATE, 0, -0.5, 0, 0, 0, 0, 0},
                        {0, Section::ARM, Section::ARMANGLE, 0, 30, 1, 0, 0, 0, 0/*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 9.5, 0, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 15, 0, true,Judge::UPDATE, 0, 22, 0, 0, 0, 0, 0},
                        {0, Section::TAIL, Section::TAILANGLE, 0, 600, 0.6, 0.4, 0.04, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 360, 0, 0, 0, 0, 0, 0}, // 600度目標で回すが、走行に制御を戻さないといけないので10度で終了
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 8, 0, true,Judge::UPDATE, 0, 2, 0, 0, 0, 0, 0}, //昇段
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0.5, 0, true,Judge::UPDATE, 0, 0.1, 0, 0, 0, 0, 0},
                        {0, Section::TAIL, Section::TAILANGLE, 0, 0, 1, 0.0, 0.00, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 6, 0, 0, 0, 0, 0, 0},// 尻尾をなめらかに本体の自重で落とす。早く走行に制御を戻すため、590度で終了
                        {0, Section::ARM, Section::ARMANGLE, 0, -50, 2, 0, 0, 0, 0/*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, -50, 0, 0, 0, 0, 0, 0},
                        {0, Section::TRACER, Section::LENGTH, 5, -0.7, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, -30, false,Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::LENGTH, 8, 0, 6, 0, 0, 1, 1 /*setparam*/, 0, 40, 0, 0, true,Judge::UPDATE, 0, 17, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 8, 0, 9, 0, 0, 1, 1 /*setparam*/, 0, -27, 0, 0, true,Judge::UPDATE, -60, 33, 0, 0, 0, 0, 0},
                        // {0, Section::VIRTUAL, Section::TURNANGLE, 8, 0, 30, 0, 0, 0.6, 1 /*setparam*/, 0, 30, 0, 0, true,Judge::UPDATE, 18, 8.5, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 30, 0, 0, 1, 1 /*setparam*/, 0, 18.7, 0, 0, true,Judge::UPDATE, 65.8, 22.5, 0, 0, 0, 0, 0},
                        // {0, Section::VIRTUAL, Section::TURNANGLE, 8, 0, 5, 0, 0, 1.4, 1 /*setparam*/, 0, -14, 0, 0, true,Judge::UPDATE, -13, 16, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 5, 0, 0, 1.1, 1 /*setparam*/, 0, -19.8, 0, 0, true,Judge::UPDATE, -81.5, 20.3, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 9, 0.7, true,Judge::UPDATE, 0, 11.27, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 5, 0, 0, 1, 1 /*setparam*/, 0, 30, 0, 0, true,Judge::UPDATE, 10.5, 22.5, 0, 0, 0, 0, 0},
                        // {0, Section::VIRTUAL, Section::TURNANGLE, 4, 0, 5, 0, 0, 1, 1 /*setparam*/, 0, -10, 0, 0, true,Judge::UPDATE, -70, 20.3, 0, 0, 0, 0, 0},
                        // {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 5, 0.4, true,Judge::UPDATE, 0, 17, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::TURNANGLE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 10, true,Judge::UPDATE, -40, 0, 0, 0, 0, 0, 0},
                        {0, Section::TRACER, Section::LENGTH, 5, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, -30, false,Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 15, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 40, 0, false,Judge::UNUPDATE, 0, 42, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                        {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

        wsParam b[100] = {
                        {0, Section::ARM, Section::ARMANGLE, 0, -58, 1.5, 0, 0, 0, 0/*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, -58, 0, 0, 0, 0, 0, 0},
                        {0, Section::TRACER, Section::LENGTH, 5, 0, 1, 0.2, 0.1, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 20, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -5, 0, true,Judge::UPDATE, 0, -0.5, 0, 0, 0, 0, 0},
                        {0, Section::ARM, Section::ARMANGLE, 0, 30, 1, 0, 0, 0, 0/*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 9.5, 0, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 15, 0, true,Judge::UPDATE, 0, 22, 0, 0, 0, 0, 0},
                        {0, Section::TAIL, Section::TAILANGLE, 0, 600, 0.6, 0.4, 0.04, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 360, 0, 0, 0, 0, 0, 0}, // 600度目標で回すが、走行に制御を戻さないといけないので10度で終了
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 8, 0, true,Judge::UPDATE, 0, 2, 0, 0, 0, 0, 0}, //昇段
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0.5, 0, true,Judge::UPDATE, 0, 0.1, 0, 0, 0, 0, 0},
                        {0, Section::TAIL, Section::TAILANGLE, 0, 0, 1, 0.0, 0.00, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 6, 0, 0, 0, 0, 0, 0},// 尻尾をなめらかに本体の自重で落とす。早く走行に制御を戻すため、590度で終了
                        // {0, Section::WALKER, Section::TAILANGLE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 1, 0, true,Judge::UPDATE, 6, 0 , 0, 0, 0, 0, 0},// 微速前進しながら、尻尾が落ちるのを待つ
                        {0, Section::ARM, Section::ARMANGLE, 0, -50, 2, 0, 0, 0, 0/*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, -50, 0, 0, 0, 0, 0, 0},
                        // {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 1, 0, true,Judge::UNUPDATE, 0, 1, 0, 0, 0, 0, 0}, //仕上げの前進
                        // {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 10000 , 0, 0, 0, 0, 0},  // stop
                        // {0, Section::TRACER, Section::LENGTH, 2, 0, 8, 0.2, 0.1, 0, 0 /*setparam*/, 0, 0, 0, 30, true,Judge::UPDATE, 0, 8, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 25, 0, true,Judge::UPDATE, 0, 6, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::LENGTH, 10, 0, 3, 0, 0, 0, 0 /*setparam*/, 0, -40, 0, 0, true,Judge::UPDATE, 0, 19.4, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::LENGTH, 8, 0, 9, 0, 0, 0, 0 /*setparam*/, 0, 32, 0, 0, true,Judge::UPDATE, 0, 30.5, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::LENGTH, 8, 0, 10, 0, 0, 0, 0 /*setparam*/, 0, -20.8, 0, 0, true,Judge::UPDATE, 0, 10.5, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::LENGTH, 3, 0, 10, 0, 0, 0, 0 /*setparam*/, 0, -20.8, 0, 0, true,Judge::UNUPDATE, 0, 22, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::LENGTH, 8, 0, 5, 0, 0, 0, 0 /*setparam*/, 0, 15, 0, 0, true,Judge::UPDATE, 0, 16.5, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::LENGTH, 3, 0, 5, 0, 0, 0, 0 /*setparam*/, 0, 15, 0, 0, true,Judge::UNUPDATE, 0, 19.7, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 5, 0.7, true,Judge::UPDATE, 0, 17, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::TURNANGLE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, -3, true,Judge::UPDATE, 41, 0, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 8, 0, true,Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 60, 0, true,Judge::UNUPDATE, 0, 45, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                        {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};
        void setWalker(Section *sc);
        void setJudge(Section *sc);
        wsParam *array[10]={a,b};
        wsParam *wp;

};

#endif
