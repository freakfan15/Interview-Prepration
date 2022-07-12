/*
Miss. Noor Rashid is a teacher. She wants to give some chocolates to the students in her class. All the students sit in a line, and each of them has a score according to performance. Noor wants to give at least one chocolate to each student. She distributes chocolates to them such that If two students sit next to each other, then the one with the higher score must get more chocolates. Miss. Noor wants to save money, so she wants to minimize the total number of chocolates.
Note :
When two students have an equal score, they are allowed to have a different number of chocolates. 
Input Format:
The first line of the input contains an integer value of N. It denotes the total number of students in Noor's class.

The second line of the input contains N integer values denoting the score of each of the students. A single space will separate them.
Output Format:
Print the minimum number of chocolates Noor must give.
Constraints
1 <= N <= 10^5
1 <= score <= 10^5

Time Limit: 1 sec
Sample Input 1 :
4
1 4 4 6
Sample Output 1 :
6
Explanation:
One of the ways in which the chocolates can be distributed, such Noor has to give minimum number of chocolates, are: The first student can be given one chocolate, second student can be given two chocolates, third student can be one chocolate and fourth can be given two chocolates.  
Sample Input 2 :
3
8 7 5
Sample Output 2 :
6
Sample Input 3 :
20
82440 36222 39726 90098 21130 95534 90800 97143 56966 45758 27836 30506 59211 72381 5674 45858 85108 10284 93404 66620
Sample Output 3 :
41
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std;

int getMin(int *arr, int n)
{
    int* dp = new int[n];
    dp[0] = 1;

    for(int i=1; i<n; i++){
        if(arr[i] > arr[i-1]){
            dp[i] = 1 + dp[i-1];
        }
        else{
            dp[i] = 1;
        }
    }

    int sum = dp[n-1];
    for(int i=n-2; i>=0; i--){
        if(arr[i] > arr[i+1] && dp[i] <= dp[i+1]){
            cout<<i<<endl;
            dp[i] = 1 + dp[i+1];
        }
        sum+=dp[i];
    }

    return sum;
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

    cout << getMin(arr, n);
    delete[] arr;
    return 0;
}