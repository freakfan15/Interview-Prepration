#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std;

void generate(vector<int> &subset, int* input, int n){
    if(n==0){
        for(int s: subset){
            cout<<s<<" ";
        }
        cout<<endl;
        return;
    }
    //dont include in subset
    generate(subset, input+1, n-1);
        
    //include in subset
    subset.push_back(input[0]);
    generate(subset, input+1, n-1);
    subset.pop_back();
    
}

void printSubsetsOfArray(int input[], int size) {
    // Write your code here
    vector<int> subset;
    generate(subset, input, size);  
}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
    int input[1000],length;
    cin >> length;
    for(int i=0; i < length; i++)
        cin >> input[i];
    printSubsetsOfArray(input, length);
    
    return 0;
}