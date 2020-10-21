#ifndef _RUNNING_BODY_H_
#define _RUNNING_BODY_H_

#include "BlockStorage.h"
#include "Block.h"

class BlockStorage;
class Block;
class RunningBody{
    private:
    int direction;
    BlockStorage *blockstorage;
    Block *block;

    public:
    RunningBody(int direction);
    void setBlockStorage(BlockStorage *blockstorage);
    void setBlock(Block *block);
    void setDirection(int direction);
    int getX();
    int getY();
    int getDirection();
    Block *getBlock();
};

#endif