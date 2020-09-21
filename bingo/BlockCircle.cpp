#include "BlockCircle.h"

BlockCircle::BlockCircle(int x, int y, int color, int no)
:BlockStorage(x, y, color)
{
   BlockCircle::no = no;
}


void BlockCircle::setNo(int no){
    BlockCircle::no = no;
}

int BlockCircle::getNo(){
    return no;
}
