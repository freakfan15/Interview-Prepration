/*
Lexicographical Order
Send Feedback
Given a number n, print numbers from 1 to n in dictionary(lexicographical) order.
Sample Input
20
Sample Output
1
10
11
12
13
14
15
16
17
18
19
2
20
3
4
5
6
7
8
9
*/
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
