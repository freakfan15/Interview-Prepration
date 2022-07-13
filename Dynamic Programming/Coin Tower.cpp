/*
Whis and Beerus are playing a new game today. They form a tower of N coins and make a move in alternate turns. Beerus plays first. In one step, the player can remove either 1, X, or Y coins from the tower. The person to make the last move wins the game. Can you find out who wins the game?
 Input format :
The first and the only line of input contains three integer values separated by a single space. They denote the value of N, X and Y, respectively.
Output format :
Prints the name of the winner, either 'Whis' or 'Beerus' (Without the quotes).
Constraints :
1 <= N <= 10 ^ 6
2 <= X <= Y<= 50

Time Limit: 1 sec
Sample Input 1 :
4 2 3
Sample Output 1 :
Whis
Sample Input 2 :
10 2 4
Sample Output 2 :
Beerus
Explanation to Sample Input 1:
Initially, there are 4 coins,  In the first move, Beerus can remove either 1, 2, or 3 coins in all three cases, Whis can win by removing all the remaining coins.
*/

#include <iostream>
#include <string>
using namespace std;

bool find(int n, int x, int y, int* dp){
    if(n==1 or n==x or n==y){
        return true;
    }
    
    if(dp[n]!=-1){
        return (dp[n] == 1)?true:false;
    }
    
    //check if b looses or wins
    //if b looses A wins and vice versa
    //for A to loose B has to win in all cases
    //for A to win B has to loose in only 1 case
    //cause A plays first
    //so loose(false)^1 = 1(win)
    // win(true)^1 = 0(loose)
    // xor with 1 gives us result of that case for A
    //we take max to find out if any case 1 comes A wins.

    int a = find(n-1, x, y, dp)^1;
    int b = 0, c = 0;
    if(n-x>=1){
    	b = find(n-x, x, y, dp)^1;    
    }
    if(n-y>=1){
    	c = find(n-y, x, y, dp)^1;   
	}
    
    int ans = max(a, max(b,c));
    
    dp[n] = ans;
    
    return (ans == 1)?true:false;
    
}

string findWinner(int n, int x, int y)
{
    
    int* dp = new int[n+1];
    
    for(int i=0; i<=n; i++){
    	dp[i] = -1;
    }
    
    if(find(n, x, y, dp) == true){
        return "Beerus";
    } 
    else{
        return "Whis";
	}
	
}

int main()
{
	int n, x, y;
	cin >> n >> x >> y;
	cout << findWinner(n, x, y);
}