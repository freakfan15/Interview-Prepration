#include <iostream>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t;
    cin >> t;
    int count = 0;
    while (t--)
    {
        string s;
        cin>>s;
        if(s.compare("X++")==0 || s.compare("++X")==0){
            count++;
        }
        else{
            count--;
        }
    }
    cout<<count;
    return 0;
}