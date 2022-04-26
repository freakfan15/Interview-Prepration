#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;
#include "Solution.h"

int main() {

vector<int> v(4,12);
v.push_back(15);
cout << v.size() <<" " <<v.capacity() << " ";
v.push_back(25);
cout << v.size() <<" " << v.capacity();

	// #ifndef ONLINE_JUDGE
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	// #endif

 //    int n;
 //    cin >> n;
    
 //    int **input = new int*[n];
    
 //    for(int i = 0; i < n; i++) {
 //        input[i] = new int[n];
 //        for(int j = 0; j < n; j++) {
 //            cin >> input[i][j];
 //        }
 //    }
    
 //    rotate(input, n);
    
 //    for(int i = 0; i < n; i++) {
 //        for(int j = 0; j < n; j++) {
 //            cout << input[i][j] << " ";
 //        }
 //        cout << endl;
 //    }


    return 0;
}