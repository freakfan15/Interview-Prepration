#include <iostream>
#include <cstring>
using namespace std;

string getCompressedString(string &input) {
    // Write your code here.

    string ans = "";
    int cnt = 1;
    for(int i=0; input[i]!='\0'; i++){
        ans += input[i];
        while(input[i+1] != '\0' && (input[i+1] == input[i])){
            cnt++;
            i++;
        }

        if(cnt!=1){
            ans += to_string(cnt);
            cnt = 1;
        }
    }

    return ans;
    
}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

    int size = 1e6;
    string str;
    getline(cin, str);
    str = getCompressedString(str);
    cout << str << endl;


    return 0;
}