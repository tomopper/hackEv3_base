#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "BlockStorage.h"

class BlockStorage;
class RunningBody;

class Block{
    private:
    int color;
    int no;
    BlockStorage *blockstorage;
    RunningBody *runningbody;

    public:
    Block(int color, int no);
    void setBlockStorage(BlockStorage *blockstorage);
    void setRunningBody(RunningBody *runningbody);
    void setColor(int color);
    void setNo(int no);
    int getColor();
    int getNo();
    int getX();
    int getY();
};

#endif