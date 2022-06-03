#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std;

int highestFrequency(int arr[], int n) {
    // Write your code here
    unordered_map<int, int> mp;

    for(int i=0; i<n; i++){
        mp[arr[i]]++;
    }

    // for(auto it: mp){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }

    pair<int, int> p = {-1,0};
    for(int i=0; i<n; i++){
        if(mp[arr[i]] > p.second){
            p.first = arr[i];
            p.second = mp[arr[i]];
        }
    }

    return p.first;
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
     int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;
}
