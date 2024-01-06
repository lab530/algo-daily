#include <bits/stdc++.h>
using namespace std;
int nums[10][10], book[10][10];//迷宫及已走过的节点
int cnt = 0;//记录路径的条数
int N, M, T;//定义迷宫大小及障碍数量
int x, y, zx, zy;//定义起点坐标和终点坐标

void dfs(int x, int y, int step){// 深度优先搜索函数
    int dx, dy;
    int next[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};//定义四个方向
    if(x == zx && y == zy)//若达到终点，则更新路径数
    {
        cnt += 1;
        return;
    }
    for(int i=0;i<4;i++)
    {
        dx = x + next[i][0];
        dy = y + next[i][1];
        if(dx < 1 || dx > N || dy < 1 || dy > M)//防止出边界
        continue;
        if(nums[dx][dy] == 0 && book[dx][dy] == 0)
        {
            // cout<<"book[dx][dy]= "<<book[dx][dy]<<endl;
            book[dx][dy] = 1;
            // cout << i << " " << cnt << endl;
            // cout<<"nums[dx][dy]= "<<nums[dx][dy]<<endl;
            dfs(dx, dy, step+1);
            book[dx][dy] = 0;
        }
    }
    return;
}

int main(){
    cin >> N >> M >> T;
    cin >> x >> y >> zx >> zy;
    for(int i = 0; i < T; ++i)//设置障碍的位置
    {
        int n, m;
        cin >> n >> m;
        nums[n][m] = 1;
    }
    book[x][y] = 1;
    dfs(x,y,0);
    cout << cnt;

    return 0;
}