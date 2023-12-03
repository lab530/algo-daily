#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<long long> ayin;

int main()
{
	long long n, m;
	cin >> n >> m;
	int p = 0;
	long long ans = 0;
	vector<long long> k(n + 1, 0);
	vector<long long> c(n + 1, 0); // 修改为 long long 类型
	
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
	}
	
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
		p += c[i] * k[i];
	}
	ayin.resize(p + 1, 1); // 修改为初始值为0
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = p; j >= 0; j--)
		{
			for (int z = 1; z <= k[i]&&z*c[i] <= j; z++)
			{
				ayin[j] = max(ayin[j], ayin[j - z*c[i]] * z); // 修改为加法
			}
		}
	}
	
	for (; ans <= p && ayin[ans] < m; )
	{
		ans++;
	}
	cout << ans;
	return 0;
}
