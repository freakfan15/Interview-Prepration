void merge(int *arr1, int size1, int *arr2, int size2, int *ans)
{
    int i =0, j=0, k=0;
    while(i<size1 and j<size2){
        if(arr1[i] <= arr2[j]){
            ans[k++] = arr1[i];
            i++;
        } 
        else {
            ans[k++] = arr2[j];
            j++;
        }
    }

    while(i<size1){
        ans[k++] = arr1[i++];
    }
    while(j<size2){
        ans[k++] = arr2[j++];
    }

}