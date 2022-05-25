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