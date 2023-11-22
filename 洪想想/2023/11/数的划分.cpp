#include<bits/stdc++.h>
using namespace std;
int n,k,cnt;
void dfs(int last,int sum,int cur){
    if(cur==k){//看分成的份数是否符合条件
        if(sum==n) cnt++;//和为输入的那个数，累加方法数量
        return;//回溯
    }
    for(int i=last;sum+i*(k-cur)<=n;i++){//剪枝，只用枚举到sum+i*(k-cur)<=n为止
    //k-cur是求出还能分几份
    //把sum+(k-cur)作为分界线，是因为当到了这一步的时候，代表后面几位数全是一样的了
    //再往后取值的话无非是重复，就比如4，分到22就顶天了，因为再往后就是13，但是31前面搜索过了，所有跳过，剩下的不走了
        dfs(i,sum+i,cur+1);//第一种方法就是列举k个1，然后再回溯
    }
    return;
}
int main(){
    cin>>n>>k;//输入数字和要分成的份数
    dfs(1,0,0);//深搜
    cout<<cnt;
}