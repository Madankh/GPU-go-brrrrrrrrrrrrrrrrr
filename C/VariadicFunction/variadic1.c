#include<stdio.h>
#include<stdarg.h>

int main(){
    int average_age;
    average_age = average(5,18,45, 32,100,7);
    printf("The average age of those 5 people is %d\n");
    return 0;
}