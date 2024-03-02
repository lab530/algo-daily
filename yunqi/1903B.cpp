#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<stack>
#include<queue>
#include<climits>
using i64 = long long;
using namespace std;
const int manx = 200005;
i64 arr[1005][1005];

void slove()
{
	int n;
	cin >> n;
	if(n == 1){
		int a;
		cin >> a;
		cout << "YES" << endl;
		cout << 1 << endl;
		return;
	}

	vector<i64> ans(n, -1);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> arr[i][j];
			if(i != j){
				if(ans[i] == -1){
					ans[i] = arr[i][j];
				}
				else{
					ans[i] &= arr[i][j];
				}
			}
		}
	}

	int flag = 1;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(i != j && (ans[i] | ans[j]) != arr[i][j]){
				flag = 0;
				break;
			}
		}
	}

	if(flag){
		cout << "YES" << endl;
		for(int i = 0; i < n; ++i){
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	else{
		cout << "NO" << endl;
	}
}

int main(){
	int t;
	cin >> t;
	while(t--)
	{
		slove();
	}
	return 0;
}
