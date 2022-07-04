#include <iostream>
using namespace std;

void lexicographicalOrderHelper(int numSoFar, int &num){
	// Write your code here
    
    if(numSoFar>num){
        return;
    }
    cout<<numSoFar<<endl;
    for(int i=0; i<=9; i++){
        lexicographicalOrderHelper(numSoFar*10 + i, num);
    }
}

void lexicographicalOrder(int num){
    for(int i=1; i<=9; i++){
        //print all numbers starting from i
        lexicographicalOrderHelper(i, num);
    }
}

int main() {
    int n;
    cin >> n;
    lexicographicalOrder(n);
}
