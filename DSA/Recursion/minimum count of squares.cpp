/*
Given an integer N, find and return the count of minimum numbers, sum of whose squares is equal to N.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. Output will be 1, as 1 is the minimum count of numbers required.
Note : x^y represents x raise to the power y.
Input Format :
Integer N
Output Format :
Required minimum count
Constraints :
1 <= N <= 50
Sample Input 1 :
12
Sample Output 1 :
3
Sample Output 1 Explanation :
12 can be represented as :
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 2^2
1^1 + 1^1 + 1^1 + 1^1 + 2^2 + 2^2
2^2 + 2^2 + 2^2
As we can see, the output should be 3.
Sample Input 2 :
9
Sample Output 2 :
1
*/

#include<iostream>
using namespace std;

int minCount(int n){
    
    if(n<=0){
        return 0;
    }
    
	if(n==1){
        return 1;
    }
    
    int minF = n;
    int ans = minF;
    
    for(int i=1; i<=n; i++){
        if(i*i > n){
            break;
		}
        
        int curr_min = minCount(n - i*i);
        if(curr_min < minF){
        	ans = curr_min;
            minF = ans;
        }
    }
    
    return 1 + ans;
    
}

int main(){

  int num;
  cin >> num;
  cout << minCount(num);

}