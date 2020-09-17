#ifndef _Block_STORAGE_CPP_
#define _BLOCK_STORAGE_CPP_

#include "BlockStorage.h"

BlockStorage::BlockStorage(int x, int y, int color){
    this->x = x;
    this->y = y;
    this->color = color;
    block = new Block[2];
}

void BlockStorage::setBlock(Block block){
    this->block[block_cnt] = block;
    if(block != null){
        block_cnt++;
        block->setBlockStorage(this);
    }else{
        block_cnt--;
        this->block[block_cnt] = new Block(-1, -1);
    }
}

void BlockStorage::setRunningBody(RunningBody runningbody){
    if(runningbody != null){
        runningbody->setBlockStorage(this);
    }
    this->runningbody = runningbody;
}

int BlockStorage::getX(){
    return x;
}

int BlockStorage::getY(){
    return y;
}

int BlockStorage::getNo(){
    return -1;
}

int BlockStorage::getColor(){
    return color;
}

Block BlockStorage::getBlock(){
    return block[0];
}

RunningBody BlockStorage::getRunningBody(){
    return runningbody;
}

#endif