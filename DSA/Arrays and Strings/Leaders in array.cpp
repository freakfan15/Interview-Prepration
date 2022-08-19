#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

void Leaders(int* arr,int len)
{
    int maxVal = arr[len - 1];
    vector<int> ans;

    int ansSize = 0;
    for(int i=len-1; i>=0; i--){
        if(arr[i] >= maxVal){
            ans.push_back(arr[i]);
            maxVal = arr[i];
        }
    }

    for(int i= ans.size() - 1; i>=0; i--){
        cout<<ans[i]<<" ";
    }
}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

    int len;
    cin>>len;
	int *arr = new int[len + 1];
	
	for(int i=0;i<len;i++)
	{
		cin>>arr[i];
	}
	Leaders(arr,len);
}