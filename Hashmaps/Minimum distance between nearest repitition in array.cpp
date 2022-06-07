//Given an integer array, find and return the minimum distance 
// between indexes of an element and its repetition.

//6
//1 3 1 5 4 3
// output = 2

int minDistance(int arr[],int n){
    unordered_map<int,pair<int,int>> mp;

    int minD = 1e7;
    for(int i=0; i<n; i++){
        int c = arr[i];
        if(mp.find(c)!=mp.end()){
            mp[c].second = i;
            minD = min((mp[c].second - mp[c].first), minD);
            mp[c].first=i;
            
        }
        else{
            mp.insert({c, {i, 0}});
        }
    }



    return minD;

}