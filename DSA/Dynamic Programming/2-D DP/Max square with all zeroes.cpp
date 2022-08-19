#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std;

int findMaxSquareWithAllZeros(int **arr, int n, int m)
{
    int** dp = new int*[n];
    for(int i=0; i<n; i++){
        dp[i] = new int[m];
    }

    for(int i=0; i<m; i++){
        dp[0][i] = (arr[0][i]==0?1:0);
    }

    for(int i=0; i<n; i++){
        dp[i][0] = (arr[i][0]==0?1:0);
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]==1){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
            }
        }
    }

    int largest = INT_MIN;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            largest = max(largest, dp[i][j]);
        }
    }

    return largest;
}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

    int **arr, n, m, i, j;
    cin >> n >> m;
    arr = new int *[n];
    
    for (i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << findMaxSquareWithAllZeros(arr, n, m) << endl;

    delete[] arr;


    return 0;
}