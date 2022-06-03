#include <iostream>
#include <cstring>
using namespace std;

long maxPathSum(int ar1[], int ar2[], int m, int n)
{
    int i=0, j=0;
    long s1 =0, s2 = 0;
    long max_sum = 0;
    while(i<m and j<n){
        if(ar1[i] < ar2[j]){
            s1+=ar1[i++];
        }
        else if(ar1[i] > ar2[j]){
            s2+=ar2[j++];
        }
        else{
            s1+=ar1[i++];
            s2+=ar2[j++];
            max_sum += max(s1, s2);
            s1 = 0; s2 = 0;
        }
    }

    while (i < m)
    {
        s1 += ar1[i++];
    }
    while (j < n)
    {
        s2 += ar2[j++];
    }
    max_sum += max(s1, s2);

    return max_sum;       
}

int main() {

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