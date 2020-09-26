#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "BlockStorage.h"

class BlockStorage;
class RunningBody;

class Block{
    private:
    int color;
    int no;
    int dx;
    int dy;// ブロックの移動先の座標
    int flag;//ブロックを運んだか運んでいないか
    BlockStorage *blockstorage;
    RunningBody *runningbody;

    public:
    Block(int color, int no);
    void setBlockStorage(BlockStorage *blockstorage);
    void setRunningBody(RunningBody *runningbody);
    void setColor(int color);
    void setNo(int no);
    void setdX_Y(int x,int y);
    void setFlag(int flag);
    int getColor();
    int getNo();
    int getX();
    int getY();
    int getdX();
    int getdY();
    int getFlag();
};

#endif