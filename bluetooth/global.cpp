#include "util.h"

static float absangle = 0;
static float first = 0;
static float last = 0;
static int flag = 4;
static char sendchar;

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
    //msg_log("getChar");
    return sendchar;
}

void setSendchar(char a)
{
    //msg_log("setChar");
    sendchar = a;
}

int getFlag()
{
    //msg_log("getF");
    return flag;
}

void setFlag(int f)
{
    //msg_log("setF");
   flag = f;
}
