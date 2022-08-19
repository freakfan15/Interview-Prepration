#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

void reverseStringWordWise(char input[]) {
    int e = 0;
    for(int i=0; input[i]!='\0'; i++){
        e++;
    }
    int end = e - 1;

    int start = 0;

    while(start<end){
        swap(input[start++], input[end--]);
    }

    int s = 0;
    int i=0, j=0;

    while(s<=e){
        if(input[s] == ' ' || input[s]=='\0'){
            j = s - 1;
            while(i<j){
                swap(input[i++], input[j--]);
            }
            i = s + 1;
        }

        s++;
    }
}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	char input[1000];
    cin.getline(input, 1000);
    reverseStringWordWise(input);
    cout << input << endl;
}