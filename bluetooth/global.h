#ifndef INCLUDED_GLOBAL
#define INCLUDED_GLOBAL

static char sendchar;
static char sendchar2;
static float length;
static int fwd;
static int absangle;
static int turn;
static int flag;

char getSendchar2();
int setSendchar2(char a2);

float getLength();
void setLength(float le);

int getFwd();
void setFwd(int f);

int getAbsangle();
void setAbsangle(int abs);

int getFirst();
void setFirst(int fi);

int getLast();
void setLast(int la);

char getSendchar();
void setSendchar(char a);

int getFlag();
void setFlag(int flag);

#endif