#include <iostream>
#include <cstring>
using namespace std;

bool isPermutation(char input1[], char input2[]) {

    int freq[256] = {0};

    int n = strlen(input1);
    int m = strlen(input2);

    if(n!=m) return false;

    for(int i=0; i<n; i++){
        freq[input1[i]]++;
    }
    for(int i=0; i<m; i++){
        freq[input2[i]]--;
    }

    for(int i=0; i<256; i++){
        if(freq[i] != 0){
            return false;
        }
    }

    return true;

}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
    int size = 1e6;
    char str1[size];
    char str2[size];
    cin >> str1 >> str2;
    cout << (isPermutation(str1, str2) ? "true" : "false");


    return 0;
}