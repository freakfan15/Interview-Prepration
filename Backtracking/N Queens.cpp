#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std;

bool possible(vector<vector<int>> &board, int row, int col, int &n){
    int i=row, j=col;
    while(i>=0 && j>=0){
        if(board[i--][j--] == 1){
            return false;
        }
    }
    i=row, j=col;
    while(i>=0){
        if(board[i--][col] == 1){
            return false;
        }
    }
    i=row, j=col;
    while(i>=0 && j<n){
        if(board[i--][j++] == 1){
            return false;
        }
    }
    return true;

}

void canPlace(vector<vector<int>> &board, int row, int &n){
    if(row == n){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<board[i][j]<<" ";
            }
        }
        cout<<endl;
        return;
    }

    for(int col=0; col<n; col++){
        if(possible(board, row, col, n) == true){
            board[row][col] = 1;
            canPlace(board, row+1, n);
            board[row][col] = 0;
        }
    }
}

void placeNQueens(int n){

    //make a n*n 2d array intialised with all zeros 
    vector<vector<int>> board(n,vector<int>(n));

    canPlace(board, 0, n);
}


int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
    int n; 
    cin >> n ;
    placeNQueens(n);
    
    return 0;
}