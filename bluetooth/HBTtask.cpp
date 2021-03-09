#include "HBTtask.h"
#include "SpeedSectionManager.h"
#include "Section.h"
#include "util.h"
#include <syssvc/serial.h>
#include "ev3api.h"
#include "Stop.h"
#include "app.h"

#include "Scene.h"

#include "global.h"

HBTtask::HBTtask() {

	bt = ev3_serial_open_file(EV3_SERIAL_BT);

	buffer = -1;
			printf("HBTtask constructed\n");    		

}
HBTtask::~HBTtask() {
	fclose(bt);
}

void HBTtask::mStop()
{
	/*ev3_motor_config(EV3_PORT_C, LARGE_MOTOR);
	ev3_motor_config(EV3_PORT_B, LARGE_MOTOR);
	msg_f("stopcheck",2);
	uint8_t c;
	c= fgetc(bt);
	
	if(c == 's')
	{
		ev3_motor_stop(EV3_PORT_C, false);
		ev3_motor_stop(EV3_PORT_B, false);
		ev3_speaker_play_tone(100,100);

		msg_f("stopok",2);
	}*/


}


//*****************************************************************************
// 関数名 : bt_task
// 引数 : unused
// 返り値 : なし
// 概要 : Bluetooth通信でコマンドを受信する。
//*****************************************************************************
#if 1
void HBTtask::reciev()
{   
	static int cnt=0;
	char buf[256];

//		send_stop = true;
		msg_f("HBTtask reciev start",1);

			printf("HBTtask reciev start\n");    		

	/*while(!ev3_bluetooth_is_connected()) {
			tslp_tsk(100);
	}

	bt = ev3_serial_open_file(EV3_SERIAL_BT);    //bluetooth開始
*/
	while(1) {
		printf("receiv:%d\n",cnt++);
		msg_f("receiv:",1);
		//ev3_speaker_play_tone(1000,100);

		if (ev3_button_is_pressed(BACK_BUTTON)) {
			return ;
		}
		//ev3_motor_config (EV3_PORT_B, LARGE_MOTOR);
	    //ev3_motor_config (EV3_PORT_C, LARGE_MOTOR);
			int disp=1;
				// 受信
					uint8_t c;
				int mode=-1;
			int sign=1;
			char *cmd[] = {"","","","foword","turn","angle","R","G","B","Y","K","bonus"};

				c= fgetc(bt);
			 // sprintf(buf,"getc:%c,%d",c,cnt++);文字列を作る。
			 // msg_f(buf,1);
				int ccc=99999;
				float num = 0;
				switch(c) {
					/*case 'g':
						disp=2;
						msg_f("clear",disp);
						ev3_led_set_color(LED_GREEN);  //初期化完了通知
						break ;*/
					case 'z':
						ev3_speaker_play_tone(10,10);
						num=1;
						break;
					case 'f':
						mode=0;
						num=0;
						//setFlag(0);
						msg_f("forward",3);
						break;
					case 'r': //赤を見つけた時の処理
						mode=1;
						disp=3;
						msg_f("RedStop",disp);
						num=0;
						break;
					case 'b': //青を見つけた時の処理
						mode=2;
						disp=3;
						msg_f("BlueStop",disp);
						//setSendchar('B');
						//setFlag(2);
						num=0;
						break;
					case 't':
						mode=3;
						num=0;
						msg_f("turn",3);
						//setFlag(3);
						break;
					/*case 'g':
						disp=2;
						msg_f("GO",disp);
						//setSendchar2('G');
						num=1;
						break;
					case 's':
						disp=2;
						msg_f("STOP",disp);
						//setSendchar2('S');
						num=1;
						break;
					*/
					case 'a':
						mode=2;
						disp=5;
							//msg_f("tail", disp);
						break;
					// ブロックビンゴ用
					case 'R':
						mode=10;
						disp=6;
						break;
					case 'G':
						mode=11;
						disp=7;
						break;
					case 'B':
						mode=12;
						disp=8;
						break;
					case 'Y':
						mode=13;
						disp=9;
						break;
					case 'K':
						mode=14;
						disp=10;
						break;
					/*case 'x':
						mode=15;
						disp=11;
						break;*/

				default:
					disp=6;
					msg_f("****", disp);
					return ;
				}

			if(num==1) continue;//g,sの時にwhileに入らずにループ

				//while((c= fgetc(bt))!='') { //4桁で受け取るのが確定してるなら4回ループでもあり
				for(int i=0; i<8; i++){
					c = fgetc(bt);
					if(c=='-') {
						sign=-1;
					}else {
						int x= c- '0';
						num *=10;
						num += x; 
					}
					
				}

				int coppy = num * 10;

				float first = (num / 10000); //上4桁取り出し(x)
				float last = (coppy % 100000) / 10.0;  //下4桁取り出し(Y)

				setFirst(first);
				setLast(last);

				msg_f(" ",3);

				num *= sign;
			sprintf(buf,"%s:%4d",cmd[disp],num);
			//msg_f(buf,disp);

			switch(mode) {
				case 0: //直進
					setFlag(0);
					setSendchar('F');
					break;
				case 1: //RedStop
					setFlag(1);
					setSendchar('R');
					break;
				case 2: //BlueStop
					setFlag(2);
					setSendchar('B');
					break;
				case 3: //旋回
					setFlag(3);
					setSendchar('T');
					break;
				case 10:
					r_num=num;
					break;
				case 11:
					g_num=num;
					break;
				case 12:
					b_num=num;
					break;
				case 13:
					y_num=num;
					break;
				case 14:
					k_num=num;
					break;
				case 15:
					bonus_num=num;
					break;

			}
		//msg_f("c",6);
		if(ccc==99999) continue; //ループ
	} 		
}
#endif

