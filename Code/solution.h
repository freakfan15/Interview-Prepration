void wavePrint(int **input, int nRows, int mCols)
{
    for(int i=0; i<mCols; i++){
        if(i%2==0){
            for(int j=0; j<nRows; j++){
                cout<<input[j][i]<<" ";
            }
        }
        else{
            for(int j=nRows - 1; j>=0; j--){
                cout<<input[j][i]<<" ";
            }
        }
    }
    
}