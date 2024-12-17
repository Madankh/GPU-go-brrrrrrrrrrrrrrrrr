#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, i, *ptr;
    printf("enter total no of values");
    scanf("%d", &n);

    ptr=(int*)calloc(n,sizeof(int));
    printf("Enter the values\n");
    for(i=0;i<n;i++){
        scanf("%d", (ptr+i));
    }

    for(i=0;i<n;i++){
        printf("%d\n", *(ptr+i));
    }
    return 0;
}