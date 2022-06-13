#include <iostream>
using namespace std;

void msort(int input[], int si, int ei){
    if(si>=ei){
        return;
    }
    
    int mi = si + (ei - si)/2;
    
    msort(input, si, mi);
    msort(input, mi + 1, ei);
    
    //merge two arrays
    int *temp = new int[ei - si + 1];
    int i = si, j = mi + 1, ti = si;
    
    while(i<=mi && j <=ei){
        if(input[i] <= input[j]){
            temp[ti++] = input[i++]; 
        }
        else{
            temp[ti++] = input[j++];
        }
    }
    
    while(i<=mi){
        temp[ti++] = input[i++];
    }
    while(j<=ei){
        temp[ti++] = input[j++];
    }
    
    for(int x = si; x<=ei; x++){
        input[x] = temp[x];
    }
}

void mergeSort(int input[], int size){
  // Write your code here
    msort(input, 0, size - 1);
}


int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}