#include "Section.h"
 
extern SimpleWalker *gWalker;
extern LineTracer *gTracer;
extern VirtualLineTracer *gVitual;
extern Odometry *gOdo;
extern SpeedControl *gSpeed;
extern TailWalker *gTailWalker;

Section::Section()
{
    first=true;
    first2=true;
}

Section::~Section()
{
    msg_log("destruct Section");
    delete mWalker;
}


bool Section::run()
{
    if(first2){
        mJudge->init();
        first2 = false;
    }
    //判定
    if(mJudge->run()){
        return true;
    }

    //走法
    if(first){
        mWalker->init();
        first = false;
    }
    mWalker->run();
    
    return false;
}

Walker *Section::selectWalker(int  no)
{
    switch(no) {
        case WALKER:
            mWalker = (Walker*)(new SimpleWalker(gOdo,gSpeed));
            break;
        case TRACER:
            mWalker = (Walker*)(new LineTracer(gOdo,gSpeed));
           break;
        case VIRTUAL:
            mWalker = (Walker*)(new VirtualLineTracer(gOdo,gSpeed));
            break;
        case VIRTUAL2:
            mWalker = (Walker*)(new VirtualLineTracer2(gOdo,gSpeed));
            break;
        case TAIL:
            mWalker = (Walker*)(new TailWalker(gOdo,gSpeed));
            // ((TailWalker*)mWalker)->setFlag(1);
            break;
        case ARM:
            mWalker = (Walker*)(new ArmWalker(gOdo,gSpeed));
            // ((ArmWalker*)mWalker)->setFlag(1);
            break;
        default:
            msg_log("selectWalker error!!");
    }

    return mWalker;
}


Judge *Section::selectJudge(int no)
{
    switch(no) {
        case LENGTH:
            mJudge = (Judge*)(new LengthJudge());
            break;
        case TURNANGLE:
            mJudge = (Judge*)(new TurnAngleJudge());
            break;
        case BRIGHTNESS:
            mJudge = (Judge*)(new BrightnessJudge());
            break;
        case COLOR:
            mJudge = (Judge*)(new ColorJudge());
            break;
        case TAILANGLE:
            mJudge = (Judge*)(new TailAngleJudge());
            break;
        case ARMANGLE:
            mJudge = (Judge*)(new ArmAngleJudge());
            break;
        default:
            msg_log("selectJudge error!!");
    }
    
    return mJudge;
}

void Section::init(){

    mWalker->init();
}
