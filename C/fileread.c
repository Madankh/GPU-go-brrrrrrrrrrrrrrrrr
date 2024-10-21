#include<stdio.h>

int main(){
    FILE *fptrr;
    fptrr = fopen("te3.txt", "r");
    if(fptrr == NULL){
        printf("fILE DOES NOT EXIST\n");
    }else{
        fclose(fptrr);
    }
    // printf(*fptrr);
    return 0;
}