#include<iostream>
using namespace std;

int sum(int a[], int n) {
	if(n==1){
        return a[0];
	}
    
	int smallArray = sum(a+1, n-1);
    return a[0] + smallArray;
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    cout << sum(input, n) << endl;
}