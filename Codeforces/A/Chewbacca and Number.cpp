#include <iostream>
#define ll long long
using namespace std;

string solve(string s){
    int f = s[0] - '0';
    if(f!=9 && f>4){
        s[0] = (9-f) + '0';
    }

    for(int i=1; i<s.length(); i++){
        int a = s[i] - '0';
        if(a>4){
            s[i] = (9 - a) + '0';
        }
    }

    return s;
}

int main()
{

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    string s;
    cin>>s;

    cout<<solve(s);

    return 0;
}