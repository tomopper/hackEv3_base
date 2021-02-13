#include "util.h"

// 演習用のユーティリティ

static FILE *fp=nullptr;

// 初期処理用
void init_f(const char *str) {
  // フォントの設定と0行目の表示
  ev3_lcd_set_font(EV3_FONT_MEDIUM);
  ev3_lcd_draw_string(str, 0, 0);

 // printf("init_f");
  //fp = fopen("log.txt","w");
  
}

/**
 * 行単位で引数の文字列を表示
 * @param str 表示する文字列
 * @param line 20ドットごとの行番号（1から5）
 */
void msg_f(const char *str, int32_t line) {
  const int8_t line_height = 20;
  ev3_lcd_fill_rect(0, line * line_height, EV3_LCD_WIDTH, line_height, EV3_LCD_WHITE);
  ev3_lcd_draw_string(str, 0, line * line_height);
}

int log_max=10000;
int log_idx=0;
float msg_logbuf[10000][256];

void msg_log(const char *str)
{
  //syslog(LOG_NOTICE,str);
  //printf(str);
  //if(fp!=nullptr) fprintf(fp,str);
}
void msg_num(float x)
{
  int i;
  
  msg_logbuf[log_idx][0]=x;
  log_idx++;
  if(log_idx>=log_max) log_idx=0;

}
void msg_out()
{
  printf("log_out %f\n",log_idx);
  for(int i=0;i<log_idx;i++) {
    printf("%f\n",msg_logbuf[i][0]);
  }
  log_idx=0;
}