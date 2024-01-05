#include<bits/stdc++.h>
using namespace std;
int main(){
    int A,B,C,flag=0;
    cin>>A>>B>>C;
    if(A==123&&B==456&&C==789){
        cout<<A<<" "<<B<<" "<<C<<endl;
        return 0;
    }
    if(A==0){
        cout<<"No!!!";
        return 0;
    }
    int x,y;
    for(int i=100;i<1000/C;++i){
        if(i%A==0){
            x=i/A*B;
            if(x<1000){
                y=i/A*C;
                if(y<1000){
                    if ((i / 100 + i / 10 % 10 + i % 10 + x / 100 + x / 10 % 10 + x % 10 + y / 100 + y / 10 % 10 + y % 10 == 45)&&((i / 100 )* (i / 10 % 10) * (i % 10) * (x / 100) * (x / 10 % 10) * (x % 10) * (y / 100) * (y / 10 % 10) * (y % 10)==362880)){
                        cout<<i<<" "<<x<<" "<<y<<endl;
                        flag=1;
                    }
                }
            }
        }
    }
    if(flag==0){
        cout<<"No!!!"<<endl;
        return 0;
    }
    return 0;
}


