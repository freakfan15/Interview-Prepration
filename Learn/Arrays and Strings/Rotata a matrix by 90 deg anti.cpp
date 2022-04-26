#include <iostream>
using namespace std;

void rotate(int **input, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i>j){
                swap(input[i][j], input[j][i]);
            }
        }
    }

    int s = 0, e = n-1;
    while(s<e){
        int j = 0;
        while(j<n){
            swap(input[s][j], input[e][j]);
            j++;
        }
        s++; e--;
    }
}


int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

    int n;
    cin >> n;
    
    int **input = new int*[n];
    
    for(int i = 0; i < n; i++) {
        input[i] = new int[n];
        for(int j = 0; j < n; j++) {
            cin >> input[i][j];
        }
    }
    
    rotate(input, n);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << input[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}