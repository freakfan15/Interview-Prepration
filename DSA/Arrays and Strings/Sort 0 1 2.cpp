#include <iostream>
using namespace std;

void sort012(int *arr, int n)
{
    int nz = 0, nt = n - 1;
    for (int i = 0; i <= nt; i++) 
    {
        if (arr[i] == 0)
        {
            swap(arr[i], arr[nz++]);
        }
        else if (arr[i] == 2)
        {
            swap(arr[i], arr[nt--]);
            //do i-- cuz we need to check that element also
            //that has come in place of 2 from front
            //cuz we haven't checked it yet.
            //i-- i++ cancels out. so we stay at the same index
            //and check tht element
            i--;
        }
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