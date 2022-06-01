#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std;
#include "Solution.h"

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

    int n=0;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }
    
    cout << max(arr,n);
    return 0;

}