#include <iostream>
#include <vector>
using namespace std;
void solve(){
	string b, a;
	cin >> a >> b;
	vector<int> A, B;
	for(int i = a.length() - 1; i >= 0; i--){
		A.push_back(a[i] - '0');
	}
	for(int i = b.length() - 1; i >= 0; i--){
		B.push_back(b[i] - '0');
	}	
	vector<int> c;
	int t = 0;
	for(int i = 0; i < A.size() || i < B.size(); i++){
		if(i < A.size())	t += A[i];
		if(i < B.size())	t += B[i];
		c.push_back(t % 10);
		t /= 10;
	}
	if(t) c.push_back(1);
	for(int i = c.size() - 1; i >= 0; i--)
		cout << c[i];
}
int main(){
	solve();
	return 0;
}