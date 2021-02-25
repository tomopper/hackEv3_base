#include "util.h"

char sendchar2 = 'G';
int length = 0;
int fwd = 0;
int absangle = 0;
int first = 0;
int last = 0;
int first2 = 0;
int last2 = 0;
int flag = 2;

char sendchar;

char getSendchar2()
{
    return sendchar2;
}

int setSendchar2(char a2)
{
    sendchar2 = a2;
    return 0;
}

int getLength()
{
    return length;
}

int setLength(int le = 0)
{
    length = le;
    return 0;
}

int getFwd()
{
    return fwd;
}

int setFwd(int f = 0)
{
    fwd = f;
    return 0;
}

int getAbsangle()
{
    //msg_f("getAbsangle",5);
    return absangle;
}

int setAbsangle(int abs = 0)
{
    absangle = abs;
    //msg_f("setAbsangle",6);
    return 0;
}

int getFirst()
{
    return first;
}

int setFirst(int fi = 0)
{
    first = fi;
    return 0;    
}

int getLast()
{
    return last;
}

int setLast(int la = 0)
{
    last = la;
    return 0;
}

char getSendchar()
{
    return sendchar;
}

int setSendchar(char a = 0)
{
    sendchar = a;
    return 0;
}

int getFlag()
{
    return flag;
}

int setFlag(int f)
{
    flag = f;
    return 0;
}
