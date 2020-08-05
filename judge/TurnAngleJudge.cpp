#include "TurnAngleJudge.h"

TurnAngleJudge::TurnAngleJudge(){
    mStartAngle=0.0;
    mFinishAngle=0.0;



}

void TurnAngleJudge::setStartAngle(){
    mStartAngle = mTurnAngle->getValue();


}


void TurnAngleJudge::setFinishAngle(float finangle){
    mFinishAngle = mStartAngle + finangle;



}


bool TurnAngleJudge::run(){
    if(mTurnAngle->getValue() >= mFinishAngle){
        return true;
    }

    return false;

}