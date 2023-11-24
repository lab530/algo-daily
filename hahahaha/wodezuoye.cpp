#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct water{
    int number;
    int t;
}x[1100];

bool role(water a, water b){
    if(a.t == b.t){
        return a.number < b.number;
    }
    else{
        return a.t < b.t;
    }
}

int main(){
    int n, i;
    cin >> n;
    for(i = 0; i < n; i++){
        x[i].number = i + 1;
        cin >> x[i].t;
    }

    sort(x, x + n, role);
    // for( i = 0; i < n; i++){
    //      cout << x[i].number << " " <<  x[i].t << endl;
    //  }

    int time = 0;
    double average = 0;

    for(i = 0; i <n; i++){
        time = time + x[i-1].t;
        average += time;
        // cout << time << " " << x[i].t << endl; 
    }

    for( i = 0; i < n; i++){
        cout << x[i].number << " ";
    }
    cout << endl;
    
    printf("%.2lf", 1.0*average/ n); 

    return 0;
}