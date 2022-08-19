/*
Given a 9*9 sudoku board, in which some entries are filled and others are 0 (0 indicates that the cell is empty), you need to find out whether the Sudoku puzzle can be solved or not i.e. return true or false.
Input Format :
9 Lines where ith line contains ith row elements separated by space
Output Format :
 true or false
Sample Input :
9 0 0 0 2 0 7 5 0 
6 0 0 0 5 0 0 4 0 
0 2 0 4 0 0 0 1 0 
2 0 8 0 0 0 0 0 0 
0 7 0 5 0 9 0 6 0 
0 0 0 0 0 0 4 0 1 
0 1 0 0 0 5 0 8 0 
0 9 0 0 7 0 0 0 4 
0 8 2 0 4 0 0 0 6
Sample Output :
true
*/

#include<iostream>
using namespace std;

bool isValid(int board[][9], int const &k, int row, int col){
    for(int i=0; i<9; i++){
        if(board[row][i] == k){
            return false;
        }
        if(board[i][col] == k){
            return false;
        }
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == k){
            return false;
        }
    }
    return true;
}


bool sudokuSolver(int board[][9]){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Don't print output and return output as specified in the question
  */
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            
            if(board[i][j] == 0){
                for(int k=1; k<=9; k++){
                    if(isValid(board, k, i, j)){
                        board[i][j] = k;
                        
                        if(sudokuSolver(board) == true){
                            return true;
                        }
                        else{
                            board[i][j] = 0;
                        }
                    }
                }
                return false;
            }
            
        }
    }
    return true;
}


int main(){

  int n = 9; 
  int board[9][9];
  for(int i = 0; i < n ;i++){
    for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }       
  }
  if(sudokuSolver(board)){
    cout << "true"; 
  }else{
    cout << "false";    
  }
}


