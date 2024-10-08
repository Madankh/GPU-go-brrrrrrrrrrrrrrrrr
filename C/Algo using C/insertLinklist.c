#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void insertAtHead(struct Node *ptr, int x){
    if(ptr!=NULL){
        struct Node *temp = (struct Node *) malloc(sizeof(struct Node));
        temp->data = x;
        temp->next = ptr; 
    }else{
        struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
        temp->data = x;
        temp->next = ptr;
    }
    return temp;
}

void insertAtTail(struct Node *ptr , int x){

}

int main(){
    struct Node *head = 
    return 0;
}