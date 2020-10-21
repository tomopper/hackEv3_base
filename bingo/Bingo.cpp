#include "Bingo.h"

#include "util.h"

Bingo::Bingo(){

    msg_log("new Bingo construted!!");
    Mapping();
    Dicision();

    //決め打ち用のちがうのに入ってるブロックの添え字
    for(BSuffix = 0; BSuffix < 10; BSuffix++)
    {
        if(runx == block[BSuffix]->getX() && runy == block[BSuffix]->getY())
            break;
    }

} 

int Bingo::get(){

    int s = 0;
    int i = 0;
    
    //数字付きブロックを(2,2)に運んだ時の処理
    if(BSuffix == 9 && block[BSuffix]->getdX() == block[BSuffix]->getX() && block[BSuffix]->getdY() == block[BSuffix]->getY()){
        msg_log("数字付きブロック!!!");
        for(i=1; i<7; i=i+2){
            for(int j=1; j<7; j=j+2){
                //ETROBOC_COURSE_INFO_BLOCK_NUMBER
                if(blockstorage[i][j]->getNo() == 6){
                    block[BSuffix]->setNo(6);
                    block[BSuffix]->setdX_Y(i, j);
                    blockstorage[rb->getX()][rb->getY()]->setRunningBody(nullptr);
                    blockstorage[block[BSuffix]->getX()][block[BSuffix]->getY()]->setBlock(nullptr);
                    blockstorage[block[BSuffix]->getdX()][block[BSuffix]->getdY()]->setBlock(block[BSuffix]);
                    blockstorage[block[BSuffix]->getdX()][block[BSuffix]->getdY()]->setRunningBody(rb);
                }
            }
        }
    }else{
        i = MovementOrder();
        printf("運ぶブロックの添え字:%d\n", i);
    }
    
    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            if(blockstorage[i][j]->getBlock() == nullptr || blockstorage[i][j]->getBlock()->getColor() == -1)
            {
                printf("\t");
            }else{
                blockstorage[i][j]->showBlock();
            }
        }
        printf("\n");
    }

    return true;
}

void Bingo::Comparison(int x, int y)
{
    int X = 0;
    int Y = 0;
    int k[2];
    int m[2];
    int a = 0;
    int n = blockstorage[x][y]->getBlock()->getColor();
    int l[2] = {0,0};

    if(n != 4){
        for(int i = 0; i < 10; i++)
        {
            if(n == block[i]->getColor())
            {
                m[a] = i;
                a++;
            }
        }
        a = 0;
        for(int i = 1; i < 7; i = i+2)
        {
            for(int j = 1; j < 7; j = j+2)
            {
                if(n == blockstorage[i][j]->getColor())
                {

                    k[a] = i;
                    l[a] = j;
                    a++;
                }
            }
        }
     
        X = Calculation(block[m[0]]->getX(), block[m[0]]->getY(), blockstorage[k[0]][l[0]]->getX(), blockstorage[k[0]][l[0]]->getY());
        Y = Calculation(block[m[1]]->getX(), block[m[1]]->getY(), blockstorage[k[1]][l[1]]->getX(), blockstorage[k[1]][l[1]]->getY());
        int b = X + Y;
        X = Calculation(block[m[0]]->getX(), block[m[0]]->getY(), blockstorage[k[1]][l[1]]->getX(), blockstorage[k[1]][l[1]]->getY());
        Y = Calculation(block[m[1]]->getX(), block[m[1]]->getY(), blockstorage[k[0]][l[0]]->getX(), blockstorage[k[0]][l[0]]->getY());
        int c = X + Y;

        if(b < c)
        {
            if(block[m[0]]->getX() == x)
            {
                block[m[0]]->setdX_Y(k[0],l[0]);
                block[m[1]]->setdX_Y(k[1],l[1]);
                block[m[0]]->setNo(blockstorage[k[0]][l[0]]->getNo());
                block[m[1]]->setNo(blockstorage[k[1]][l[1]]->getNo());
            }else{
                X = blockstorage[k[1]][l[1]]->getNo();
                block[m[0]]->setdX_Y(k[1],l[1]);
                block[m[1]]->setdX_Y(k[0],l[0]);
                block[m[1]]->setNo(X);
            }
        }else{
            if(block[m[0]]->getX() == x)
            {
                block[m[0]]->setdX_Y(k[1],l[1]);
                block[m[1]]->setdX_Y(k[0],l[0]);
                block[m[0]]->setNo(blockstorage[k[1]][l[1]]->getNo());
                block[m[1]]->setNo(blockstorage[k[0]][l[0]]->getNo());
            }else{
                block[m[0]]->setdX_Y(k[0],l[0]);
                block[m[1]]->setdX_Y(k[1],l[1]);
                block[m[0]]->setNo(blockstorage[k[0]][l[0]]->getNo());
                block[m[1]]->setNo(blockstorage[k[1]][l[1]]->getNo());
            }
        }
    }
}
	
