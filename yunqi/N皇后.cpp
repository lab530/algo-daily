#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
#include<stack>
#include<queue>
#include<climits>
using i64 = long long;
using namespace std;
const int MANX = 200005;

/*
1.运用一个数组去标记被使用过的列
2.找到对角线与下标的映射关系
3.按行搜索
*/
int n;
int arr[15];   // 输出序列
int line[15], neglect[30], restrain[30];   // 行，撇，捺
int ans;

void dfs(int cnt)   // cnt 表示行数
{
    if(cnt > n){
        ans++;
        if(ans <= 3){
            for(int i = 1; i <= n; ++i)
            {
                cout << arr[i] << ' ';
            }
            cout << endl;
        }
    }

    // 遍历列
    for(int i = 1; i <= n; ++i)
    {
       if(line[i] || neglect[i + cnt] || restrain[cnt - i + n]) continue;

       arr[cnt] = i;
       line[i] = neglect[i + cnt] = restrain[cnt - i + n] = 1;  // 标记已经使用过，neglect对角线<行列之和不变>， restrain对角线<行列之差不变， 防止负数加行数>
       dfs(cnt + 1);
       line[i] = neglect[i + cnt] = restrain[cnt - i + n] = 0;
    }
}

int main()
{
    cin >> n;
    dfs(1);
    cout << ans << endl;
    return 0;
}