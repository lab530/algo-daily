#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
struct node{
	int l, r;
};
string ans = "A";
vector<int> A;
bool cmp(node x, node y){
	return x.l*x.r < y.l*y.r;
}
string compare(string a, string b){
	if(a.length() < b.length()) return b;
	if(a.length() == b.length()){
		int n = a.length();
		for(int i = 0; i < n; ++i){
			if(a[i] > b[i]) return a;
			if(a[i] < b[i]) return b;
		}
	}
	return a;
}
void highmul(int a, int b){
	// highdiv
	vector<int> C;
	string temp; 
	int r = 0;
	for(int i = A.size() - 1; i >= 0; --i){
		r = (r*10 + A[i]);
		C.push_back(r / b); 
		r %= b;
	}
	reverse(C.begin(), C.end());
	while(C.size() > 1 && C.back() == 0) C.pop_back();
	for(int i = C.size() - 1; i >= 0; --i){
		temp = temp + to_string(C[i]);
	}	
	// compare
	if(ans == "A") ans = temp;
	else ans = compare(temp, ans);
	C.clear();
	// highmul
	int sum = 0;
	for(int i = 0; i < A.size() || sum; ++i){
		if(i < A.size()) sum += A[i] * a;
		C.push_back(sum % 10);
		sum /= 10;
	}
	while(C.size() > 1 && C.back() == 0) C.pop_back();
	A = C;
}
void init(int a){
	while(a){
		A.push_back(a % 10);
		a /= 10;
	}
}
void solve(){
	int n, a, b;
	cin >> n >> a >> b;
	vector<node> v(n);
	init(a);
	for(int i = 0; i < n; i++)
		cin >> v[i].l >> v[i].r;
	sort(v.begin(), v.end(), cmp);
	for(int i = 0; i < n; i++){
		highmul(v[i].l, v[i].r);	
	}
	cout << ans << endl;
}
int main(){
	solve();
	return 0;
}