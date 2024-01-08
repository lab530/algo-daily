#include<bits/stdc++.h>
using namespace std;
int n;
int m = 0;
int mix = INT_MAX;
struct lll{
	int number;
	int left;
	int right;
	int connect;
}ku[105];

void bfs(int white,int k, int value){
	m += ku[k].number * value;//计算值
	//cout << 1;connect和right,left起了冲突
	if(ku[k].left != 0 && ku[k].left != white) bfs(k, ku[k].left, value + 1);
	if(ku[k].right != 0 && ku[k].right != white) bfs(k, ku[k].right, value + 1);
	if(ku[k].connect != 0 && ku[k].connect != white) bfs(k, ku[k].connect, value + 1);
	return ;
}

void slove(){
	for(int i = 1; i <= n; i++){
		cin >> ku[i].number >> ku[i].left >> ku[i].right;
		if(ku[i].left != 0){//反向寻找
			ku[ku[i].left].connect = i;
		}
		if(ku[i].right != 0){
			ku[ku[i].right].connect = i;
		}
	}
	for(int i = 1; i <= n; i++){
		m = 0;
		bfs(0, i, 0);
		mix = min(mix, m);
	}
	cout << mix;
	return ;
}
int main(){
	//cout << ku[3].right;
	cin >> n;
	slove();
	return 0;
}