#ifndef _BLOCK_CIRCLE_H_
#define _BLOCK_CIRCLE_H_

#include "BlockStorage.h"
class BlockCircle : public BlockStorage{
    public:
    BlockCircle(int x, int y, int color, int no);
    void setNo(int no);
    int getNo();

    private:
    int no;
};

#endif