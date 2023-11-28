#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int treasure_selection(int n, int W, const vector<vector<int>>& treasures) {
	vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
	
	for (int i = 1; i <= n; i++) {
		int v_i = treasures[i - 1][0];
		int w_i = treasures[i - 1][1];
		int m_i = treasures[i - 1][2];
		for (int j = 1; j <= W; j++) {
			for (int k = 0; k <= min(m_i, j / w_i); k++) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - k * w_i] + k * v_i);
			}
		}
	}
	
	return dp[n][W];
}

int main() {
	int n, W;
	cin >> n >> W;
	
	vector<vector<int>> treasures(n, vector<int>(3));
	for (int i = 0; i < n; i++) {
		cin >> treasures[i][0] >> treasures[i][1] >> treasures[i][2];
	}
	
	int result = treasure_selection(n, W, treasures);
	cout << result << endl;
	
	return 0;
}