#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std;

int getPairsWithDifferenceK(int *arr, int n, int k) {
    unordered_map<int,int> mp;

    int ans = 0;

    for (int i = 0; i < n; ++i)
    {
        int comp = arr[i] - k;
        ans += mp[comp];

        if (k!=0)
        {
            comp = arr[i] + k;
            ans += mp[comp];
        }

        mp[arr[i]]++;
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

    int *input = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}