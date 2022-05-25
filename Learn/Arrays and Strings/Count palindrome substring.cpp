#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

bool isPalindrome(char ch[], int s, int e){
    // cout<<ch[s]<<endl;
    while(s<e){
        // cout<<ch[s]<<" "<<ch[e]<<endl;
        if(ch[s]!=ch[e]){
            return false;
        }
        s++; e--;
    }
    return true;
}

int countPalindromeSubstrings(char s[]) {
    int ans = 0;
    int len = 0;

    for(int i=0; s[i]!='\0'; i++){
        len++;
        for(int j=i+1; s[j]!='\0'; j++){
            if(isPalindrome(s, i, j)){
                // cout<<i<<" "<<j<<endl;
                ans++;
            }
        }
    }
    return ans+len;
}


int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
    char input[10000];
    cin >> input;
    cout << countPalindromeSubstrings(input) << endl;
  
}