#include "util.h"

static char sendchar2 = 'G';
static float length = 0;
static int fwd = 0;
static float absangle = 0;
static float first = 0;
static float last = 0;
static int flag = 4;

char sendchar;

char getSendchar2()
{
    return sendchar2;
}

void setSendchar2(char a2)
{
    sendchar2 = a2;
}

float getLength()
{
    return length;
}

void setLength(float le)
{
    length = le;
}

int getFwd()
{
    return fwd;
}

void setFwd(int f)
{
    fwd = f;
}

float getAbsangle()
{
    //msg_f("getAbsangle",5);
    return absangle;
}

void setAbsangle(float abs)
{
    absangle = abs;
    //msg_f("setAbsangle",6);
}

float getFirst()
{
    return first;
}

void setFirst(float fi)
{
    first = fi;
}

float getLast()
{
    return last;
}

void setLast(float la)
{
    last = la;
}

char getSendchar()
{
    msg_log("getChar");
    return sendchar;
}

void setSendchar(char a)
{
    msg_log("setChar");
    sendchar = a;
}

int getFlag()
{
    msg_log("getF");
    return flag;
}

void setFlag(int f)
{
    msg_log("setF");
   flag = f;
}
