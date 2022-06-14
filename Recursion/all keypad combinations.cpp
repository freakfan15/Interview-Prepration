/*
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.

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

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    
    if(num==0 || num == 1){
        output[0] = "";
        return 1;
    }
    
    int smallOutSize = keypad(num/10, output);
    string input;

    int n = num%10;

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

    string* temp = new string[smallOutSize];
    for(int i=0; i<smallOutSize; i++){
        temp[i] = output[i];
    }

    for(int i=0; i<input.size(); i++){
        for(int j=0; j<smallOutSize; j++){
            output[(i)*smallOutSize + j] = temp[j] + input[j];
        }
    }

    return (input.size())*smallOutSize;
}


int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}