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

struct amount
{
	int a;
	int b; 
}am[manx];

bool cmp(amount x, amount y)
{
	return x.b > y.b;
}

void slove()
{
	int n;
	cin >> n;
	i64 summ = 0, minn = 10e9 + 1;
	int cnt = 0;
	while(n--){
		int x;
		cin >> x;
		vector<int> arr(x);
		for(int i = 0; i < x; ++i){
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end());
		if(arr[0] < minn){
			minn = arr[0];
		}
		am[cnt].a = arr[0];
		am[cnt].b = arr[1];
		cnt++;
	}
	sort(am, am + cnt, cmp);
	// for(int i = 0; i < cnt; ++i){
	// 	cout << am[i].a << ' ' << am[i].b << endl;
	// }
	for(int i = 0; i < cnt - 1; ++i){
		summ += am[i].b;
	}
	summ += minn;
	cout << summ << endl;
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
