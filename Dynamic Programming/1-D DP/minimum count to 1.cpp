#include <bits/stdc++.h>
using namespace std;

int countStepsToOne(int n, int* dp){
    if(n == 1){
    	return 0;
    }
    
    if(dp[n]!=-1){
        return dp[n];
    }
    
    int res = countStepsToOne(n-1, dp);
    
    if(n%2 == 0){
        res = min(res, countStepsToOne(n/2, dp));
    }
    
    if(n%3 == 0){
        res = min(res, countStepsToOne(n/3, dp));
    }
    dp[n] = 1 + res;
    return dp[n];
}

int countStepsToOne(int n)
{

    int* arr = new int[n+1];
    for(int i=0; i<=n; i++){
        arr[i] = -1;
    }
    return countStepsToOne(n, arr);
}

int main()
{
	int n;
	cin >> n;
	cout << countStepsToOne(n);
}