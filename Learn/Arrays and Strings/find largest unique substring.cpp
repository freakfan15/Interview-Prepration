#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

void findLargestUniqueSubstring(char input[], char output[]){
    int mp[256] = {0};

    int s = 0, e = 0;
    int left = 0, right = 0;
    int maxLen = -1;

    while(input[right]!='\0'){
        char c1 = input[right];
        mp[c1] += 1;
        right++;

        while(mp[c1] > 1){
            char c2 = input[left];
            mp[c2] -=1;
            left++;
        }
        if(right - left > maxLen){
            maxLen = right - left;
            s = left; e = right;
        }
    }

    int idx = 0;

    for(int i=s; i<e; i++){
        output[idx] = input[i];
        idx++;
    }
    output[idx] = '\0';
}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

    char input[1000], output[1000];
    cin.getline(input, 1000);
    findLargestUniqueSubstring(input, output);
    cout << output << endl;
}