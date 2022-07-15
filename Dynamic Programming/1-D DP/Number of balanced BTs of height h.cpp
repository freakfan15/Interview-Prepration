/*
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Time complexity should be O(h).
Input Format :
The first and only line of input contains an integer, that denotes the value of h. Here, h is the height of the tree.
Output Format :
The first and only line of output contains the count of balanced binary trees modulus 10^9 + 7.
Constraints :
1 <= h <= 10^6
Time Limit: 1 sec
Sample Input 1:
3
Sample Output 1:
15
Sample Input 2:
4
Sample Output 2:
315
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std;

const unsigned int M = 1000000007;
int find(int n, int* dp){
    if(n == 1 || n == 0){
        return 1;
    }

    if(dp[n]!=-1){
        return dp[n];
    }

    int h1 = find(n-1, dp);
    int h2 = find(n-2, dp);

    int output = ((1LL*h1*h1)%M + (2LL*h1*h2)%M)%M;
    dp[n] = output;
    return output;
}

int balancedBTs(int n) {
    int* dp = new int[n+1];
    for(int i=0; i<=n; i++){
        dp[i] = -1;
    }

    int ans = find(n, dp);

    delete [] dp;
    return ans;
}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
    int n;
    cin >> n;
    cout << balancedBTs(n);
    return 0;
}