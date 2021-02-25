#ifndef INCLUDED_GLOBAL
#define INCLUDED_GLOBAL

static char sendchar;
static char sendchar2;
static int length;
static int fwd;
static int absangle;
static int turn;
static int flag;

char getSendchar2();
int setSendchar2(char a2);

int getLength();
int setLength(int le);

int getFwd();
int setFwd(int f);

int getAbsangle();
int setAbsangle(int abs);

int getFirst();
int setFirst(int fi);

int getLast();
int setLast(int la);

char getSendchar();
int setSendchar(char a);

int getFlag();
int setFlag(int flag);

#endif