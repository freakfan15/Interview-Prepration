void rotate(int **input, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i>j){
                swap(input[i][j], input[j][i]);
            }
        }
    }

    int s = 0, e = n-1;
    while(s<e){
        int j = 0;
        while(j<n){
            swap(input[s][j], input[e][j]);
            j++;
        }
        s++; e--;
    }
}
