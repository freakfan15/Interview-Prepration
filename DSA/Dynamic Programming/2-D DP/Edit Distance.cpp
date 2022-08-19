/*
You are given two strings S and T of lengths M and N, respectively. Find the 'Edit Distance' between the strings.
Edit Distance of two strings is the minimum number of steps required to make one string equal to the other. In order to do so, you can perform the following three operations:
1. Delete a character
2. Replace a character with another one
3. Insert a character
Note :
Strings don't contain spaces in between.
 Input format :
The first line of input contains the string S of length M.

The second line of the input contains the String T of length N.
Output format :
Print the minimum 'Edit Distance' between the strings.
Constraints :
0 <= M <= 10 ^ 3
0 <= N <= 10 ^ 3

Time Limit: 1 sec
Sample Input 1 :
abc
dc
Sample Output 1 :
2
 Explanation to the Sample Input 1 :
 In 2 operations we can make string T to look like string S.
First, insert character 'a' to string T, which makes it "adc".

And secondly, replace the character 'd' of string T with 'b' from the string S. This would make string T as "abc" which is also string S. 

Hence, the minimum distance.
Sample Input 2 :
whgtdwhgtdg
aswcfg
Sample Output 2 :
9
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std;

#include<vector>
int find(string s1, string s2, int m, int n, vector<vector<int>> &dp){
    if(m==0){
        return n;
    }

    if(dp[m][n] !=-1){
        return dp[m][n];
    }

    if(n==0){
        return m;
    }

    //if 1st char are equal find in s1+1, s2+1
    if(s1[0] == s2[0]){
        return find(s1.substr(1), s2.substr(1), m-1, n-1, dp);
    }

    //replace s1[0] with s2[0]
    int op1 = find(s1.substr(1), s2.substr(1), m-1, n-1, dp);
    //delete s1[0] and comapre with s2
    int op2 = find(s1.substr(1), s2, m-1, n, dp);
    //delete s2[0] and compare with s1
    int op3 = find(s1, s2.substr(1), m, n-1, dp);

    //add one to min cuz of 1 operation performed above
    dp[m][n] = 1 + min(op1, min(op2, op3));

    return dp[m][n];
}


int editDistance(string s1, string s2)
{
    int m = s1.size();
    int n = s2.size();

    vector<vector<int>> dp;

    for (int i = 0; i <=m; ++i)
    {
        vector<int> vi(n+1, -1);
        dp.push_back(vi);
    }

    int ans = find(s1, s2,m,n, dp);
    return ans;
}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2) << endl;


    return 0;
}