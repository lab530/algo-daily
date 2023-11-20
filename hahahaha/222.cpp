#include <iostream>
#include <algorithm>
#include <functional>
#include <cstdio>
using namespace std;

struct good{
    int weight;
    int money;
    float bi;
}haha[150];

bool role (good a, good b){
    return a.bi > b.bi ;
}

int main(){
    int n, t;
    cin >> n >> t;
   
    for(int i = 0; i < n; i++){
        cin >> haha[i].weight >> haha[i].money;
        haha[i].bi = 1.0 * haha[i].money / haha[i].weight;
    }

    sort(haha, haha + n, role);

    float qian = 0;

    for(int i = 0; i < n; i++){
        if(haha[i].weight <= t) {
            t = t - haha[i].weight;
            qian = qian + haha[i].money;
        }

        else {
            qian = qian + t * haha[i].bi;
            break;
        }
    }

    printf("%.2f",qian);

    return 0;
}