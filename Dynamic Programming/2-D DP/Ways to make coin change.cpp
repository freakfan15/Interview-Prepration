/*
For the given infinite supply of coins of each of denominations, D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make the change for Value V using coins of denominations D.
Return 0 if the change isn't possible.
Input Format
The first line of the input contains an integer value N, which denotes the total number of denominations.

The second line of input contains N values, separated by a single space. These values denote the value of denomination.

The third line of the input contains an integer value, that denotes the value of V.
Output Format
Print the total total number of ways i.e. W.
Constraints :
1 <= n <= 10
1 <= V <= 1000

Time Limit: 1sec
Sample Input 1 :
3
1 2 3
4
Sample Output 1 :
4
Explanation to Sample Input 1 :
Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).
Sample Input 2 :
6
1 2 3 4 5 6
250
Sample Output 2 :
13868903
*/

#include <iostream>
#include <vector>
using namespace std;

int countWaysToMakeChangeHelp(int denominations[], int numDenominations, int value, vector<vector<int>> &dp){
    if(value==0){
        return 1;
    }
    if(numDenominations==0){
        return 0;
    }

    if(dp[value][numDenominations] != -1){
        return dp[value][numDenominations];
    }

    int pick=0;
    if(denominations[0]<=value){
        pick = countWaysToMakeChangeHelp(denominations, numDenominations, value - denominations[0], dp);
    }
    int notpick = countWaysToMakeChangeHelp(denominations+1, numDenominations-1, value, dp);

    int ans = pick + notpick;
    dp[value][numDenominations] = ans;
    return ans;

}

int countWaysToMakeChange(int denominations[], int numDenominations, int value){
    vvi dp(value+1, vi (numDenominations+1, -1));

    return countWaysToMakeChangeHelp(denominations, numDenominations, value, dp);

}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

    
    int numDenominations;
    cin >> numDenominations;
    
    int *denominations = new int[numDenominations];

    for (int i = 0; i < numDenominations; i++)
    {
        cin >> denominations[i];
    }

    int value;
    cin >> value;

    cout << countWaysToMakeChange(denominations, numDenominations, value);

    delete[] denominations;


    return 0;
}