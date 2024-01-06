#include<bits/stdc++.h>
using namespace std;
int n;//单词数 
string tr[30];//存储字符串 
int yc[30][30];//两个字母的最小重叠部分 
int vis[30];//判断单词使用频率. 
/*没过的一个样例，答案应该是15，问题出在slove函数没法解决x == 1, y == 1情况下的解答
1
envelope
e*/
int slove(int x , int y){//计算最短重合长度
    string a = tr[x];
    string b = tr[y];
    int l1 = a.size();
    int l2 = b.size();
    int nm = 0;
    if(a.find(b) != string::npos && l1 != l2){//代表包含子串关系
        return nm;
    }else{
        
        for(int j = 1; j <= min(l1,l2); j++){
            if(a.substr(l1 - j, j).find(b.substr(0,j)) != string::npos){
                nm = j;
                break;//找最短，找到就走，不带回头的
            }
        }
    }
    return nm;
}
char ch;//开头字母 
int ans = -1;//答案 
int an = 0;//每次搜到的当前最长串 
void dfs(int p){//p为尾部单词编号(p的后缀就是“龙”的后缀，因为p已经连接到”龙“后面了)
    bool jx = false; 
    for(int j = 1; j <= n; j++){
        if(vis[j] >= 2) continue;//使用了两次就跳过 
        if(yc[p][j] == 0 ) continue;//两单词之间没有重合部分就跳过 
        if(yc[p][j] == tr[p].size() || yc[p][j] == tr[j].size()) continue;//两者存在包含关系就跳过 
        an += tr[j].size() - yc[p][j];//两单词合并再减去最小重合部分 ,而an也是不断更新的，代表当前情况下的长度
        vis[j]++;//使用了一次
        jx = true;//标记一下当前已经成功匹配到一个可以连接的部分 
        dfs(j); //接上去
        an -= tr[j].size() - yc[p][j];//回溯，就要再减回去那一部分长度 
        vis[j]--;//回溯,使用-- ,代表单词使用次数--
    }
    if(jx == false){//jx==false说明不能再找到任何一个单词可以相连了 
        ans = max(ans,an);//更新ans 
    }
    return;
}
int main(){
    cin >> n;
    for(int i = 1;i<=n;i++)
        cin >> tr[i];
    cin >> ch; 
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            yc[i][j] = slove(i,j); 
        }
    }
     
    for(int i = 1; i <= n; i++){//从头到尾看一下有没有以指定开头字母为开头的单词 
        if(tr[i][0] == ch){//如果有，就以当前单词为基准进行搜索。 
            vis[i]++;//使用过一次 
            an = tr[i].size();//更新当前串长度 
            dfs(i);//接上
            vis[i] = 0;//消除影响 
        } 
    } 
    printf("%d",ans);
    return 0;
}