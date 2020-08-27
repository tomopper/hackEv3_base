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

    protected:

    private:
        int n;
        
        wsParam wp[100] = {{0, Section::TAIL, Section::TAILANGLE, 0, 600, 0.5, 1, 0.0001, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 10000, 0, 0, 0, 0, 0},
                        {0, Section::ARM, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 10, 0, 0, 0, 0},
                        {0,Section::ARM, Section::LENGTH, 0, 0, 4, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 10, 0, 0, 0, 0},
                      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0}};
        void setWalker(Section *sc);
        void setJudge(Section *sc);
        

};

#endif
