#include<stdio.h>
#include<stdarg.h>

void printNumbers(int size, ...){
    int i, value;
    va_list args;
    va_start(args, size);
    for(i=0; i<=size;i++){
        value = va_arg(args, int);
        printf("%d ", value);
    }
    va_end(args);
    printf("\n");
};

int main(){
    printNumbers(3,4,5,44,6);
    return 0;
}