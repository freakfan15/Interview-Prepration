#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cusSort(const pair<int,int> &a, const pair<int,int> &b){
	return a.second < b.second;
}


int main(int argc, char const *argv[])
{

	vector<pair<int,int>> v;

	int n,m,k;
	cin>>n>>m>>k;

	while(n){
		int ai, bi;
		cin>>ai>>bi;
		v.push_back(make_pair(ai,bi));
	}

	sort(v.begin(), v.end(), cusSort);

	for(auto a:v){
		cout<<a.first<<" "<<a.second<<endl;
	}
	
	return 0;
}