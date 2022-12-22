//********** https://cses.fi/problemset/task/1643/ ************

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
typedef vector<int> vi;
typedef multiset<int> msi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

ll solve(vi v){
	ll currSum = 0, maxSum = -1e9;

	for(unsigned int i=0; i<v.size(); i++){
		currSum+=(v[i]);
		if(currSum > maxSum) maxSum = currSum;
		if(currSum < 0) currSum = 0;
	}
	return maxSum;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    vi v;
    int n; cin>>n;

    while(n--){
    	int x; cin>>x;
    	v.pb(x);
    }

    cout<<solve(v);
}