/*
Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".
Constraints :
1 <= |S| <= 50
where |S| represents the length of string S. 
Sample Input 1 :
xpix
Sample Output :
x3.14x
Sample Input 2 :
pipi
Sample Output :
3.143.14
Sample Input 3 :
pip
Sample Output :
3.14p
Constraints:-
1<=|S|<=50
*/


#include <iostream>
using namespace std;

// Change in the given string itself. So no need to return or print anything

void replacePi(char input[]) {
    // Write your code here
    if(input[1] == '\0'){
        return;
    }
    
    replacePi(input+1);
    if(input[0] == 'p' && input[1] == 'i'){
        int n = 0;
        for(int i=0; input[i]!='\0'; i++){
            n++;
        }
        for(int i = n - 1 ; i>=2; i--){
            input[i+2] = input[i];
        }
        input[n+2] = '\0';
        
        input[0] = '3'; input[1] = '.'; input[2] = '1'; input[3] = '4';
    }
    return;
}

int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
