#include <iostream>
using namespace std;

int main()
{

	#ifndef ONLINE_JUDGE
	freopen("rin.txt","r",stdin);
	freopen("rout.txt","w",stdout);
	#endif

    int size = 1e6;
    char str1[size];
    char str2[size];
    cin >> str1 >> str2;
    cout << (isPermutation(str1, str2) ? "true" : "false");

	return 0;
}