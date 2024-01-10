#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,l,sum,ans;
int fa[1005];
struct Edge{
    int u,v,w;
}edge[10005];

bool cmp(Edge a, Edge b){
    return a.w < b.w;
}

int find(int x)
{
    return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}
int main()
{
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1; i <= m; i++){
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }
    sort(edge + 1 , edge + m + 1, cmp);    //按代价升序排列 
    for(int i = 1; i <= m; i++)
    {
        int fx = find(edge[i].u), fy = find(edge[i].v);
        if(fx != fy)        //如果这两个点不在同一棵树中 
        {
            fa[fx] = fy;
            sum++;        //连一条边，让它们合并成为一棵树 
            ans += edge[i].w;        //加上合并的代价 
        }
        if(sum == n - k)        //已经连好了k棵树 
        {
            cout << ans;
            return 0;
        }
    }
    cout << "No Answer";    //不可能连好 
    return 0;
}