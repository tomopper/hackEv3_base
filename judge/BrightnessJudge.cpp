#include "BrightnessJudge.h"

BrightnessJudge::BrightnessJudge(){
    brightness = 0.0;
    flag = 0;

}
void BrightnessJudge::setBrightness(float x, int i){
    brightness = x;
    flag = i;

    


}

bool BrightnessJudge::run(){
    if(flag == 1){
        if(mBrightness->getValue() >= brightness){
            return true;
        }else{
            return false;
        }
    }else{
        if(mBrightness->getValue() <= brightness){
            return true;
        }else{
            return false;
        }
    }


    
}