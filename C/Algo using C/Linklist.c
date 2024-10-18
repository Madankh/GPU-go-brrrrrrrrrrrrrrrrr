#include<stdio.h>
#include<stdlib.h>

struct Linklist{
    int data;
    struct Linklist *next;
};

void linkedListTraversal(struct Linklist* ptr){
    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    struct Linklist *head;
    struct Linklist *head1;
    struct Linklist *head2;

    head = (struct Linklist *) malloc(sizeof(struct Linklist));
    head1 = (struct Linklist *) malloc(sizeof(struct Linklist));
    head2 = (struct Linklist *) malloc(sizeof(struct Linklist));
    head->data = 10;
    head->next = head1;
    head1->data = 12;
    head1->next = head2;
    head2->data = 13;
    head2->next = NULL;
    linkedListTraversal(head);
    
    return 0;
}