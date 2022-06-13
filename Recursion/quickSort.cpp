#include<iostream>
using namespace std;

int partition(int input[], int s, int e){
    int cnt = 0;
    for(int i = s+1; i<=e; i++){
        if(input[i] <= input[s]){
            cnt++;
        }
    }
    
    int pivotIndex = s + cnt;
    std::swap(input[s], input[pivotIndex]);
    
    int i = s, j = e;
    
    while(i<pivotIndex && j>pivotIndex){
        if(input[i] <= input[pivotIndex]){
            i++;
        }
        else if(input[j]>input[pivotIndex]){
            j--;
        }
        else{
            std::swap(input[i++], input[j--]);
        }
    }
    
    return pivotIndex;
}

void quickSort(int input[], int s, int e)
{
    if(s >= e){
        return;
    }
    
    int p = partition(input, s, e);
    
    quickSort(input, s, p-1);
    quickSort(input, p+1, e);
}
void quickSort(int input[], int size)
{
    quickSort(input, 0, size - 1);
}


int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}