/*
Alice and Bob need to send secret messages to each other and are discussing ways to encode their messages:
Alice: “Let’s just use a very simple code: We’ll assign ‘A’ the code word 1, ‘B’ will be 2, and so on down to ‘Z’ being assigned 26.”

Bob: “That’s a stupid code, Alice. Suppose I send you the word ‘BEAN’ encoded as 25114. You could decode that in many different ways!”

Alice: “Sure you could, but what words would you get? Other than ‘BEAN’, you’d get ‘BEAAD’, ‘YAAD’, ‘YAN’, ‘YKD’ and ‘BEKD’. I think you would be able to figure out the correct decoding. And why would you send me the word ‘BEAN’ anyway?”

Bob: “OK, maybe that’s a bad example, but I bet you that if you got a string of length 5000 there would be tons of different decodings and with that many you would find at least two different ones that would make sense.”

Alice: “How many different decodings?”

Bob: “Jillions!”
For some reason, Alice is still unconvinced by Bob’s argument, so she requires a program that will determine how many decodings there can be for a given string using her code.
Input
Input will consist of multiple input sets. Each set will consist of a single line of at most 5000 digits representing a valid encryption (for example, no line will begin with a 0). There will be no spaces between the digits. An input line of ‘0’ will terminate the input and should not be processed.
Output
For each input set, output the number of possible decodings for the input string. Print your answer taking modulo "10^9+7"
Sample Input:
25114
1111111111
3333333333
0
Sample Output:
6
89
1
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std;

int number(string s){
    if(s.size() == 1){
         return 1;
    }
    if(s.size() == 0){
        return 1;
    }   

    int ways = number(s.substr(1));
    int asci = ((s[0]-'0')*10 + (s[1] - '0'));
    if(asci<=26){
        ways+=number(s.substr(2));
    }

    return ways;
}

int num_codes(vector<int> &v, int size) {
    for(int it: v){
        cout<<it<<" ";
    }
     if (size == 1) {
         return 1;
     }
     if (size == 0) {
         return 1;
     }
     int output = num_codes(v, size - 1);
    if (v[size - 2] * 10 + v[size - 1] <= 26) {
        cout<<size<<endl;
        cout<<(v[size - 2] * 10 + v[size - 1])<<endl;
         output += num_codes(v, size -2);
     } 
}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
    // string s;
    // cin>>s;
    // int i=0;
    // while(s!="0"){
    //   cout<<number(s)<<endl;
    //   cin>>s;
    // }
    int n;
    cin>>n;
    while(n!=0){
        vector<int> v;
        while(n>0){
            v.push_back(n%10);
            n = n/10;
        }
        reverse(v.begin(), v.end());
        cout<<num_codes(v,v.size())<<endl;
        cin>>n;
    }

    return 0;
}