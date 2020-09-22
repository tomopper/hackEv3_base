#include "Bingo.h"

#include "util.h"

Bingo::Bingo(){

    msg_log("new Bingo construted!!");

} 

int Bingo::get(){

    int m = 0;
    int n = 0;
    int *p;
    int *r;
    int A = 0;
    int s = 0;
    bool c = false;

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
    block[1] = new Block(4, 1);
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
    

    for(int i=1; i<6; i=i+2)
    {
        for(int j=1; j<6; j=j+2)
        {
            if(blockstorage[i][j]->getBlock() != nullptr)
            {
                if(blockstorage[i][j]->getBlock()->getColor() != blockstorage[i][j]->getColor())
                {
                    m = i;
                    n = j;
                }else{
                    for(A = 0; A < 10; A++)
                    {
                        if(i == block[A]->getX() && j == block[A]->getY()){
                            blockflag[A] = 1;
                            break;
                            
                        }
                    }
                }
            }
        }
    }
    
    for(A = 0; A < 10; A++)
    {
        if(m == block[A]->getX() && n == block[A]->getY())
            break;
    }

    // 自己位置設定
    RunningBody *rb = new RunningBody(0);
    blockstorage[6][4]->setRunningBody(rb);
    
    //System.out.println("自己位置:(" + rb->getX() + "," + rb->getY() + ") 向き:" + rb->getDirection());
    //System.out.println("運ぶブロックの座標 :4,4");
    blockstorage[4][4]->setRunningBody(rb);
    blockstorage[6][4]->setRunningBody(nullptr);
    //System.out.println("自己位置:(" + rb->getX() + "," + rb->getY() + ") 向き:" + rb->getDirection());
    rb->setBlock(block[6]);
    /*
    if(rb->getBlock() != nullptr)
        System.out.println("持っているブロック：" + rb.getBlock());
    */
   
   
   //

     p = Comparison(4,4);

    static char buf[256];
    sprintf(buf,"p[0]=%d, p[1]=%d",p[0],p[1]);
           msg_log(buf);
    //終
 
    int p1=p[0];
    int p2=p[1];
    blockstorage[p[0]][p[1]]->setBlock(block[6]);
           msg_log("step 1");

   blockstorage[p[0]][p[1]]->setRunningBody(rb);
           msg_log("step 2");
    blockstorage[4][4]->setRunningBody(nullptr);
           msg_log("step 3");

    //System.out.println("運搬後");
    //System.out.println("自己位置:(" + rb->getX() + "," + rb->getY() + ") 向き:" + rb->getDirection());
    
    rb->setBlock(nullptr);

    /*
    if(rb->getBlock() == nullptr)
        System.out.println("ブロックを持っていない");
    */
    blockstorage[4][4]->setBlock(nullptr); //???X?u???????u???b?N???????i?{????????????j
    //System.out.println(p[0] + ","  + p[1]);
    blockflag[6] = 1;


    //BlockStorageにセットしてるblock消したいなあ

    //System.out.println("運ぶブロックの座標 :2,2");
    blockstorage[2][2]->setRunningBody(rb);

    printf("p[0] %d p[1] %d\n",p[0],p[1]);
               return 0;

//    blockstorage[p[0]][p[1]]->setRunningBody(nullptr);
    blockstorage[1][1]->setRunningBody(nullptr);
    //System.out.println("自己位置:(" + rb->getX() + "," + rb->getY() + ") 向き:" + rb->getDirection());
           return 0;
    rb->setBlock(block[2]);
    /*
    if(rb->getBlock() != nullptr)
        System.out.println("持っているブロック：" + rb->getBlock());
    */

  
    p = Comparison(2,2);
    blockstorage[p[0]][p[1]]->setBlock(block[2]);
    blockstorage[p[0]][p[1]]->setRunningBody(rb);
    blockstorage[2][2]->setRunningBody(nullptr);
    //System.out.println("運搬後");
    //System.out.println("自己位置:(" + rb->getX() + "," + rb->getY() + ") 向き:" + rb->getDirection());
    rb->setBlock(nullptr);
    /*
    if(rb->getBlock() == nullptr)
        System.out.println("ブロックを持っていない");
    */
    blockstorage[2][2]->setBlock(nullptr);
    //System.out.println(p[0] + ","  + p[1]);
    blockflag[2] = 1;
    
    //System.out.println("運ぶブロックの座標 :" + m + "," + n);
    blockstorage[m][n]->setRunningBody(rb);
    blockstorage[p[0]][p[1]]->setRunningBody(nullptr);
    //System.out.println("自己位置:(" + rb->getX() + "," + rb->getY() + ") 向き:" + rb->getDirection());
    p = Comparison(m,n);
    for(A = 0; A < 10; A++)
    {
        if(m == block[A]->getX() && n == block[A]->getY())
            break;
    }
    

    /*rb->setBlock(block[A]);
    if(rb->getBlock() != nullptr)
        System.out.println("持っているブロック：" + rb->getBlock());
    */
    //System.out.println(A);
    blockstorage[p[0]][p[1]]->setBlock(block[A]);
    blockstorage[p[0]][p[1]]->setRunningBody(rb);
    blockstorage[m][n]->setRunningBody(nullptr);
    //System.out.println("運搬後");
    //System.out.println("自己位置:(" + rb->getX() + "," + rb->getY() + ") 向き:" + rb->getDirection());
    rb->setBlock(nullptr);
    /*
    if(rb->getBlock() == nullptr)
        System.out.println("ブロックを持っていない");
    */
    blockstorage[m][n]->setBlock(nullptr);
    //System.out.println(p[0] + ","  + p[1]);
    blockflag[A] = 1;


    while(true)
    {
        //走行体のx,yから運ぶブロックを見つけてm,nに入れる
        r = Search(p[0],p[1]);
        c = true;
        //System.out.println("運ぶブロックの座標 :" + r[0] + "," + r[1]);
        if(blockstorage[r[0]][r[1]]->getBlock()->getColor() != 4)
        {
            p = Comparison(r[0],r[1]);
        }else{
            if(blockstorage[r[0]][r[1]]->getBlock()->getNo() != 0){
                s = blockstorage[r[0]][r[1]]->getBlock()->getNo();
            }else{
                //ブロックの数字がわかるところまで移動
                p[0] = 2;
                p[1] = 2;
                //System.out.println("今の場所 " + p[0] + "," + p[1]);
                s = 6;
                blockstorage[r[0]][r[1]]->getBlock()->setNo(s);
            }
            for(p[0] = 1; p[0] <= 5; p[0] = p[0]+2)
            {
                for(p[1] = 1; p[1] <= 5; p[1] = p[1]+2)
                {
                    if(s == blockstorage[p[0]][p[1]]->getNo())
                    {
                        c = false;
                        break;
                    }
                }
                if(c == false)
                {
                    c = true;
                    break;
                }
            }
        }
        for(A = 0; A < 10; A++)
        {
            if(r[0] == block[A]->getX() && r[1] == block[A]->getY())
                break;
        }
        blockstorage[r[0]][r[1]]->setRunningBody(rb);
        blockstorage[m][n]->setRunningBody(nullptr);
        //System.out.println("自己位置:(" + rb->getX() + "," + rb->getY() + ") 向き:" + rb->getDirection());
        rb->setBlock(block[A]);
        /*
        if(rb->getBlock() != nullptr)
            System.out.println("持っているブロック：" + rb->getBlock());
        */
        //System.out.println("ブロックの配列番号：" + A);
        blockstorage[p[0]][p[1]]->setBlock(block[A]);
        blockstorage[p[0]][p[1]]->setRunningBody(rb);
        blockstorage[m][n]->setRunningBody(nullptr);
        //System.out.println("運搬後");
        //System.out.println("自己位置:(" + rb->getX() + "," + rb->getY() + ") 向き:" + rb->getDirection());
        rb->setBlock(nullptr);
        /*
        if(rb->getBlock() == nullptr)
            System.out.println("ブロックを持っていない");
        */
        if(p[0] != r[0] || p[1] != r[1])
            blockstorage[r[0]][r[1]]->setBlock(nullptr);
        //System.out.println("サークルの座標：" + p[0] + ","  + p[1]);
        blockflag[A] = 1;
        for(int i = 0; i <= 9; i++)
        {
            if(blockflag[i] == 0){
                c = false;
            }
        }
        if(c == true){
            break;
        }
        m = r[0];
        n = r[1];
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

int *Bingo::Comparison(int x, int y)
{
    int X = 0;
    int Y = 0;
    int m[2];
    int a = 0;
    Block *bk = blockstorage[x][y]->getBlock();
    printf("Comparison bk %d %d\n",bk,bk->getColor());
    int n = blockstorage[x][y]->getBlock()->getColor();
    int k[2];
    int l[2];



    if(n != 4){
        for(int i = 0; i < 10; i++)
        {
            printf("color %d %d\n",n,block[i]->getColor());

            if(n == block[i]->getColor())
            {
                m[a] = i;
                printf("a=%d i=%d\n",a,i);
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

        printf("a=%d\n",a);

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
                X = blockstorage[k[0]][l[0]]->getNo();
                k[1] = l[0];
                block[m[0]]->setNo(X);
            }else{
                X = blockstorage[k[1]][l[1]]->getNo();
                k[0] = k[1];
                k[1] = l[1];
                block[m[1]]->setNo(X);
            }
        }else{
            if(block[m[0]]->getX() == x)
            {
                X = blockstorage[k[1]][l[1]]->getNo();
                k[0] = k[1];
                k[1] = l[1];
                block[m[0]]->setNo(X);
            }else{
                X = blockstorage[k[0]][l[0]]->getNo();
                k[1] = l[0];
                block[m[1]]->setNo(X);
            }
        }
    }
    return k;
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

int *Bingo::Search(int x,int y)
{
    int min = 99;
    int z = 0;
    int j = 0;
    int *k;

    for(int i = 0; i < 10; i++)
    {
        z = Calculation(x,y,block[i]->getX(),block[i]->getY());
        k = Comparison(block[i]->getX(),block[i]->getY());
        z = z + Calculation(block[i]->getX(),block[i]->getY(),k[0],k[1]);
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
    return k;
}

