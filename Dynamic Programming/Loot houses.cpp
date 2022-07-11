/*
A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
Input format :
The first line of input contains an integer value of 'n'. It is the total number of houses.

The second line of input contains 'n' integer values separated by a single space denoting the amount of money each house has.
Output format :
Print the the maximum money that can be looted.
Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1 :
6
5 5 10 100 10 5
Sample Output 1 :
110
Sample Input 2 :
6
10 2 30 20 3 50
Sample Output 2 :
90
Explanation of Sample Output 2 :
Looting first, third, and the last houses([10 + 30 + 50]) will result in the maximum loot, and all the other possible combinations would result in less than 90.
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std;

int maxSum(int* arr, int i, int n, int* dp){
    if(i>=n){
        return 0;
    }

    if(dp[i]!=-1){
        return dp[i];
    }
    int igap = maxSum(arr, i+2, n, dp);
    int nogap = maxSum(arr, i+1, n, dp);

    int res = max(arr[i] + igap, nogap);
    dp[i] = res;
    return res;
}

int maxMoneyLooted(int *arr, int n)
{

    int* dp = new int[n+2];
    for(int i=0; i<n+2; i++){
        dp[i] = -1;
    }
    int ans = maxSum(arr, 0, n, dp);

    delete [] dp;
    return ans;
}

//using iteration
int maxMoneyLooted2(int * arr, int n){
	int* dp = new int[n];

	dp[0] = arr[0];
	dp[1] = arr[1];

	for(int i=2; i<n; i++){
		dp[i] = max(dp[i-2] + arr[i], dp[i-1]);
	}

	return dp[n-1];
}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << maxMoneyLooted(arr, n);

    delete[] arr;
    return 0;
}
