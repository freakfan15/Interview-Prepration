#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std;

int findSum(int arr[],int n){
    int sum = 0;
    int maxi = arr[0];

    for(int i=0; i<n; i++){
        sum+=arr[i];
        maxi = max(maxi, sum);
        if(sum<0){
            sum = 0;
        }
    }

    return maxi;
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    cout<<findSum(arr,n);
    return 0;
}