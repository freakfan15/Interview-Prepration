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