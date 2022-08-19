/*
Combinational Sum
Send Feedback
Given an array of integers A and an integer B. Find and return all unique combinations in A where the sum of elements is equal to B.
Elements of input array can be repeated any number of times.
One combination should be saved in increasing order. Order of different combinations doesn't matter.
Note : All numbers in input array are positive integers.
Input Format :
Line 1 : Integer n
Line 2 : n integers (separated by space)
Line 3 : Integer B (i.e. sum)
Output Format :
Combinations in different lines
Contraints :
1<= N <=1000
Sample Input 1 :
4
7 2 6 5
16
Sample Output 1 :
2 2 2 2 2 2 2 2 
2 2 2 2 2 6 
2 2 2 5 5 
2 2 5 7 
2 2 6 6 
2 7 7 
5 5 6
Sample Input 2 :
4
2 4 6 8
8
Sample Output 2 :
2 2 2 2 
2 2 4 
2 6 
4 4 
8 
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std;

void combinationSum(vector<int>& ar, int sum, int i, vector<int> &comb, vector<vector<int>> &res){
    if(i == ar.size()){
        if(sum == 0){
            res.push_back(comb);
        }
        return;
    }
    if(ar[i] <=sum){
        comb.push_back(ar[i]);
        combinationSum(ar, sum - ar[i], i, comb, res);
        comb.pop_back();   
    }
    combinationSum(ar, sum, i+1, comb, res);
}

vector<vector<int> > combinationSum(vector<int>& ar, int sum){
    vector<vector<int>> res;
    vector<int> comb;
    sort(ar.begin(), ar.end());

    vector<int> temp;
    for(int i=0; i<ar.size();){
        temp.push_back(ar[i]);
        int j = i+1;
        while(j<ar.size() && ar[j] == ar[i]){
            j++;
        }
        i=j;
    }

    int idx = 0;

    combinationSum(temp, sum, idx, comb, res);
    return res;
}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
    int n;
    cin >> n;
    int x;
    vector<int> ar;
    for(int i = 0; i < n; i++){
        cin >> x;
        ar.push_back(x);
    }
    int sum;
    cin >> sum;
    vector<vector<int> > res = combinationSum(ar, sum);
    if (res.size() == 0) {
        cout << "Empty";
        return 0;
    }
    for (int i = 0; i < res.size(); i++) {
        if (res[i].size() > 0) {
            for (int j = 0; j < res[i].size(); j++)
                cout << res[i][j] << " ";
            cout << endl;
        }
    }
}