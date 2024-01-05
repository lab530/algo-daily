#include<bits/stdc++.h>
using namespace std;
int kkk[1005];
int ku[1005][1005];
int main(){
    int n, m;
    cin >> n >> m;
    vector<int>a(n+5);
    vector<int>b(m + 5);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> b[i];
    }

    if(n == m){
        int nm = 0;
        for(int i = 0;i <= n; i++){
            nm = nm + a[i] * b[i];
        }
        cout << nm;
    }else if(2 * n > m){

        // for(int p = 1; p <= n; p++){
        //     kkk[p] = a[p] * b[p];
        // }
        for(int i = 1; i <= n; i++){
            for(int j = 1;j <= i; j++){
                if(i > j){
                   ku[i][j] = min(ku[i - 1][j - 1] + b[i] * a[j],ku[i - 1][j]); 
                }else{
                    ku[i][j] = ku[i - 1][j - 1] + b[i] * a[j]; 
                }
            }
        }
        int u = 2 * n - m;
        for(int i = n + 1; i <= m; i++){
            for(int j = u; j <= n; j++){
                ku[i][j] = min(ku[i - 1][j - 1] + b[i] * a[j],ku[i - 1][j]);
            }
        }
        cout << ku[m][n];
        
    }else{
        for(int i = 1; i <= n; i++){
            for(int j = 1;j <= i; j++){
                if(i > j){
                   ku[i][j] = min(ku[i - 1][j - 1] + b[i] * a[j],ku[i - 1][j]); 
                }else{
                    ku[i][j] = ku[i - 1][j - 1] + b[i] * a[j]; 
                }
            }
        }

        for(int i = n + 1; i <= m - n; i++){
            for(int j = 1; j <= n; j++){
                ku[i][j] = min(ku[i - 1][j - 1] + b[i] * a[j],ku[i - 1][j]);
            }
        }



        for(int i = m - n + 1; i <= m; i++){
            for(int j = i - m + n; j <= n; j++){
                ku[i][j] = min(ku[i - 1][j - 1] + b[i] * a[j],ku[i - 1][j]);
            }
        }
        cout << ku[m][n];
    }
    return 0;
}