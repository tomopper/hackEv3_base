#ifndef _BLOCK_CIRCLE_CPP_
#define _BLOCK_CIRCLE_CPP_

#include "BlockCircle.h"

BlockCircle::BlockCircle(int x, int y, int color, int no)
:BlockStorage(x, y, color)
{
    this->no = no;
}


void BlockCircle::setNo(int no){
    this->no = no;
}

void BlockCircle::getNo(){
    return no;
}

#endif