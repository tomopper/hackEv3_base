#ifndef _BLOCK_CIRCLE_H_
#define _BLOCK_CIRCLE_H_

#include "BlockStorage.h"
class BlockCircle : public BlockStorage{
    public:
    BlockCircle();
    void setNo();
    int getNo();

    private:
    int no;
};

#endif