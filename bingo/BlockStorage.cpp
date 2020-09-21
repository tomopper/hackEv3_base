#include "BlockStorage.h"

BlockStorage::BlockStorage(int x, int y, int color){
    BlockStorage::x = x;
    BlockStorage::y = y;
    BlockStorage::color = color;
    block[0]=nullptr;
    block[1]=nullptr;
}

void BlockStorage::setBlock(Block *block){
    BlockStorage::block[block_cnt] = block;
    if(block != nullptr){
        block_cnt++;
        block->setBlockStorage(this);
    }else{
        block_cnt--;
        BlockStorage::block[block_cnt] = new Block(-1, -1);
    }
}

void BlockStorage::setRunningBody(RunningBody *runningbody){
    if(runningbody != nullptr){
        runningbody->setBlockStorage(this);
    }
    BlockStorage::runningbody = runningbody;
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

Block *BlockStorage::getBlock(){
    return block[0];
}

RunningBody *BlockStorage::getRunningBody(){
    return runningbody;
}
