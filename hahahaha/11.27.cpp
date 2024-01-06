#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    string record;
    int a = 0, b = 0; 
    string ch;
    int flag = 0;
    while(!flag) {
        cin >> ch;
        for(int i = 0; i < ch.size(); ++i) {
            record += ch[i];
            if(ch[i] == 'E') {
                flag = 1;
                break;
            } 
        }
    }
    int num = record.size();
    for(int i = 0; i < num; ++i) {
        
        if(record[i] == 'W') {
            a++;
        }
        else if(record[i] == 'L') {
            b++;
        }
        else if(record[i] == 'E') {
            break;
        }
        if((a == 11 && b <= 9)|| (b == 11&& a <= 9)) {
            cout << a << ":" << b << endl;
            a = 0;
            b = 0;
        } else if (a >= 10 && b >= 10 && abs(a - b) == 2){
            cout << a << ":" << b << endl;
            a = 0;
            b = 0;
        }

    }
    cout << a << ":" << b << endl;
    a = 0;
    b = 0;
    cout << endl;


    for(int i = 0; i < num; ++i) {
        
        if(record[i] == 'W') {
            a++;
        }
        else if(record[i] == 'L') {
            b++;
        }
        else if(record[i] == 'E') {
            break;
        }
        if((a == 21 && b <= 19)|| (b == 21 && a <= 19)) {
            cout << a << ":" << b << endl;
            a = 0;
            b = 0;
        } else if (a >= 20 && b >= 20 && abs(a - b) == 2){
            cout << a << ":" << b << endl;
            a = 0;
            b = 0;
        }
    }
    cout << a << ":" << b << endl;

    return 0; 
}
