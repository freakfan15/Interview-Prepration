#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int helper(string s){
    if(s.length() == 1){
        return (s[0] - '0');
    }
    
    int rightPart = helper(s.substr(1));
    int first = s[0] - '0';
    
    return pow(10, s.length() - 1)*first + rightPart;
}

int stringToNumber(char input[]) {
    // Write your code here 
    std::string s = "";
    
    for(int i=0; input[i]!='\0'; i++){
        s+=input[i];
    }
    
    return helper(s);
}

int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
