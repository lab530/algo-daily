#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    int n, cha[1100], i;
    int shu[1100];
    int b = 0;

    cin >> n;
    shu[0] = n;

    for( i = 1; i <= n; i++) {
        cin >> shu[i];
    }
    
    for( i = 1; i < n; i++) {
        cha[i] = abs(shu[i] - shu[i+1]);
    }

    sort(cha + 1,cha + n);

    for( i = 1; i < n ; i++) {
       
        if(cha[i] != i ){
            b++;
        }
        
    }

    if(b == 0){
        cout << "Jolly";
    }

    else {
        cout << "Not jolly";
    }

    return 0;
}
