#include "BlockStorage.h"

#include "util.h"
BlockStorage::BlockStorage(int x, int y, int color){
    BlockStorage::x = x;
    BlockStorage::y = y;
    BlockStorage::color = color;
    block[0]=nullptr;
    block[1]=nullptr;
    block_cnt=0;
}

void BlockStorage::setBlock(Block *bk){
    block[block_cnt] = bk;
    if(bk != nullptr){
        block_cnt++;
        bk->setBlockStorage(this);
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

void BlockStorage::showBlock(){
    for(int i=0; i<2; i++){
        if(block[i] != nullptr){
            if(block[i]->getColor() != -1){
                printf("color:%d No:%d\t", block[i]->getColor(), block[i]->getNo());
            }
        }
    }
}