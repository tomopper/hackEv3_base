#include "RunningBody.h"

RunningBody::RunningBody(int direction){
    RunningBody::direction = direction;
}

void RunningBody::setBlockStorage(BlockStorage *blockstorage){
    RunningBody::blockstorage = blockstorage;
}

void RunningBody::setBlock(Block *block){
    if(block != nullptr)
    {
        block->setRunningBody(this);
    }
    RunningBody::block = block;
}

void RunningBody::setDirection(int direction){
	RunningBody::direction = direction;
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
	
Block *RunningBody::getBlock(){
    return block;
}
