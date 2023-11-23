#include <iostream>
using namespace std;

int main(){
	int t = 0; 
	cin >> t;
	while(t--){
		int n = 0, k =0;
		cin >> n >> k; 

		int check = 0; 
        
		for(int i = 0; i< n; i++){
			int mun; 
			cin >> mun;

			if(mun == k){
                check = 1;
            }  
		}

		if(check == 1) {
            cout << "YES" << endl; 
        } 
		else {
            cout << "NO" << endl;
        } 
	}

    return 0;
}