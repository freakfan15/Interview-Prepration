//****** https://cses.fi/problemset/task/1619/ *******

#include <bits/stdc++.h>
using namespace std;

int solve(vector<pair<int, int>> times){
	sort(times.begin(), times.end());

	int currCustomers = 0, maxCustomers = 0;
	for(int i=0; i<times.size(); i++){
		if(times[i].second == 1){
			currCustomers++;	
			maxCustomers = max(currCustomers, maxCustomers);
		} 
		else currCustomers--;
	}

	return maxCustomers;
}


int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    int s, e;

    vector<pair<int, int>> times;

    for(int i=0; i<n; i++){
    	cin>>s>>e;
    	times.push_back({s,1});
    	times.push_back({e,-1});
    }

	cout<<solve(times)<<endl;
}