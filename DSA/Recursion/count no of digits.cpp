#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
  
    cout << count(n) << endl;
}
int count(int n){
    
    if(n==0){
        return 0;
    }
    
    int so = count(n/10);
    return 1 + so;
}


