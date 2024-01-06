#include <iostream>
#include <vector>
using namespace std;
void solve(){
	string a;
	int b;
	cin >> a >> b;
	vector<int> A, C;
	for(int i = a.length() - 1; i >= 0; --i){
		A.push_back(a[i] - '0');
	}
	int t = 0;
	for(int i = 0; i < A.size() || t; ++i){
		if(i < A.size()) t += A[i] * b;
		C.push_back(t % 10);
		t /= 10;
	}
	while(C.size() > 1 && C.back() == 0) C.pop_back();
	for(int i = C.size() - 1; i >= 0; i--)
		cout << C[i];
}
int main(){
	solve();
	return 0;
}