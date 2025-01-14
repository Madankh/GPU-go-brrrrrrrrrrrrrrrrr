#include<stdio.h>
#include<stdlib.h>


int main(){
    int n = 3;
    int *ptr = &n;
    int **ptr1 = &ptr;

    printf("%d\n", ptr); 
    printf("%d\n", &n);

    printf("%d\n", *ptr);
    printf("%d\n", **ptr1);

    printf("%d\n", &ptr);
    printf("%d\n", ptr1);
    
    return 0;
}