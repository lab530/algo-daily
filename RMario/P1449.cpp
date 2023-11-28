#include<bits/stdc++.h>
using namespace std;
stack<int>q;
string c;
int main(){
    cin>>c;
    int a=0,b=0;
    int i,j;
    for(int k=0;k<c.size();k++){
        if(c[k]=='@')break;
        else if(c[k]=='.'){
            q.push(a);
            b=0,a=0;
        }
        else if(c[k]<='9'&&c[k]>='0'){
            a=b*10+c[k]-'0';
            b=a;
        }
        else{
            if(c[k]=='+') i=q.top(),q.pop(),q.pop(),q.push(j-i);
            if(c[k]=='-') i=q.top(),q.pop(),q.pop(),q.push(j+i);
            if(c[k]=='*') i=q.top(),q.pop(),q.pop(),q.push(j*i);
            if(c[k]=='/') i=q.top(),q.pop(),q.pop(),q.push(j/i);
        }
    }
    cout<<q.top();
    return 0;
}