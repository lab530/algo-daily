#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

int main()
{
	int a = 0;
	int binah = 0;
	string ayin;
	cin >> a;
	cin >> ayin;
	vector<int>carmen(ayin.size(), 0);
	for(int i = 1; i < a; i++)
	{
		if(ayin[i] == ayin[binah])
		{
			binah++;
			carmen[i] = binah;
		}
		else
		{
			if(binah != 0)
			{
				binah = carmen[binah - 1];
				i--;
			}
			else
			{
				carmen[i] = 0;
			}
		}
	}
	cout << a - carmen[carmen.size() - 1];
}