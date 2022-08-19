#include <iostream>
#include <cstring>
using namespace std;

void reverseEachWord(char input[]) {
    int s = 0;
    for(int i=0; input[i]!='\0'; i++){
        if(input[i+1] == ' ' or input[i+1] == '\0'){
            int e = i;
            while(s<e){
                swap(input[s], input[e]);
                s++; e--;
            }
            s = i + 2; 
        }
    }
}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
    int size = 1e6;
    char str[size];
    cin.getline(str, size);
    reverseEachWord(str);
    cout << str;


    return 0;
}