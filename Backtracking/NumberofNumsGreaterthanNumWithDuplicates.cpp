#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std;

long solve(int* input, int n, int* freq, int* fact){
    if(n==0 or n==1){
        return 0;
    }

    long den = 1;
    for(int i=0; i<10; i++){
        if(freq[i]>0){
            den = den*fact[freq[i]];
        }
    }
    
    long ans = 0;
    for(int i=input[0] + 1; i<10; i++){
        if(freq[i]>0){
            ans += fact[n-1]*freq[i]/den;
            // cout<<n<<" "<<den<<" "<<ans<<endl;
        }
    }
    // ans = (ans/den)*freq[input[0]];

    freq[input[0]]--;

    ans += solve(input+1, n-1, freq, fact);

    return ans;
}

long numberOfNumbersWithDuplicates(long num){

    std::vector<int> v;

    int n=0;
    while(num>0){
        v.push_back(num%10);
        num = num/10;
        n++;
    }

    reverse(v.begin(), v.end());

    int *input = new int[v.size()];

    for(int i=0; i<n; i++){
        input[i] = v[i];
    }

    int fact[10] = {0};
    int freq[10] = {0};

    for(int i=0; i<n; i++){
        freq[v[i]]++;
    }

    fact[0] = 1;
    for(int i=0; i<9; i++){
        fact[i+1] = (i+1)*fact[i];
    }

    return solve(input, n, freq, fact);

}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	

    long n;
    cin >> n;
    cout << numberOfNumbersWithDuplicates(n) << endl;

    return 0;
}