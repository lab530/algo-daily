#include<bits/stdc++.h>
using namespace std;
#define MAXN 6005//定义一个不可改变量 值为6005
int h[MAXN];//创建两个大小为6005大小的数组
int v[MAXN];
vector<int> son[MAXN];//创建一个动态数组，大小是6005，
//vector<int> 表示每个 son 数组元素都是一个整数向量，可以存储一组整数值
int f[MAXN][2];//创建一个二维数组大小是6005，并且包含三个位子，代表去不去
void dp(int x)//自定义函数dp，代表大概率用得到动态数组
{
 f[x][0]=0;//把输入值对应的数组的第一位定义为0，表示这个人不去的话带来的快乐值是0
 f[x][1]=h[x];//表示这个人去的话能给舞会提供多少快乐度
 for(int i=0;i<son[x].size();i++)//看看如果x的下属们快乐度的总数
 {
  int y=son[x][i];//把每一个职员的快乐度赋值给y
  dp(y);//看看这个职员有没有下属，有的话会损失多少快乐度
  f[x][0]+=max(f[y][0],f[y][1]);//因为已经全算完了，看看上司去和不去快乐度那个高，并累加
  //取最大值是因为上司来舞会的话也是可以增加开心度的
  f[x][1]+=f[y][0];//该数组的第二个元素用来储存累加表示他若去，职员就不去，快乐度加成为0
}
}
int main()
{
 int n;
 cin>>n;//代表大学里有n个职员
 for(int i=1;i<=n;i++) cin>>h[i];//存储每一个职员的快乐指数（职员包括上司）
 for(int i=1;i<=n-1;i++)//开始输入上司的关系
 {
  int x,y;
  cin>>x>>y;//代表y是x的直接上司
  son[y].push_back(x);//代表把x穿插到y对应的数组末尾，代表了从属关系，这样的话从属数量可能就不止一个了
  v[x]=1;//把v数组第x个元素定义为1，代表这个人有上司了
 }
 int root;//定义一个整型变量root
 for(int i=1;i<=n;i++)
 if(!v[i]) {root=i;break;}//这个用来找到校长
 dp(root);//从dp函数里调用root变量
 cout<<max(f[root][0],f[root][1])<<endl;//输出最大值，就是考虑要不要上司参加什么的
 return 0;
}