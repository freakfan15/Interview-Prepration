#include <iostream>
using namespace std;

void sort012(int *arr, int n)
{
    //Write your code here
    int zero = 0;
    int one = 0;
    
    for(int i=0; i<n; i++){
        if(arr[i] == 0){
            zero++;
        }
        else if(arr[i] == 1){
            one++;
        }
    }
    
    cout<< zero <<" "<<one<<endl;
    
    int i=0, cnt = 0;
    while(cnt<zero){
        arr[i] = 0; 
        i++; cnt++;
    }
    cnt = 0;
    while(cnt<one){
        arr[i] = 1; i++; cnt ++;
    }
    cnt = 0;
    while(cnt< n - (zero + one) ){
        arr[i] = 2; i++; cnt ++;
    }
}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

    int t;
	cin >> t;
	while (t--)
	{
		int size;

		cin >> size;
		int *arr = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];
		}

		sort012(arr, size);

		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}

		delete[] arr;
		cout << endl;
	}

    return 0;
}