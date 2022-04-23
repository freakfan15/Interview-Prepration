#include<unordered_set>
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