#include "util.h"

static float absangle = 0;
static int first = 0;
static float last = 0;
static int flag = 4;
static char sendchar;
static int count = 0;

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

int getFirst()
{
    return first;
}

void setFirst(int fi)
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

int getCount()
{
    return count;
}

void setCount(int c)
{
    count = c;
}