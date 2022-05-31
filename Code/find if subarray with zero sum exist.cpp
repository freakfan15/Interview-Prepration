#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std;

bool subArrayZeroSum(int input[], int n) {
    unordered_set<int> s;

    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum +=input[i];
        if (sum == 0 || s.find(sum)!=s.end())
        {
            return true;
        }

        s.insert(sum);
    }    
    return false;      
}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

    int n;
    int input[100000];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>input[i];
    }
    bool val = subArrayZeroSum(input, n);
    if(val)
    {
        cout<<"true";
    }
    else
    {
            cout<<"false";
    }
    return 0;

}