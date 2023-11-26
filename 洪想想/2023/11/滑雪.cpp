#include<bits/stdc++.h>
using namespace std;
int ku[105][105];//存入数据值
int fw[105][105];//用于计算每一个点的最大递减队列长度
int r,c;//定义两个输入
int kkk = 0;//定义最大递减队列长度

//判断出要执行处理的坐标是否在矩阵内
int pd(int i,int j){
    if(i < 1 || j < 1){
        return 0;
    }else if(i > r || j > c){
        return 0;
    }
    return 1;
}

//经过检验，问题就出在这个自定义函数中，但凡改了任意一个k的值，答案就会变
int hmq(int i,int j,int mix){
    //int t=1;
    int k1 = 0,k2 = 0,k3 = 0,k4 = 0;
    //分别表示目前点往左，往右，往上，往下的最大递减队列长度
    //cout<<i<<" "<<j<<endl;
    //cout<<ku[i][j]<<endl;//ku数组里全是0，牛逼
    if(fw[i][j] != 0){
        //剪枝，判断这个点是否已经被计算过了，如果已经被计算过，就直接取已经算好的结果，记忆
        //cout<<1<<endl;//这个if也是根本没有进去的，和pd拜托了关系，所以问题在ku[i][j]
        return fw[i][j];
    }

    if((ku[i][j] > ku[i + 1][j]) && pd(i + 1,j)){//判断上方的数值
        k1 = hmq(i+1,j,mix);
    }

    if((ku[i][j] > ku[i - 1][j]) && pd(i - 1,j)){//判断下方的数值
        k2 = hmq(i-1,j,mix);
    }

    if((ku[i][j] > ku[i][j + 1]) && pd(i,j + 1)){//判断右方的数值
        k3 = hmq(i,j+1,mix);
    }

    if((ku[i][j] > ku[i][j - 1] && pd(i,j - 1))){//判断左方的数值
        //cout<<1<<endl;//根本没进入这个if
        k4 = hmq(i,j-1,mix);
    }
    //cout<<k1<<endl<<k2<<endl<<k3<<endl<<k4<<endl<<endl;//问题出在这个自定义函数身上,因为输出全是0
    fw[i][j]= max( k1,max( k2,max( k3, k4))) +1;//加 1 是因为要算上这个点本身的队列长度


//首先，通过黄梦琪（——）自己调用自己，可以知道。。。可能有的情况就是，黄梦琪（）调用自己后，
//把某些点给赋值了，但是却没赋值最大可能值，然后在后面的循环里，就直接跳过了这个点
    return fw[i][j];
}


int f(int i,int j,int mix){

    //cout<<1<<endl;//确实应该是已经全跑完了，代表循环次数应该是没有问题的，问题出在自定义函数的计算逻辑
    
    /*if(fw[i][j] != 0){
        //不为0，代表该点的值之前被算过了
        
        mix += fw[i][j];
        if(kkk < mix){
            kkk = mix; 
        }
        return mix;
    }*/
    //在2.0修改后，已经在进入函数前就把这样的点拦截了
    //当前要探索的点还没被算出来
    int a = 0,b = 0,m = 0,d = 0;

    if(pd(i+1,j) && ku[i][j] > ku[i + 1][j]){//判断上方的数值
        a = hmq(i+1,j,mix);
    }

    if(pd(i-1,j) && ku[i][j] > ku[i - 1][j]){//判断下方的数值
        b = hmq(i-1,j,mix);
    }

    if(pd(i,j+1) && ku[i][j] > ku[i][j + 1]){//判断右方的数值
        m = hmq(i,j+1,mix);
    }

    if(pd(i,j-1) && ku[i][j] > ku[i][j - 1]){//判断左方的数值
        d = hmq(i,j-1,mix);
    }
    //cout<<a<<endl<<b<<endl<<m<<endl<<d<<endl<<endl;//里面的值没有一个大于等于2的，很不合理，主要应该去看看 黄梦琪（）自定义函数
    fw[i][j]= 1 + max(a,max(b,max(m,d)));//存入每个点的最大可能值
    mix += fw[i][j]  ;

    if(kkk < mix){//取最大值
        kkk = mix; 
    }
    return mix;//返回值是当前最大可能值
}



int main(){
    
    cin >> r >> c ;
    //cout<<pd(1,1)<<endl;//这样的结果居然会返回 0 ，所以问题应该是出在pd函数，现在对pd函数进行检验
    //pd函数修改完后输出值依旧不对，检查一下输入
    for(int i = 1;i <= r; i++){
        for(int j = 1;j <= c; j++){
            cin >> ku[i][j];
        }//把值存入数组里面，输入没有问题
    }
    /*for(int i = 1;i <= r; i++){
        for(int j = 1;j <= c; j++){
            cout << ku[i][j]<<" ";
        }//把值存入数组里面，输入没有问题
        cout << endl;
    }*/

    for(int i = 1;i <= r; ++i){
        //cout << 1<<endl;//确实跑完了所以的点
        for(int j = 1;j <= c; ++j){
            //再次遍历一次列表
            if(fw[i][j] == 0){//代表当前点还没有被计算过
                //计算
                f(i,j,0);
            }
            else{
                //cout<<1<<endl;//执行次数多次，代表这个循环是有被使用的
                //cout<<fw[i][j]<<endl;
                //清一色的 1 ，代表。。。前边的计算中，没有算出来比 1 长的最长递减数列长度
                kkk=max(kkk,fw[i][j]);
            }      
        }
    }

    cout << kkk;
    //样例输出为26，比正确答案大一，所以应该是累加时出现错误了
    //检测了一下，好像变成了输出数组里最大值的程序了，很抽象
    //因为比较的时候把ku数组当成fw数组来用了，giao
    return 0;
}