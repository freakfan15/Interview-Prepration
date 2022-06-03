#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std;

int max(int arr[], int n) {
    unordered_map<int,int> mp;

    int sum = 0;
    int largest = 0;
    for(int i=0; i<n; i++){
        if(arr[i] ==0){
            sum+=-1;
        }
        else{
            sum+=1;
        }   
        if(sum == 0){
            largest = i+1;
        }
        else if(mp.find(sum)!=mp.end()){
            if(i - mp[sum] > 0 and (i-mp[sum]> largest)){
                largest = i - mp[sum];
            }   
        }
        else{
            mp.insert({sum, i});    
        }
        
    }

    return largest;
}


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