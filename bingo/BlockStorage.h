#ifndef _BLOCK_STORAGE_H_
#define _BLOCK_STORAGE_H_

#include "BlockCircle.h"
#include "IntersectionCircle.h"
#include "BlackLine.h"

class BlockStorage{
    private:
    int x;
    int y;
    int color;
    Block[] block;
    int block_cnt;
    RunningBody runningbody;

    public:
    BlockStorage(int x, int y, int color);
    void setBlock();
    void setRunningBody();
    int getX();
    int gerY();
    int getNo();
    int getColor();
    Block getBlock();
    RunningBody getRunningBody();
    void showMap();
    void showBlock();
};