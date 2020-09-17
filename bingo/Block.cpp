#ifndef _BLOCK_CPP_
#define _BLOCK_CPP_

#include "Block.h"

Block::Block(int color, int no){
    this->color = color;
    this->no = no;
}

void Block::setBlockStorage(BlockStorage blockstorage){
    this->blckstorage = blockstorage;
}

void Block::setRunningBody(RunningBody runningbody){
    this->runningbody = runnigbody;
}

void Block::setColor(int color){
    this->color = color;
}

void Block::setNo(int no){
    this->no = no;
}

int Block::getColor(){
    return color;
}

int Block::getNo(){
    return no;
}

int Block::getX(){
    return blockstorage->getX();
}

int Block::getY(){
    return blockstorage->getY();
}

#endif