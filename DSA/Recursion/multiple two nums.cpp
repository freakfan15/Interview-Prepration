#include <iostream>
using namespace std;

int multiplyNumbers(int m, int n) {
    // Write your code here
    if(m == 0 || n==0){
        return 0;
    }
    
    int smAns = multiplyNumbers(m, n-1);
    return m + smAns;
}

int main() {
    int m, n;
    cin >> m >> n;
    cout << multiplyNumbers(m, n) << endl;
}
