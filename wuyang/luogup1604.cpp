#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    char a1[5005], b1[5005]; 
    int a[5005], b[5005], c[5005]; 
    int len_a, len_b, len_c = 1, x, i;
    scanf("%s %s",a1,b1);
    len_a = strlen(a1);
    len_b = strlen(b1);
    for(i=0; i<len_a; i++) {
        if(a1[i]>='A')
        a[len_a - i] = a1[i] - 'A'+10;
        else
        a[len_a - i] = a1[i] - '0'; 
    }
    for(i=0; i<len_b; i++) {
        if(b1[i]>='A')
        b[len_b - i] = b1[i] - 'A'+10;
        else
        b[len_b - i] = b1[i] - '0'; 
    }
    x = 0;
     while(len_c <= len_a || len_c <= len_b) {     
        c[len_c] = a[len_c] + b[len_c] + x;
        x = c[len_c] / n; 
        c[len_c] %= n; 
        len_c++;  
    }
    c[len_c] = x;
    while(c[len_c] == 0&&len_c>1) { 
        len_c--; 
    }
    for(int i=len_c; i>=1; i--) {
        if(c[i]<10)
        printf("%d", c[i]); 
        else
        printf("%c", c[i]+'A'-10); 
    }


    return 0;
}