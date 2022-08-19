#include <iostream>
#define ll long long
using namespace std;

int solve(ll &a, ll &b, ll &c, ll &d){
    ll m = a*d;
    ll n = b*c;

    if(m==n) return 0;

    else if(m==0 || n==0) return 1;

    else if(m%n==0 || n%m==0) return 1;

    else return 2;
}

int main()
{

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;

    while(t--){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<solve(a,b,c,d)<<endl;
    }
    return 0;
}