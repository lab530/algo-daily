/*
链接：https://www.lanqiao.cn/problems/10015/learning/?contest_id=157
2023.12.28
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// void solve() {
//     int n; cin >> n; 
//     string s; cin >> s; 
//     s = " " + s; 
//     unordered_map<int, int> mp; 
//     for(int i = 0; i < n - 1; ++i) {
//         pair<int, int> p; cin >> p.first >> p.second; 
//         mp.insert(p); 
//     }
//     vector<char> vt; 
//     vt.push_back(s[1]); 
//     int sign = mp[1]; 
//     for(int i = 1; i < n; ++i) {
//         vt.push_back(s[sign]); 
//         sign = mp[sign]; 
//     }
//     for(char v: vt) cout << v << ' '; 
//     cout << endl; 
//     bool judge = true; 
//     for(int i = 2; i < vt.size(); ++i) {
//         if(vt[i] == vt[i - 1] && vt[i] == vt[i - 2]) {
//             judge = false; 
//             break; 
//         }
//     }
//     if(judge) cout << "YES" << endl; 
//     else cout << "NO" << endl; 
//     return; 
// }
/*
不可线性展开，因为可能会有节点连接两个点以上。
比如
in:
19
0000001100111101110
15 5
9 14
4 1
10 6
16 1
13 12
3 6
2 18
13 15
17 14
17 15
4 7
9 19
16 10
1 17
8 5
18 3
11 5
cnt: 1 1 1 2 2 1 1 1 1 1 1 3 2 0 1 1 2 1 0 1 2 1 0 0 1 1 1 0 2 0 
出现了一个节点 12 连接三个节点的情况，故判断cnt >= 2
*/
/*
题目思路：三个连续节点颜色相同不美观，但是可能会出现多于三个节点相连的可能因为二叉树中一个节点最多与三个节点相连

二叉树中与一个节点相连最多有三个点，对每个节点进行遍历，则能遍历出树上所有连续的三个点，
只要这三个点中没有两个以上的点与其相同，则是个漂亮的圣诞树。

颜色相同则计数cnt
*/
void solve() {
    int n; cin >> n; 
    string s; cin >> s; 
    s = " " + s; 
    vector<int> cnt(n + 1, 0); 
    for(int i = 1; i < n; ++i) {
        int x, y; cin >> x >> y; 
        if(s[x] == s[y]) {  // 说明颜色相同
            ++cnt[x]; 
            ++cnt[y]; 
        }
    }
    bool sign = true; 
    for(int i = 1; i < cnt.size(); ++i) {
        if(cnt[i] == 2 || cnt[i] == 3) sign = false; 
    }
    if(sign) cout << "YES" << endl; 
    else cout << "NO" << endl; 
}

int main() {
    int t; cin >> t; 
    while(t--) {
        solve(); 
    }
    return 0; 
}