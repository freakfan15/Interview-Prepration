/*
Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.

Constraints :
1 <= n <= 10^6

Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf

*/

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std;

void helper(int num, string output){
   if(num == 0 || num == 1){
        cout<<output<<endl;
        return;
    }

    int n = num%10;
    string input;
    
    switch(n){
        case 2: input = "abc";
        break;
        case 3: input = "def";
        break;
        case 4: input = "ghi";
        break;
        case 5: input = "jkl";
        break;
        case 6: input = "mno";
        break;
        case 7: input = "pqrs";
        break;
        case 8: input = "tuv";
        break;
        case 9: input = "wxyz";
        break;
    }


    for(int i=0; i<input.size(); i++){
        helper(num/10, input[i] + output);
    } 
}

void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */

    helper(num, "");
}


int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
    int num;
    cin >> num;

    printKeypad(num);
    return 0;
}