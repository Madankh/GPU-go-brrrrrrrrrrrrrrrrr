#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void linklistTraversal(struct Node* head){
    while(head != NULL){
        printf("%d head->data \n", head->data);
        head = head->next;
    }
};

void insertAtTail(struct Node* head, int n){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;
    newNode->data = n;
    newNode->next = NULL;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}
int main(){
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    struct Node *head1 = (struct Node*) malloc(sizeof(struct Node));
    struct Node *head2 = (struct Node*) malloc(sizeof(struct Node));
    head->data = 23;
    head->next = head1;
    head1->data = 34;
    head1->next = head2;
    head2->data = 65;
    head2->next = NULL;
    insertAtTail(head, 3);
    linklistTraversal(head);

    return 0;
}