#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std;

int makeAnagram(char str1[], char str2[]){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */

    unordered_map<int,int> mp;

    for(int i=0; str1[i]!='\0'; i++){
        mp[str1[i]]++;
    }

    for(int i=0; str2[i]!='\0'; i++){
        mp[str2[i]]--;
    }

    int ans = 0;

    for(auto it: mp){
        ans+= abs(it.second);
    }

    return ans;
    
}


int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

    char str1[10010], str2[10010];
    cin>>str1;
    cin>>str2;
    
    cout << makeAnagram(str1,str2) << endl;
    return 0;

}