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
	vector<i64> arr(n + 1), summ(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> arr[i];
		summ[i] = summ[i - 1] + arr[i];
	}

	int odd = 0, even = 0;
	vector<i64> ans(n + 1);
	for(int i = 1; i <= n; ++i){
		if(arr[i] % 2 == 0){
			even++;
		}
		else odd++;

		i64 times = odd / 3;
		summ[i] -= times;
		if(odd % 3 == 1){
			summ[i]--;
		}

		ans[i] = summ[i];
		if(i == 1) ans[i] = arr[i];
	}

	for(int i = 1; i <= n; ++i) cout << ans[i] << ' ';
	cout << endl;

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
