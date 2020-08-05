#define _USE_MATH_DEFINES

#include "Odometry.h"
#include "math.h"
#include "HackEv3.h"

#define M_PI 3.14159265358979323846


Odometry::Odometry(Motor *left, Motor *right,
					Length *len,
					TurnAngle *angle,
					Velocity *velo):
	mLeftMotor(left),
	mRightMotor(right),
	mTurnAngle(angle),
	mLength(len),
	mVelocity(velo)
{
	mLeftMotor->reset();
	mRightMotor->reset();

	x=y=th=0.0;
	sumlen=0;
	prev_rs1=current_rs1=0;
	prev_rs2=current_rs2=0;
}



void Odometry::reset() 
{
	resetLength();
	resetAngle();

}
void Odometry::resetLength()
{
	sumlen=0.0;	
}
void Odometry::resetAngle()
{
	th=0.0;
	x=y=0;
	deg = 0.0;
}

void Odometry::update()
{
	current_rs1 = mLeftMotor->getCount();
	current_rs2 = mRightMotor->getCount();
	
	calc();
	mVelocity->update(current_rs1,current_rs2);

	prev_rs1=current_rs1;
	prev_rs2=current_rs2;
}

void Odometry::calc()
{

	static int count=0;

	float rs1 = current_rs1;
	float rs2 = current_rs2;

	//syslog(LOG_NOTICE,"rs1,rs2 = %d,%d <- %d,%d",(int)rs1,(int)rs2, prev_rs1,prev_rs2);

	float drs1=rs1-prev_rs1;
	float drs2=rs2-prev_rs2;

	float len_l = drs1*M_PI*D_LEFT/360.0;
	float len_r = drs2*M_PI*D_RIGHT/360.0;
	float dth=(len_r-len_l)/TREAD;
	
	x+= (len_r+len_l)/2.0*cos(th+dth/2.0); //進行方向 X軸 0度方向
	y+= (len_r+len_l)/2.0*sin(th+dth/2.0); //横	

	th+=dth; // 左旋回＋、右旋回-
	sumlen += (len_r+len_l)/2.0;

	mLength->update(sumlen);
	mTurnAngle->update(th);

}

void Odometry::setPwm(int left,int right)
{
	mLeftMotor->setPWM(left);
	mRightMotor->setPWM(right);
}