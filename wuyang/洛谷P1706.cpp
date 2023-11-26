#include <bits/stdc++.h>
using namespace std;
int n,used[100],nums[100];

void print()//Êä³ö
{
    int i;
    for(i=1;i<=n;i++)
    printf("%5d",nums[i]);
    printf("\n");
}

void dfs(int k){
    int i;
    if(k==n) {
        print();
        return;
    }
    for(i=1;i<=n;i++){
        if(!used[i])
        {
            used[i]=1;
            nums[k+1]=i;
            dfs(k+1);
            used[i]=0;
        }
    }
}

int main()
{
    cin>>n;
    dfs(0);
    return 0;
}