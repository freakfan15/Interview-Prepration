#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std;

vector<vector<int>> subsets;
void generate(vector<int> &subset, int* input, int n){
    if(n==0){
        subsets.push_back(subset);
        return;
    }
    //dont include in subset
    generate(subset, input+1, n-1);
        
    //include in subset
    subset.push_back(input[0]);
    generate(subset, input+1, n-1);
    subset.pop_back();
    
}

int subset(int input[], int n, int output[][20]) {
    // Write your code here
    vector<int> subset;
    generate(subset, input, n);
    
    int length = subsets.size();
    
    for(int i=0; i<length; i++){
        for(int j=0; j<subsets[i].size(); j++){
            // output[i][j] = subsets[i][j];
            cout<<subsets[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return length;
    
}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
    int input[20],length, output[35000][20];
    cin >> length;
    for(int i=0; i < length; i++)
    cin >> input[i];
  
    int size = subset(input, length, output);

    for( int i = 0; i < size; i++) { 
        for( int j = 1; j <= output[i][0]; j++) { 
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}