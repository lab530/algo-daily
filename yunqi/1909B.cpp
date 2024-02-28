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
	vector<i64> arr(n);
	for(int i = 0; i < n; ++i) cin >> arr[i];
	int odd = 0, even = 0;
	for(int i = 0; i < n; ++i){
		if(arr[i] % 2 == 0){
			even++;
		}
		else odd++;
	}
	if(odd > 0 && even > 0){
		cout << 2 << endl;
	}
	if(odd == 0 || even == 0){
		i64 k = 1;
		while(true){
			for(int i = 0; i < n; ++i){
				if(arr[i] % k != arr[0] % k){
					cout << k << endl;
					return;
				}
			}
			k *= 2;
		}
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