int Bingo::Calculation(int x, int y, int m, int n)
{
    if(x > m)
    {
        x = x - m;
    }else{
        x = m - x;
    }
    
    if(y > n)
    {
        y = y - n;
    }else{
        y = n - y;
    }
    
    x = x + y;
    
    return x;
}

void Bingo::Mapping()
{
    numcard = 1;
   //黒線
    for(int i = 1; i <= 5; i = i+2){
        for(int j = 0; j <= 6; j = j+2){
            blockstorage[i][j] = new BlackLine(i,j,4);
        }
    }
    for(int i = 0; i <= 6; i = i+2){
        for(int j = 0; j <= 5; j = j+2){
            blockstorage[i][j] = new BlackLine(i,j,4);
        }
    }
    //青色交点サークル
    for(int i = 0; i <= 2; i = i+2){
        for(int j = 4; j <= 6; j = j+2){
            blockstorage[i][j] = new BlackLine(i,j,0);
        }
    }
    //赤色交点サークル
    for(int i = 0; i <= 2; i = i+2){
        for(int j = 0; j <= 2; j = j+2){
            blockstorage[i][j] = new IntersectionCircle(i,j,1);
        }
    }
    
    //緑色交点サークル
    for(int i = 4; i <= 6; i = i+2){
        for(int j = 4; j <= 6; j = j+2){
            blockstorage[i][j] = new IntersectionCircle(i,j,2);
        }
    }
    
    //黄色交点サークル
    for(int i = 4; i <= 6; i = i+2){
        for(int j = 0; j <= 2; j = j+2){
            blockstorage[i][j] = new IntersectionCircle(i,j,3);
        }
    }


    blockstorage[3][3] = new BlockStorage(3, 3, 5);
    //ブロックサークル
    blockstorage[1][1] = new BlockCircle(1,1,3,1);
    blockstorage[1][3] = new BlockCircle(1,3,2,2);
    blockstorage[1][5] = new BlockCircle(1,5,1,3);
    blockstorage[3][1] = new BlockCircle(3,1,0,4);
    blockstorage[3][5] = new BlockCircle(3,5,3,5);
    blockstorage[5][1] = new BlockCircle(5,1,2,6);
    blockstorage[5][3] = new BlockCircle(5,3,1,7);
    blockstorage[5][5] = new BlockCircle(5,5,0,8);
    
    //ブロック
    block[0] = new Block(3, 0);
    block[1] = new Block(1, 0);
    block[2] = new Block(4, numcard);
    block[3] = new Block(2, 0);
    block[4] = new Block(2, 0);
    block[5] = new Block(0, 0);
    block[6] = new Block(3, 0);
    block[7] = new Block(1, 0);
    block[8] = new Block(0, 0);
    block[9] = new Block(4, 0);

    // 置き場とブロックの結合
    blockstorage[0][0]->setBlock(block[0]);
    blockstorage[0][4]->setBlock(block[1]);
    blockstorage[2][2]->setBlock(block[2]);
    blockstorage[2][6]->setBlock(block[3]);
    blockstorage[3][5]->setBlock(block[4]);
    blockstorage[4][0]->setBlock(block[5]);
    blockstorage[4][4]->setBlock(block[6]);
    blockstorage[5][3]->setBlock(block[7]);
    blockstorage[6][2]->setBlock(block[8]);
    blockstorage[6][6]->setBlock(block[9]);
    
    //間違ったサークルに入っているブロックの座標(m,n) 同じ色のサークルに入っているブロックのflagに1を立てる
    for(int i=1; i<6; i=i+2)
    {
        for(int j=1; j<6; j=j+2)
        {
            if(blockstorage[i][j]->getBlock() != nullptr)
            {
                if(blockstorage[i][j]->getBlock()->getColor() != blockstorage[i][j]->getColor())
                {
                    runx= i;
                    runy= j;
                }else{
                    for(BSuffix = 0; BSuffix < 10; BSuffix++)
                    {
                        if(i == block[BSuffix]->getX() && j == block[BSuffix]->getY()){
                            block[BSuffix]->setFlag(1);
                            break;
                        }
                    }
                }
            }
        }
    }
}