#define TEXT 
//#define BINARY

void HBTtask::send()
{
    char buf[256];
	
	//while(1) {
	    	// 送信
		uint8_t c;
	//	fputc('*',bt);
	//	tslp_tsk(10);
		int cnt=0;
		bool stop = false;
	
	  	while(!send_stop && !empty()) {
    		T_SENDBUF x = dequeue();
			//msg_f(buf, 1);
    		
    		int8_t cnt=0;
#ifdef	TEXT
    		/*sprintf(buf,"T%d\nL%d\nR%d\nM%d\nA%d\nG%d\nC%d\nK%d\nr%d\ng%d\nb%d\nS%d\nV%d\n"
    			,(int)x.cnt,(int)x.motor_l,(int)x.motor_r,(int)x.motor_arm,(int)x.angle,(int)x.gyro,
    			(int)x.color,(int)x.light,(int)x.rgb.r,(int)x.rgb.g,(int)x.rgb.b,(int)x.sonar,(int)x.volt);*/
			sprintf(buf,"T%d\nL%d\nR%d\nM%d\nG%d\nK%d\nk%d\nr%d\ng%d\nb%d\nS%d\nV%d\nX%d\nY%d\nD%d\nl%d\nA%d\ns%d\n"
    			,(int)x.cnt,(int)x.motor_l,(int)x.motor_r,(int)x.motor_arm,(int)x.gyro
				,(int)x.light,(int)(x.light_rate*10000),(int)x.r,(int)x.g,(int)x.b, (int)x.sonar,(int)x.volt,
				(int)(x.x*100),(int)(x.y*100),(int)(x.th*18000/3.14),(int)(x.len*100),(int)(x.angle*100),(int)(x.v*100));

    		while((c=buf[cnt++])!=0) {
    			fputc(c,bt);
				}
			// 処理を占有しないように定期的にスリープ
			if(cnt++>50) {
				tslp_tsk(1);
				cnt=0;
			}
#endif
#ifdef BINARY

			char buf[256];
			sprintf(buf,"size %d",sizeof(x));
			msg_f(buf,3);

			char st = 0x33;
			fputc(st,bt); 
			fputc(st,bt);
			fputc(st,bt);
			fputc(st,bt);
			fwrite(&x,sizeof(x),1,bt);
			fflush(bt);

		//	ev3_speaker_play_tone(NOTE_E4,100);
			
#endif
    	}
	//}

	
}
	
// 次の要素の添え字を求める
int HBTtask::next(int index) {
  return (index + 1) % BUF_SIZE;
}

// キューを初期化する
void HBTtask::init_queue() {
  front = rear = 0;
}

// キューにデータを入れる
void HBTtask::enqueue(T_SENDBUF x) {

  if (next(rear) == front) {
     return;
  }
  SENDBUF[rear] = x;
  rear = next(rear);
}

// キューからデータを取り出す。データがないとINF(無効な値)を返す。
T_SENDBUF HBTtask::dequeue() {
  T_SENDBUF x;
  if (front == rear) {
  	x.light=-1;
    return x;
  }
  x = SENDBUF[front];
  front = next(front);
  return  x;
}

// キューが空かどうかを調べる。空なら１、空でなければ０を返す
int HBTtask::empty() {
  return  front == rear;
}

int HBTtask::getBTData()
{
	return buffer;
}
void HBTtask::resetBTData()
{
	buffer = -1;
}

int HBTtask::getRed()
{
	return r_num;
}
int HBTtask::getGreen()
{
	return g_num;
}
int HBTtask::getBlue()
{
	return b_num;
}
int HBTtask::getYellow()
{
	return y_num;
}
int HBTtask::getBlack()
{
	return k_num;
}
int HBTtask::getBonus()
{
	return bonus_num;
}