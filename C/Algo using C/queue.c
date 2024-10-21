#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int front;
    int back;
    int *arr;
};

void push(struct Queue *ptr, int k){
    if(ptr->front == ptr->back){
        printf("Queue is empty");
    }
    if{ptr->front == -1 || ptr->back == -1}{
        ptr->front++;
        ptr->back++;
        arr[ptr->back] = k;
    }
    ptr->back++;
    arr[ptr->back] = k;
};

int main(){

    return 0;
}