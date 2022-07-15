/*
Given an array with N elements, you need to find the length of the longest subsequence in the given array such that all elements of the subsequence are sorted in 
strictly increasing order.
Input Format
The first line of input contains an integer N. The following line contains N space separated integers, that denote the value of elements of array.
Output Format
The first and only line of output contains the length of longest subsequence.
Constraints
1 <= N <= 10^3
Time Limit: 1 second
Sample Input 1 :
6
5 4 11 1 16 8
Sample Output 1 :
3
Sample Output Explanation
Length of longest subsequence is 3 i.e. (5,11,16) or (4,11,16).
Sample Input 2 :
3
1 2 2
Sample Output 2 :
2
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std;

void generate(int* arr, int n, int* leftmax){
    if(n==0){
        leftmax[0] = 1;
        return;
    }

    generate(arr, n-1, leftmax);
    int maxLeft = 0;
    for(int i=0; i<n; i++){
        if(leftmax[i] > maxLeft && arr[i] <arr[n-1]){
            maxLeft = leftmax[i];       
        }
    }
    leftmax[n-1] = 1 + maxLeft;
}

int longestIncreasingSubsequence(int* arr, int n) {
    // Write your code here
    int* leftmax = new int[n];
    int largest = 0;
    generate(arr, n, leftmax);
    for(int i=0; i<n; i++){
        cout<<leftmax[i]<<" ";
        if(leftmax[i] > largest){
            largest = leftmax[i];
        }
    }
    cout<<endl;

    return largest;
}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << longestIncreasingSubsequence(arr, n);
    return 0;
}
