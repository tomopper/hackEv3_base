#ifndef _RUNNING_BODY_CPP_
#define _RUNNING_BODY_CPP_

#include "RunningBody.h"

RunningBody::Runningbody(int direction){
    this->direction = direction;
}

void RunningBody::setBlockStorage(BlockStorage blockstorage){
    this->blockstorage = blockstorage;
}

void RunningBody::setBlock(Block block){
    if(block != null)
    {
        block->setRunningBody(this);
    }
    this->block = block;
}

void RunningBody::setDirection(int direction){
	this->direction = direction;
}

int RunningBody::getX(){
    return blockstorage->getX();
}
	
int RunningBody::getY(){
    return blockstorage->getY();
}
	
int RunningBody::getDirection(){
    return direction;
}
	
Block RunningBody::getBlock(){
    return block;
}

#endif