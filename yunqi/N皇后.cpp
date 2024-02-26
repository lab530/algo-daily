#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
#include<stack>
#include<queue>
#include<climits>
using i64 = long long;
using namespace std;
const int MANX = 200005;

/*
1.����һ������ȥ��Ǳ�ʹ�ù�����
2.�ҵ��Խ������±��ӳ���ϵ
3.��������
*/
int n;
int arr[15];   // �������
int line[15], neglect[30], restrain[30];   // �У�Ʋ����
int ans;

void dfs(int cnt)   // cnt ��ʾ����
{
    if(cnt > n){
        ans++;
        if(ans <= 3){
            for(int i = 1; i <= n; ++i)
            {
                cout << arr[i] << ' ';
            }
            cout << endl;
        }
    }

    // ������
    for(int i = 1; i <= n; ++i)
    {
       if(line[i] || neglect[i + cnt] || restrain[cnt - i + n]) continue;

       arr[cnt] = i;
       line[i] = neglect[i + cnt] = restrain[cnt - i + n] = 1;  // ����Ѿ�ʹ�ù���neglect�Խ���<����֮�Ͳ���>�� restrain�Խ���<����֮��䣬 ��ֹ����������>
       dfs(cnt + 1);
       line[i] = neglect[i + cnt] = restrain[cnt - i + n] = 0;
    }
}

int main()
{
    cin >> n;
    dfs(1);
    cout << ans << endl;
    return 0;
}