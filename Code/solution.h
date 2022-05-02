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

    cout<<ans.size()<<endl;

    for(int i= ans.size() - 1; i>=0; i--){
        cout<<ans[i]<<" ";
    }
}