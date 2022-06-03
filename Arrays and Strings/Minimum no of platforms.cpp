#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int platformsNeeded(int arrival[], int departure[], int n) {

    int need[n] = {0};

    int ans = 0;
    for(int i=0; i<n; i++){
        int j=0;
        while(j<ans){
            if((arrival[i] > need[j]) || (arrival[i]<1200 && arrival[i-1] > 1200 && need[j]>1200)){
                need[j] = departure[i];
                break;
            }
            j++;
        }
        if(j==ans){
            need[j] = departure[i];
            ans++;
        }
        else{
            j++;
            while(j<ans){
                need[j] = 0;
                j++;
            }
        }
        
    }

    return ans;
}
// i=0: 0315 0 0 0 0 ans = 1
// i=1: 2338 0 0 0 0 ans = 1
// i=2: 2359 0 0 0 0 ans = 1
// i=3:


int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

    int n;
	cin>>n;
    int* arr=new int[n];
    int* dep=new int[n];
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
	}
	for(int i=0;i<n;i++)
    {
    	cin>>dep[i];
	}
    cout<< platformsNeeded(arr, dep, n);

    return 0;
}