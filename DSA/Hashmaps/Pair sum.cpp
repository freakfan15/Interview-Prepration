#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std;

int pairSum(int *arr, int n) {
    // Write your code here
    unordered_map<int,int> mp;

    for(int i=0; i<n; i++){
        mp[arr[i]]++;
    }

    int ans = 0;

    for(int i=0; i<n; i++){
        int x = -arr[i];
        if(x == arr[i]){
            if(mp[x] > 0)
            {
                ans+=mp[x] - 1;
                mp[arr[i]]--;
            }
        }

        else if(mp[x] > 0){
            ans+=mp[x];
            mp[arr[i]]--;
        }
    }

    return ans;
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

    cout << pairSum(arr, n);

    delete[] arr;
}