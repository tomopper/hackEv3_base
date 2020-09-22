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
    int bx;
    int by;
    int cx;
    int cy;
    int flag;
} coord;
// bx,by:ブロックの初期位置,cx,cy:そのブロックを運ぶ場所の座標,ブロックを運んだか運んでいないかのフラグ

class Bingo{
    public:
    Bingo();
    int get();
    void Search(int x,int y,int *ans);
    int Calculation(int x, int y, int m, int n);
    void Comparison(int x, int y, int *ans);
    BlockStorage *blockstorage[7][7];
    Block *block[10];
    int blockflag[10] = {0,0,0,0,0,0,0,0,0,0};

    coord a[10] ={{0,0,0,0,0},
                  {0,0,0,0,0},
                  {0,0,0,0,0},
                  {0,0,0,0,0},
                  {0,0,0,0,0},
                  {0,0,0,0,0},
                  {0,0,0,0,0},
                  {0,0,0,0,0},
                  {0,0,0,0,0},
                  {0,0,0,0,0}};
    protected:

};


//マッピングメソッド
//移動先決定メソッド
//ブロックの移動順決定メソッド


#endif