//****** https://cses.fi/problemset/task/1091 *************

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef multiset<int> msi;
#define pb push_back

void solve(msi ticketPrice, vi maxPrice){
	for(int i=0; i<maxPrice.size(); i++){
		auto it = ticketPrice.upper_bound(maxPrice[i]);
		if(it==ticketPrice.begin() && (*it)!=maxPrice[i]){
			cout<<-1<<endl;
			continue;
		}
		if(it!=ticketPrice.begin()){
			it = --it;
		}
		if(it==ticketPrice.end()){
			cout<<-1<<endl;
		}
		else{
			cout<<(*(it))<<endl;
			ticketPrice.erase(it);
		}
	}
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    msi ticketPrice;
    vi maxPrice;

    int n, m;
    cin>>n>>m;

    for(int i=0; i<n; i++){
    	int x;
    	cin>>x;
    	ticketPrice.insert(x);
    }

    for(int i=0; i<m; i++){
    	int x;
    	cin>>x;
    	maxPrice.pb(x);
    }

    solve(ticketPrice, maxPrice);
}