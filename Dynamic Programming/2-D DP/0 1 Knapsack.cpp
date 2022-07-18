/*
A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weighs wi and is of value vi. Considering the constraints of maximum weight that knapsack can carry, you have to find and return the maximum value that thief can generate by stealing items.
Note
Space complexity should be O(W).
Input Format :
The first line contains an integers, that denote the value of N. The following line contains N space separated integers, that denote the values of weight of items. The following line contains N space separated integers, that denote the values associated with the items. The following line contains an integer that denote the value of W. W denotes maximum weight that thief can carry.
Output Format :
The first and only line of output contains the maximum value that thief can generate, as described in the task. 
Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
Time Limit: 1 second
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output 1 :
13
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std;
#include "Solution.h"

//space O(n*W)
int knapsackHelper(int* weight, int* value, int n, int maxWeight, vector<vector<int>> &dp) {
    if(n==0){
        return 0;
    }
    if(n==1){
        if(weight[0]<=maxWeight){
            return value[0];
        }else{
            return 0;
        }
    }

    if(dp[maxWeight][n]!=-1){
        return dp[maxWeight][n];
    }

    int pick = INT_MIN;
    if(weight[0]<=maxWeight){
        pick = value[0] + knapsackHelper(weight+1, value+1, n-1, maxWeight-weight[0], dp);
    }
    int nonpick = knapsackHelper(weight+1, value+1, n-1, maxWeight, dp);

    int ans = max(pick, nonpick);
    dp[maxWeight][n] = ans;
    return ans;
}

int knapsack(int* weight, int* value, int n, int maxWeight) {
    
    vector<vector<int>> dp;

    for(int i=0; i<=maxWeight; i++){
        vector<int> vi(n+1, -1);
        dp.push_back(vi);
    }

    return knapsackHelper(weight, value, n, maxWeight, dp);
}


int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    
    int n;
    cin >> n;
    int* wt = new int[n];
    int* val = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    for (int j = 0; j < n; j++) {
        cin >> val[j];
    }

    int w;
    cin >> w;

    cout << knapsack(wt, val, n, w) << "\n";

    delete[] wt;
    delete[] val;


    return 0;
}