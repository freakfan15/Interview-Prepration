/*
Given an integer N, find and return the count of unique Binary search trees (BSTs) are possible with nodes valued from 1 to N.
Output count can be very large, so return the count modulo 10^9+7.
Input Format :
Integer n 
Output Format :
Count of BSTs
Contraints :
1<= N <=1000
Sample Input 1:
8
Sample Output 1:
1430
Sample Input 2:
3
Sample Output 2:
5
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
int count(int n, int * dp){
    if(n==0 || n==1){
        return 1;
    }

    //let say we place k at root node, then left  side will contain[1---k-1] and right sub tree [k+1...n]
    if(dp[n]!=-1){
        return dp[n];
    }

    int output = 0;    
    for(int k=1; k<=n; k++){
        int left = count(k-1, dp);
        int right = count(n-k, dp);

        output = (output + (1LL*left*right)%M)%M;
    }    
    dp[n] = output;
    return output;
}

int countBST(int n)
{
    int* dp = new int[n+1];
    for(int i=0; i<=n; i++){
        dp[i] = -1;
    }

    int ans = count(n, dp);
    delete [] dp;
    return ans;
}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
    int n ;
    cin>>n;
    cout<<countBST(n);
    return 0;
}