#include "ColorJudge"

ColorJudge::ColorJudge(){
    hue = 0.0;
    satu = 0.0;

}
void ColorJudge::setColor(float h,float s){
    hue = h;
    satu = s;

}
bool ColorJudge::run(){
    if((h-mHsvHue->getValue())>=180){
            num=h+mHsvHue->getValue();
    }
    if(num-h=>sa2&&num-h=<sa1){
        if((s-mHsvSatu->getValue())=>sa3&&(s-mHsvSatu->getValue())=>sa4){
                return true;
        }
    }
    else{
        return false;
    }

}