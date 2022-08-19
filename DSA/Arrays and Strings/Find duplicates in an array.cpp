#include <iostream>
#include<unordered_set>
using namespace std;

int findDuplicate(int *arr, int n)
{
    unordered_set<int> s;
    //Write your code here
	for(int i=0; i<n; i++){
        if(s.find(arr[i])!=s.end()){
            return arr[i];
		}
        s.insert(arr[i]);
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
		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << findDuplicate(input, size) << endl;
	}

	return 0;
}