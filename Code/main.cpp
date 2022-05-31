#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std;
#include "Solution.h"

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

    char str1[10010], str2[10010];
    cin>>str1;
    cin>>str2;
    
    cout << makeAnagram(str1,str2) << endl;
    return 0;

}