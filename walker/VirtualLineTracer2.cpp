#include "VirtualLineTracer2.h"
#include "math.h"
#define M_PI 3.14159265358979323846
VirtualLineTracer2::VirtualLineTracer2(Odometry *odo,
                        SpeedControl *scon)
                         : SimpleWalker(odo,scon) {
    sx=0;
    sy=0;
    fx=0;
    fy=0;
    nx=0;
    ny=0;
    basedistance=0;
    mTarget=0;
    mTargetSpeed=0;
    mPFactor=0;
    mIFactor=0;
    mDFactor=0;
    mLimit = 100;
}

void VirtualLineTracer2::setParam(float speed,float kp, float ki, float kd,float angleTarget,float angleKp){


    msg_log("testtt");
    mTargetSpeed = speed;
    
    mPFactor = kp;
    mIFactor = ki;
    mDFactor = kd;

  
    mTarget= 0;
    mPid->setTarget(mTarget);


    
    mPid->setKp(mPFactor); 
    mPid->setKi(mIFactor);
    mPid->setKd(mDFactor);
   
    mCurve = angleTarget;
    mAngleKp = angleKp;

}

void    VirtualLineTracer2::setsPosition(float x,float y){
    sx = x+mXPosition->getvalue();
    sy = y+mYPosition->getvalue();

}
void    VirtualLineTracer2::setfPosition(float x,float y){
    fx = x+mXPosition->getvalue();
    fy = y+mYPosition->getvalue();

}

void  VirtualLineTracer2::setRelaTurnAngle(float angle,float dangle){
setsPosition(0,0);
setfPosition( 100*cos((angle/180)*M_PI+(dangle/180)*M_PI), 100*sin((angle/180)*M_PI+(angle/180)*M_PI));
}
void  VirtualLineTracer2::setAbsTurnAngle(float angle){

setsPosition(0,0);
setfPosition( 100*cos((angle/180)*M_PI),100*sin((angle/180)*M_PI));
   static char buf[256];
    sprintf(buf," %f,%f",100*cos(angle),100*sin(angle));
    msg_log(buf);

}


void    VirtualLineTracer2::setnPosition(){
    nx = mXPosition->getvalue();
    ny = mYPosition->getvalue();

}

float VirtualLineTracer2::calcdistance(){
     static char buf[256];
    sprintf(buf," %f",((fy-sy)*nx-(fx-sx)*ny+fx*sy-fy*sx)/sqrt((fx-sx)*(fx-sx)+(fy-sy)*(fy-sy)));
    msg_log(buf);

    return ((fy-sy)*nx-(fx-sx)*ny+fx*sy-fy*sx)/sqrt((fx-sx)*(fx-sx)+(fy-sy)*(fy-sy));
} 

float VirtualLineTracer2::calcTurn(){
        

        float val1_turn =  mPid->getOperation(calcdistance());


        return val1_turn ;
}

void VirtualLineTracer2::run(){
    setnPosition();
        mTurn = -(calcTurn());
      //     static char buf[256];
    //sprintf(buf,"%d",mTurn);
   // msg_log(buf);



    setCommandV((int)mTargetSpeed, (int)mTurn);
    SimpleWalker::run();


}