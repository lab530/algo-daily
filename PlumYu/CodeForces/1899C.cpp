#include<iostream>
#include<vector>
using namespace std;
void solve()
{
	int n, maxval = -3010, ans = 0;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		maxval = max(a[i], maxval);
	}
	if(maxval <= 0)	cout << maxval << '\n';
	else
	{
		int sum = a[0];
		for(int i = 1; i < n; i++)
		{
			if((a[i - 1] + 1010) % 2 != (a[i] + 1010) % 2)
			{
				if(sum + a[i] > 0)
				{
					if(i == 1 && sum < 0) sum = 0;
					sum += a[i];
				}
				else
				{
					sum = max(a[i], 0);
				}
			}
			else
			{
				sum = max(0, a[i]);
			}
			ans = max(ans, sum);
		}
		cout << max(ans, maxval) << endl;
	}
}
int main()
{
	int __;
	cin >> __;
	while(__--) solve();
	return 0;
}