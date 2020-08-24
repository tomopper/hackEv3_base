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

} wParam;

typedef struct _Param2
{

    int lflag;
    int tflag;

    float fangle;
    float flength;
    float bright1;
    float bright2;
    float color1;
    float color2;
} jParam;

class SpeedSectionManager : public SectionManager
{
public:
    SpeedSectionManager();

protected:
private:
    int n;
    wParam wp[100] = {{0, Section::TRACER, Section::LENGTH, 20, 0, 30, 0.2, 0.1, 0, 0 /*setparam*/, 0, 0, 0, 0, true},
                      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true}};
    jParam jp[100] = {{1, 1, 0, 200, 0, 0, 0, 0}};
    void setWalker(Section *sc);
    void setJudge(Section *sc);
};
#endif
