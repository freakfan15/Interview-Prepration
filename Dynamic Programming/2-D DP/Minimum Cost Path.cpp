#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std;

//iterative method
int min_cost2(int** input, int m, int n) {
    int ** dp = new int*[m];
    for (int i = 0; i < m; i++) {
        dp[i] = new int[n];
    }

    //going from dp[m-1][n-1] to dp[m-1][n-1] will take cost input[m-1][n-1]
    dp[m - 1][n-1] = input[m-1][n-1];
    //fill up the last col by cumm sum as in last col u can only go down
    for (int i = m - 2; i >= 0; i--) {
        dp[i][n -1] = dp[i + 1][n-1] + input[i][n-1];
    }

    //fill up the last row by cumm sum as in last row u can only go right
    for (int j = n - 2; j >=0; j--) {
        dp[m -1][j] = dp[m - 1][j + 1] + input[m-1][j];
    }

    for (int i = m - 2; i >=0; i--) {
        for (int j = n - 2; j >=0 ; j--) {
            dp[i][j] = input[i][j] + min(dp[i+1][j], min(dp[i+1][j+1], dp[i][j + 1]));
        }
    }

    int ans = dp[0][0];

    for(int i=0; i<m; i++){
        delete [] dp[i];
    }

    delete [] dp;

    return ans;
}

//recursive
int min_cost(int** input, int si, int sj, int ei, int ej, vector<vector<int>> &dp) {
    if (si == ei && sj == ej) {
        return input[ei][ej];
    }
    if (si > ei || sj > ej) {
        return INT_MAX;
    }

    if(dp[si][sj] !=-1){
        return dp[si][sj];
    }
    int option1 = min_cost(input, si + 1, sj, ei, ej, dp);
    int option2 = min_cost(input, si + 1, sj + 1, ei, ej, dp);
    int option3 = min_cost(input, si, sj + 1, ei, ej, dp);

    int ans = input[si][sj] + min(option1, min(option2, option3));    
    dp[si][sj] = ans;
    return ans;
}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

    int ** input = new int*[3];
    input[0] = new int[3];
    input[1] = new int[3];
    input[2] = new int[3];
    input[0][0] = 4;
    input[0][1] = 3;
    input[0][2] = 2;
    input[1][0] = 1;
    input[1][1] = 8;
    input[1][2] = 3;
    input[2][0] = 1;
    input[2][1] = 1;
    input[2][2] = 8;

    vector<vector<int>> dp;
    for(int i=0; i<3; i++){
        vector<int> vi(3, -1);
        dp.push_back(vi);
    }

    cout << min_cost(input, 0,0,2,2,dp) << endl;
    cout << min_cost2(input,3,3) << endl;
    delete [] input[0];
    delete [] input[1];
    delete [] input[2];
    delete [] input;


    return 0;
}