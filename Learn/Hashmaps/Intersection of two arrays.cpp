#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std;

void intersection(int *arr1, int *arr2, int n, int m) 
{
    //Write your code here
    unordered_map<int,int> mp;
    for(int i=0; i<m; i++){
        mp[arr2[i]]++;
    }

    sort(arr1, arr1+n);

    for(int i=0; i<n; i++){
        if(mp[arr1[i]] > 0){
            cout<<arr1[i]<<" ";
            mp[arr1[i]]--;

        }

    }

}

int main()
{

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int t;
	cin >> t;
	while (t--)
	{

		int size1, size2;

		cin >> size1;
		int *input1 = new int[size1];

		for (int i = 0; i < size1; i++)
		{
			cin >> input1[i];
		}

		cin >> size2;
		int *input2 = new int[size2];

		for (int i = 0; i < size2; i++)
		{
			cin >> input2[i];
		}

		intersection(input1, input2, size1, size2);
		
		delete[] input1;
		delete[] input2;
		
		cout << endl;
	}

	return 0;
}