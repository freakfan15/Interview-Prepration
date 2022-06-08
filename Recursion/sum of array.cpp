int sum(int a[], int n) {
	if(n==1){
        return a[0];
	}
    
	int smallArray = sum(a+1, n-1);
    return a[0] + smallArray;
}
