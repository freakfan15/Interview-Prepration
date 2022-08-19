/*
Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.
Input format :
The first and the only line of input contains an integer value, 'N'.
 Output format :
Print the minimum count of numbers required.
Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1 :
12
Sample Output 1 :
3
Explanation of Sample Output 1 :
12 can be represented as : 
A) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)

B) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)  + (2 ^ 2)

C) (1^2) + (1^2) + (1^2) + (1^2) + (2 ^ 2) + (2 ^ 2)

D) (2 ^ 2) + (2 ^ 2) + (2 ^ 2)

As we can see, the output should be 3.
Sample Input 2 :
9
Sample Output 2 :
1
*/

#include <bits/stdc++.h>
using namespace std;

int minCount(int n, int* dp){
    if(n<=0){
        return 0;
    }

    if(n==1){
        return 1;
    }

    if(dp[n]!=-1){
        return dp[n];
    }

    int ans = n;

    for(int i=1; i<=n; i++){
        if(i*i > n){
            break;
        }

        int min_so_far = minCount(n - i*i, dp);
        ans = min(min_so_far, ans);
    }

    dp[n] = 1 + ans;

    return 1 + ans;
}

int minCount(int n)
{
    int* dp = new int[n+1];
    for(int i=0; i<=n; i++){
        dp[i] = -1;
    }

    int res = minCount(n, dp);

    return res;
}

int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}