#include<stdio.h>

struct queue{
    int size;
    int f;
    int b;
    int *arr;
};

int main(){
    struct queue q;
    q.size = 10;
    q.f, q.b = -1;
      
    return 0;
}