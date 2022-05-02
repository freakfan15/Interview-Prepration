int platformsNeeded(int arrival[], int departure[], int n) {

    int need[n] = {0};

    int ans = 0;
    for(int i=0; i<n; i++){
        int j=0;
        while(j<ans){
            if((arrival[i] > need[j]) || (arrival[i]<1200 && arrival[i-1] > 1200 && need[j]>1200)){
                need[j] = departure[i];
                break;
            }
            j++;
        }
        if(j==ans){
            need[j] = departure[i];
            ans++;
        }
        else{
            j++;
            while(j<ans){
                need[j] = 0;
                j++;
            }
        }
        
    }

    return ans;
}
// i=0: 0315 0 0 0 0 ans = 1
// i=1: 2338 0 0 0 0 ans = 1
// i=2: 2359 0 0 0 0 ans = 1
// i=3:

