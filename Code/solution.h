void reverseStringWordWise(char input[]) {
    int e = 0;
    for(int i=0; input[i]!='\0'; i++){
        e++;
    }
    int end = e - 1;

    int start = 0;

    while(start<end){
        swap(input[start++], input[end--]);
    }

    int s = 0;
    int i=0, j=0;

    while(s<=e){
        if(input[s] == ' ' || input[s]=='\0'){
            j = s - 1;
            while(i<j){
                swap(input[i++], input[j--]);
            }
            i = s + 1;
        }

        s++;
    }
}