/*
Print Subsets of Array
Send Feedback
Given an integer array (of length n), find and print all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print the subsets in different lines.
Input format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)
Constraints :
1 <= n <= 15
Sample Input:
3
15 20 12
Sample Output:
[] (this just represents an empty array, don't worry about the square brackets)
12 
20 
20 12 
15 
15 12 
15 20 
15 20 12 
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std;

void generate(vector<int> &subset, int* input, int n){
    if(n==0){
        for(int s: subset){
            cout<<s<<" ";
        }
        cout<<endl;
        return;
    }
    //dont include in subset
    generate(subset, input+1, n-1);
        
    //include in subset
    subset.push_back(input[0]);
    generate(subset, input+1, n-1);
    subset.pop_back();
    
}

void printSubsetsOfArray(int input[], int size) {
    // Write your code here
    vector<int> subset;
    generate(subset, input, size);  
}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
    int input[1000],length;
    cin >> length;
    for(int i=0; i < length; i++)
        cin >> input[i];
    printSubsetsOfArray(input, length);
    
    return 0;
}