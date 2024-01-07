#include<bits/stdc++.h>
using namespace std;
int  n;
struct kkk{
    int left;
    int right;
}ku[1000005];
//求前序序列的递归，深搜
int bfs1(int w){
    if(ku[w].left != 0){
        cout << ku[w].left << " ";
        bfs1(ku[w].left);
    }
    if(ku[w].right != 0){
        cout << ku[w].right << " ";
        bfs1(ku[w].right);
    }
    return 0;
}
//求中序序列的递归，深搜
int bfs2(int w){
    if(ku[w].left != 0){
        bfs2(ku[w].left);
        //cout << ku[w].left << " ";
    }
    cout << w << " ";
    if(ku[w].right != 0){
        bfs2(ku[w].right);
        //cout << ku[w].right << " ";
    }
    return 0;
}
//求后序的
int bfs3(int w){
    if(ku[w].left != 0){
        bfs3(ku[w].left);
        cout << ku[w].left << " ";
    }
    if(ku[w].right != 0){
        bfs3(ku[w].right);
        cout << ku[w].right << " ";
    }
    //cout << w << " ";
    return 0;
}
void front(){
    cout << 1 << " ";
    bfs1(1);
    cout << endl;
    return ;
}

void middle(){
    bfs2(1);
    cout << endl;
    return ;
}

void beside(){
    bfs3(1);
    cout << 1 << " ";
    cout << endl;
    return ;
}
void slove(){
    for(int i = 1; i <= n; i++){
        cin >> ku[i].left >> ku[i].right;
    }
    front();
    middle();
    beside();
}
int main(){
    
    cin >> n;
    slove();
    return 0;
}