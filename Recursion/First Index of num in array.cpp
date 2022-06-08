#include<iostream>
using namespace std;

int helper(int input[], int size, int x, int i){
    if(size == 0){
        return -1;
    }
    
    if(input[0] == x){
        return i;
    }
    
    return helper(input + 1, size - 1, x, i+1);
}


int firstIndex(int input[], int size, int x) {
	return helper(input, size, x, 0);
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    cout << firstIndex(input, n, x) << endl;

}