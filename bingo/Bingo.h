#ifndef _BINGO_H_
#define _BINGO_H_

#include "BlockStorage.h"
#include "BlockCircle.h"
#include "IntersectionCircle.h"
#include "BlackLine.h"
#include "Block.h"
#include "RunningBody.h"
#include "etroboc_ext.h"

class BlackLine;

class Bingo{
    public:
    int BSuffix;
    int runx;
    int runy;
    int numcard; //数字カードの数字
    Bingo();
    int get();
    void Search(int x,int y,int *ans);
    int Calculation(int x, int y, int m, int n);
    void Comparison(int x, int y);
    void Mapping(); //マッピングするメソッド
    void Dicision(); //ブロックの移動先決定メソッド
    int MovementOrder(); //ブロックの移動順メソッド

    BlockStorage *blockstorage[7][7];
    Block *block[10];
    int blockflag[10] = {0,0,0,0,0,0,0,0,0,0};
    RunningBody *rb = new RunningBody(0);

    protected:

};


#endif