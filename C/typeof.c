#include<stdio.h>

typedef struct student{
    int roll;
    float cgpa;
    char name[100];
} stu;

int main(){
    // struct student s1;
    stu s2 = {43, 3.4, "suman"};
    printf("roll %d" , s2.roll);

    return 0;
}