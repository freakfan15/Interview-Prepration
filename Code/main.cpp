#include <iostream>
using namespace std;

#include "solution.h"

int main()
{

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int *a,*b,m,n,i;
    cin>>m;
    a=new int[m];
    for(i=0;i<m;i++)
        cin>>a[i];
    cin>>n;
    b=new int[n];
    for(i=0;i<n;i++)
        cin>>b[i];
    long ans = maxPathSum(a,b,m, n);
    cout << ans << endl;
    delete a;
    delete b;
    return 0;
}