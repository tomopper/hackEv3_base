#ifndef _BINGO_H_
#define _BINGO_H_

#include "BlockStorage.h"
#include "BlockCircle.h"
#include "IntersectionCircle.h"
#include "BlackLine.h"
#include "Block.h"
#include "RunningBody.h"

class BlackLine;

typedef struct _Coordinate
{
    int x;
    int y;
} coord;

class Bingo{
    public:
    Bingo();
    int get();
    int *Search(int x,int y);
    int Calculation(int x, int y, int m, int n);
    int *Comparison(int x, int y);
    BlockStorage *blockstorage[7][7];
    Block *block[10];
    int blockflag[10] = {0,0,0,0,0,0,0,0,0,0};

    coord a[2] ={{0,0},{0,0}};
    protected:

};






#endif