#include "util.h"

char sendchar2 = 'G';
float length = 0;
int fwd = 0;
int absangle = 0;
int first = 0;
int last = 0;
int first2 = 0;
int last2 = 0;
int flag = 0;

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

int getAbsangle()
{
    //msg_f("getAbsangle",5);
    return absangle;
}

void setAbsangle(int abs)
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

int getLast()
{
    return last;
}

void setLast(int la)
{
    last = la;
}

char getSendchar()
{
    return sendchar;
}

void setSendchar(char a)
{
    sendchar = a;
}

int getFlag()
{
    return flag;
}

void setFlag(int f)
{
    flag = f;
}
