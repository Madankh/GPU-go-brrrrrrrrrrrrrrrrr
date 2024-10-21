#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,i,*ptr;
    printf("Enter total no of values");
    scanf("%d", &n);

    ptr=(int*)malloc(n*sizeof(int));
    printf("Enter the values\n");
    for(i=0;i<n;i++){
        scanf("%d", (ptr+i));
    }
    printf("Enter the updated size of n");
    scanf("%d", &n);
    int *ptr1 = (int*)realloc(ptr, n*sizeof(int));


    printf("The entered values are:");
    for(i=0;i<n; i++){
        printf("%d\t", *(ptr+i));
    }
    free(ptr);
    return 0;
}