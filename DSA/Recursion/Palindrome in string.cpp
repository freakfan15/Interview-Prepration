#include <iostream>
using namespace std;

bool helper(char input[], int s, int e){
    if(s == e || e == -1){
        return true;
    }
    
    if(input[s] != input[e]){
        return false;
    }
    
    return helper(input, s+1, e-1);
}

bool checkPalindrome(char input[]) {
    
    int n = 0;
    for(int i=0; input[i]!='\0'; i++){
        n++;
    }
    
    return helper(input, 0, n-1);
        
}

int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
