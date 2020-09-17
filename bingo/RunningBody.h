#ifndef _RUNNING_BODY_H_
#define _RUNNING_BODY_H_

class RunningBody{
    private:
    int direction;
    BlockStorage BlockStorage;
    Block Block;

    public:
    RunningBody(int direction);
    void setBlockStorage(BlockStorage BlockStorage);
    void setBlock(Block block);
    void setDirection(int direction);
    int getX();
    int getY();
    int getDirection();
    Block getBlock();
};

#endif