#include<stdio.h>
#include<string.h>
struct Student
{
    int roll;
    float cgpa;
    char name[100];
};

void printInfo(struct Student s1);

int main(){
    struct Student s1 = {123, 9.2, "suman"};
    printInfo(s1);
    // s1.roll = 1203;
    // s1.cgpa = 9.6;
    // strcpy(s1.name, "Suman");
    // struct Student *ptr = &s1;
    // printf("student roll = %d\n" , (*ptr).roll);
    // printf("student roll = %d\n" , ptr->roll);
    // printf("Student name = %s\n", s1.name);
    // printf("Student roll = %d\n", s1.roll);
    // printf("Student cgpa = %f\n", s1.cgpa);
    return 0;
}

void printInfo(struct Student s1){
    printf("Student name = %s\n", s1.name);
    printf("Student roll = %d\n", s1.roll);
    printf("Student cgpa = %f\n", s1.cgpa);
}