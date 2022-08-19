#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std;

bool hasPathHelper(int** arr, int n, int** solution, int x, int y){

    if(x == n-1 && y==n-1){
        return true;
    }

    if(x<0 || y<0 || x>=n || y>=n || arr[x][y]==0 || solution[x][y]==1){
        return false;
    }

    //mark x, y as visited
    solution[x][y] = 1;

    if(hasPathHelper(arr, n, solution, x-1, y)){
        return true;
    }
    if(hasPathHelper(arr, n, solution, x, y-1)){
        return true;
    }
    if(hasPathHelper(arr, n, solution, x+1, y)){
        return true;
    }
    if(hasPathHelper(arr, n, solution, x, y+1)){
        return true;
    }

    //since no path exits, mark x, y as not visited
    solution[x][y] = 0;

    return false;
}

bool hasPath(int** arr, int n){
    int** solution = new int*[n];
    for(int i=0; i<n; i++){
        solution[i] = new int[n];
        for(int j=0; j<n; j++){
            solution[i][j] = 0;
        }
    }

    return hasPathHelper(arr, n, solution, 0, 0);
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

    cout<<hasPath(arr, n)<<endl;

    return 0;
}