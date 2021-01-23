#include "Stop.h"
#include "util.h"

bool Stop::run()
{


    mCount=mCount-1;
    if(mCount!=0){
        return false;
    }
    else{
        return true;
    }


}

void  Stop::setCount(int count)
{
    mCount=count;

    /*if(count == 1){
        mCount = 0;
        msg_f("white",3);
    }
    else if(count == 2){
        mCount = 5;
        msg_f("red",4);
    }
    else if(count == 3){
        mCount = 1000000;
        msg_f("blue",5);
    }*/
}