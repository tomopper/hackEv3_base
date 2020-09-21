#ifndef _BLOCK_STORAGE_H_
#define _BLOCK_STORAGE_H_

//#include "BlockCircle.h"
//#include "IntersectionCircle.h"
//#include "BlackLine.h"

#include "Block.h"
#include "RunningBody.h"

class Block;
class RunningBody;

class BlockStorage{
    private:
    int x;
    int y;
    int color;
    Block *block[2];
    int block_cnt;
    RunningBody *runningbody;

    public:
    BlockStorage(int x, int y, int color);
    void setBlock(Block *block);
    void setRunningBody(RunningBody *runningbody);
    int getX();
    int getY();
    int getNo();
    int getColor();
    Block *getBlock();
    RunningBody *getRunningBody();
};

#endif