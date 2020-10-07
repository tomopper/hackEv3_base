#include "Bingo.h"

#include "util.h"

Bingo::Bingo(){

    msg_log("new Bingo construted!!");

} 

int Bingo::get(){

    int p[2];
    int r[2];
    int s = 0;
    bool c = false;

    Mapping();
    Dicision();
    for(int i = 0; i < 10; i++){
        printf("block[i].dx=%d,block[i].dy=%d\n", block[i]->getdX(), block[i]->getdY());
    }

    //決め打ち用のちがうのに入ってるブロックの添え字
    for(BSuffix = 0; BSuffix < 10; BSuffix++)
    {
        if(runx == block[BSuffix]->getX() &&runy == block[BSuffix]->getY())
            break;
    }

 
		//デバック
		/*
		
		for(int i = 0; i < 7; i++)
		{
			for(int j = 0; j < 7; j++)
			{
				if(blockstorage[i][j] == nullptr)
				{
					System.out.print("\t");
				}else{
					blockstorage[i][j]->showMap();
				}
			}
			System.out.print("\n");
		}
		*/
    
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
    int n= blockstorage[x][y]->getBlock()->getColor();
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
        //System.out.println("m[0] " + m[0] + ", m[1] " + m[1]);
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

        //System.out.println("k[0] =" + k[0] + ",l[0] =" + l[0] + ",k[1] =" + k[1] + ",l[1] =" + l[1]);
       
     
        X = Calculation(block[m[0]]->getX(), block[m[0]]->getY(), blockstorage[k[0]][l[0]]->getX(), blockstorage[k[0]][l[0]]->getY());
        Y = Calculation(block[m[1]]->getX(), block[m[1]]->getY(), blockstorage[k[1]][l[1]]->getX(), blockstorage[k[1]][l[1]]->getY());
        int b = X + Y;
        X = Calculation(block[m[0]]->getX(), block[m[0]]->getY(), blockstorage[k[1]][l[1]]->getX(), blockstorage[k[1]][l[1]]->getY());
        Y = Calculation(block[m[1]]->getX(), block[m[1]]->getY(), blockstorage[k[0]][l[0]]->getX(), blockstorage[k[0]][l[0]]->getY());
        int c = X + Y;
        //System.out.println("b " + b + ", c " + c);

        if(b < c)
        {
            if(block[m[0]]->getX() == x)
            {
                //System.out.println(blockstorage[1][1]->getNo());
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

void Bingo::Search(int x,int y, int *ans)
{
    int min = 99;
    int z = 0;
    int j = 0;
    int *k = ans;
    int k2[2];
    
    printf("Search %d %d \n",x,y);
    for(int i = 0; i < 10; i++)
    {
        z = Calculation(x,y,block[i]->getX(),block[i]->getY());
        printf("z=%d\n", z);
        Comparison(block[i]->getX(),block[i]->getY());
        z = z + Calculation(block[i]->getX(),block[i]->getY(),k2[0],k2[1]);
        if(min > z && blockflag[i] == 0)
        {
            min = z;
            j = i;
            z = 0;
        }
    }

    k[0] = block[j]->getX();
    k[1] = block[j]->getY();
    //System.out.println("次のブロックの配列番号：" + j);
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
    block[0] = new Block(0, 0);
    block[1] = new Block(4, numcard);
    block[2] = new Block(2, 0);
    block[3] = new Block(1, 0);
    block[4] = new Block(3, 0);
    block[5] = new Block(1, 0);
    block[6] = new Block(3, 0);
    block[7] = new Block(2, 0);
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
                            blockflag[BSuffix] = 1;
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
    for(int i = 0; i < 4; i++){
        for(BSuffix = 0; BSuffix < 10; BSuffix++){
            if(block[BSuffix]->getColor() == i){
                printf("BSuffix=%d\n", BSuffix);
                printf("i=%d\n", i);
                break;
            }
        }
        Comparison(block[BSuffix]->getX(),block[BSuffix]->getY());
    }
    for(int i = 0; i < 2; i++){
        for(BSuffix = 0; BSuffix < 10; BSuffix++){
            if(block[BSuffix]->getColor() == 4){
                printf("BSuffix=%d\n", BSuffix);
                printf("i=%d\n", i);
                break;
            }
        }
        if(block[BSuffix]->getX() == 6 && block[BSuffix]->getY() == 6){
            block[BSuffix]->setdX_Y(2,2);
        }else{
            int k;
            int j;
            for(k = 1; k < 6; k = k+2){
                bool c = true;
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
        }
    }
     printf("BSuffix=%d\n", BSuffix);
}

void Bingo::MovementOrder()
{
    
} 