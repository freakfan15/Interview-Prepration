#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std;

void printAllPathsHelper(int** arr, int n, int** solution, int x, int y){

    if(x == n-1 && y==n-1){
        solution[x][y] = 1;
        for(int i=0; i<n; i++){
            for (int j = 0; j < n; j++)
            {
                cout<<solution[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }

    if(x<0 || y<0 || x>=n || y>=n || arr[x][y]==0 || solution[x][y]==1){
        return;
    }

    //mark x, y as visited
    solution[x][y] = 1;

    printAllPathsHelper(arr, n, solution, x-1, y);
    printAllPathsHelper(arr, n, solution, x, y-1);
    printAllPathsHelper(arr, n, solution, x+1, y);
    printAllPathsHelper(arr, n, solution, x, y+1);

    solution[x][y] = 0;
    return;  
}

void printAllPaths(int** arr, int n){
    int** solution = new int*[n];
    for(int i=0; i<n; i++){
        solution[i] = new int[n];
        for(int j=0; j<n; j++){
            solution[i][j] = 0;
        }
    }

    printAllPathsHelper(arr, n, solution, 0, 0);
}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	

    int n;
    cin>>n;
    int** arr = new int*[n];

    for(int i=0; i<n; i++){
        arr[i] = new int[n];
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    cout<<printAllPaths(arr, n)<<endl;

    return 0;
}