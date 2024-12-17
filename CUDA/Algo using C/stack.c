#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int  isEmpty(struct stack* ptr){
    if(ptr->top == -1){
        return -1;
    }else{
        return 0;
    }
};

int isFull(struct stack* ptr){
    if(ptr->top == ptr->size - 1){
        return 1;
    }else{
        return 0;
    }
}

void push(struct stack* ptr, int val){
    if(isFull(ptr)){
        printf("stack overflow");
    }else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

void pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack is underflow");
    }
    else{
        int val = ptr->arr[ptr->top];
    }
}

int main(){

    return 0;
}