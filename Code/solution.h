int max(int arr[], int n) {
    unordered_map<int,int> mp;

    int sum = 0;
    int largest = 0;
    for(int i=0; i<n; i++){
        if(arr[i] ==0){
            sum+=-1;
        }
        else{
            sum+=1;
        }   
        if(sum == 0){
            largest = i+1;
        }
        else if(mp.find(sum)!=mp.end()){
            if(i - mp[sum] > 0 and (i-mp[sum]> largest)){
                largest = i - mp[sum];
            }   
        }
        else{
            mp.insert({sum, i});    
        }
        
    }

    return largest;
}
