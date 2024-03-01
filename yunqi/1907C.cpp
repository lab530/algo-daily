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

void slove()
{
	int n;
	cin >> n;
	string str;
	cin >> str;
	vector<int> arr(26);
	for(int i = 0; i < n; ++i){
		arr[str[i] - 'a']++;
	}
	int maxx = 0;
	for(int i = 0; i < 26; ++i){
		maxx = max(maxx, arr[i]);
	}
	if(maxx <= maxx - n){
		if(n % 2 == 0){
			cout << 0 << endl;
		}
		else{
			cout << 1 << endl;
		}
	}
	else{
		cout << maxx * 2 - n << endl;
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
