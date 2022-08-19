#include<climits>
#include<vector>
int find(int* arr, int s, int e, vector<vector<int>> &dp){
	// if(s==e){
	// return 0;
	// }
    if(s==e-1){ //1 matrix only means 2 elements [a0 a1]
        return 0;
    }
    
    if(dp[s][e]!=-1){
        return dp[s][e];
    }
    
	int res = INT_MAX;
    
    for(int k=s+1; k<=e-1; k++){
        int first = find(arr, s, k, dp);
        int second = find(arr, k, e, dp);
        int third = arr[s]*arr[k]*arr[e];
        res = min(res, first + second + third);
    }
    
    dp[s][e] = res;
    return res;
    
}

int matrixChainMultiplication(int* arr, int n) {
    // Write your code here
    
    vector<vector<int>> dp;
    for(int i=0; i<=n; i++){
        vector<int> vi(n+1 , -1);
        dp.push_back(vi);
    }
    
    return find(arr, 0, n, dp);
    
}