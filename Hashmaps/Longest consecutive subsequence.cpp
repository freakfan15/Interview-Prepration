#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    unordered_set<int> s;
    vector<int> v;

    for(int i=0; i<n; i++){
        s.insert(arr[i]);
    }

    int maxLen = 0;
    int st, e;
    for(int i=0; i<n; i++){
        int currLen = 1;
        int curr = arr[i];
        while(s.find(curr+1)!=s.end()){
            currLen++;
            curr++;
        }
        if(currLen > maxLen){
            maxLen = currLen;
            e = curr--;
            st = e - maxLen + 1;
        }
    }
    if(st!=e){
        v.push_back(st);
        v.push_back(e);
    } else{
        v.push_back(st);
    }

    return v;
}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    for (auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << " ";

    delete[] arr;
}