void Bingo::Dicision()
{
    int k;
    int j;
    bool c = true;

    for(int i = 0; i < 4; i++){
        for(BSuffix = 0; BSuffix < 10; BSuffix++){
            if(block[BSuffix]->getColor() == i){
                break;
            }
        }
        Comparison(block[BSuffix]->getX(),block[BSuffix]->getY());
    }
    BSuffix = 0;
    for(int i = 0; i < 2; i++){
        for(; BSuffix < 10; BSuffix++){
            if(block[BSuffix]->getColor() == 4){
                break;
            }
        }
        if(block[BSuffix]->getX() == 6 && block[BSuffix]->getY() == 6){
            block[BSuffix]->setdX_Y(2,2);
            BSuffix++;
        }else{
            for(k = 1; k < 6; k = k+2){
                for(j = 1; j < 6; j = j+2){
                    if(blockstorage[k][j]->getNo() == block[BSuffix]->getNo()){
                        c = false;
                        break;
                    }
                }
                if(c == false){
                    break;
                }
            }
            block[BSuffix]->setdX_Y(k,j);
            BSuffix++;
        }
    }
}

int Bingo::MovementOrder()
{
    int i=0;
    int dis=0;
    int dis_min=99;
    

    for(i=0; i<10; i++)
    {
        if(blockstorage[4][4]->getBlock() == block[i] && block[i]->getFlag() == 0)
        {
            blockstorage[block[i]->getdX()][block[i]->getdY()]->setBlock(block[i]);
            blockstorage[4][4]->setBlock(nullptr);
            block[i]->setFlag(1);
            return i;
        }
    }
    for(i=0; i<10; i++)
    {
        if(blockstorage[2][2]->getBlock() == block[i] && block[i]->getFlag() == 0)
        {
            blockstorage[block[i]->getdX()][block[i]->getdY()]->setBlock(block[i]);
            blockstorage[2][2]->setBlock(nullptr);
            block[i]->setFlag(1);
            return i;
        }
    }
    if(block[BSuffix]->getFlag() == 0)
    {
        blockstorage[block[BSuffix]->getdX()][block[BSuffix]->getdY()]->setBlock(block[BSuffix]);
        blockstorage[block[BSuffix]->getdX()][block[BSuffix]->getdY()]->setRunningBody(rb);
        blockstorage[runx][runy]->setBlock(nullptr);
        block[BSuffix]->setFlag(1);
        i = BSuffix;
        return i;
    }

    for(i=0; i<10; i++)
    {
        if(block[i]->getFlag() == 0)
        {
            dis = Calculation(rb->getX(), rb->getY(), block[i]->getX(), block[i]->getY());
            dis = dis + Calculation(block[i]->getX(), block[i]->getY(), block[i]->getdX(), block[i]->getdY());

            if(dis < dis_min)
            {
                dis_min = dis;
                BSuffix = i;
                dis = 0;
            }
        }
    }

    blockstorage[rb->getX()][rb->getY()]->setRunningBody(nullptr);
    blockstorage[block[BSuffix]->getX()][block[BSuffix]->getY()]->setBlock(nullptr);
    blockstorage[block[BSuffix]->getdX()][block[BSuffix]->getdY()]->setBlock(block[BSuffix]);
    blockstorage[block[BSuffix]->getdX()][block[BSuffix]->getdY()]->setRunningBody(rb);
    block[BSuffix]->setFlag(1);
    i = BSuffix;

    return i;
} 