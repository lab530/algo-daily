#include<bits/stdc++.h>
using namespace std;
int a[5][5], ans = 0, mix = 20;//mix代表能成功的次数
void dd(int x,int y){//处理按一次灯 
    a[x][y] = 1 - a[x][y];
    a[x+1][y] = 1 - a[x+1][y];
    a[x][y+1] = 1 - a[x][y+1];
    a[x-1][y] = 1 - a[x-1][y];
    a[x][y-1] = 1 - a[x][y-1];
}
void dfs(int k) {
    if(k > mix) {//就是操作次数超过了目前的最大次数
        return;
    }
    int s = 0;
    for(int i = 1;i <= 3; ++i){
        for(int j = 1;j <= 3; ++j){
            s+=a[i][j]; 
        }    
    }//计算目前九宫格里面亮着的灯的数量  
    if(s == 9){//九栈灯全亮着
        ans = k - 1;//取操作次数，因为算操作了但是其实还没操作，所以真正操作次数还要减一
        if(ans < mix){//判断，存取最小的操作次数
            mix = ans;
        }
    }
    for(int i = 1;i <= 3; ++i){
        for(int j = 1; j <= 3; ++j){//处理这个位置的灯一次
        dd( i, j);
        dfs( k + 1);//深搜,表示直接再操作一次看看怎么样
        dd( i, j);//还原处理，以此完成回溯
        }
    }
    return;
}    
int main(){
for(int i = 1;i <= 3; ++i){
    for(int j = 1;j <= 3; ++j){
        cin >> a[i][j];//存入九宫格里的数据
    }    
} 
dfs(1);//调动深搜
cout << mix;//输出 
return 0;
}