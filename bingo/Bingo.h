#ifndef _BINGO_H_
#define _BINGO_H_

#include "BlockStorage.h"
#include "Block.h"
#include "RunningBody.h"

class Bingo{
    public:
    Bingo();
    int get();
    int m = 0;
    int n = 0;
    int p[2];
    int r[2];
    int A = 0;
    int s = 0;
    bool c = false;
    int Search(int x,int y)[2];
    int X = 0;
    int Y = 0;
    int m[2] = {0,0};
    int a = 0;
    int n = blockstorage[x][y].getBlock().getColor();
    int k[2] = {0,0};
    int l[2] = {0,0};

    int Calculation(int x, int y, int m, int n);
    int Comparison(int x, int y)[2];
    int blockflag[10] = {0,0,0,0,0,0,0,0,0,0};
    int min = 99;
    int z = 0;
    int j = 0;

    protected:


};






#endif