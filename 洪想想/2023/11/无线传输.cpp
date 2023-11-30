#include<bits/stdc++.h>
using namespace std;
void kpm(string s,int l){
    int n = l;
    int i = 0;//跑前缀
    int j = 1;//跑后缀
    vector<int> res(n,0);
    while(j < n){
        if(s[i] == s[j]){
            i++;
            res[j] = i;
            j++;
            //break;
        }else{
            if(i != 0){
                i = res[i-1];
            }else{
                res[j] = 0;
                j++;
            }
        }
    }
    /*for(int i = 0; i<n; i++){
        cout << res[i] << endl;
    }*/
    /*int yy;                                                    
    for(int i = 0; i < n; i++){
        if(res[i] == 0){
            //cout << 1 <<endl;
            yy = i;                                                                                                                   
        }
    }   */                                                                                                 
    cout << n - res[n - 1]; 
    
    return;   
}

int main(){ 
    int l;
    string s;
    cin >>l >>s;
    kpm(s,l);
    return 0;
}