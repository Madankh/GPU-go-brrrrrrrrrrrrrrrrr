#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node * next;
};

// void terversalNode(struct Node* head){
//     while(head){
//         printf(head->data);
//         head = head->next;
//     }
// }

void traversalNode(struct Node* head) {
    while (head) {  // Correct condition to loop through the list
        printf("%d\n", head->data);  // Correct format specifier for printing an integer
        head = head->next;
    }
}


int main(){
    struct Node *head;
    struct Node *head1;
    struct Node * head2;
    struct Node *head3;

    head = (struct Node*) malloc(sizeof(struct Node));
    head1 = (struct Node*) malloc(sizeof(struct Node));
    head2 = (struct Node*) malloc(sizeof(struct Node));
    head3 = (struct Node*) malloc(sizeof(struct Node));
    head->data = 2;
    head->next = head1;
    head1->data=4;
    head1->next = head2;
    head2->data = 5;
    head2->next = head3;
    head3->data = 49;
    head3->next = NULL;
    traversalNode(head);

    // Free allocated memory to avoid memory leaks
    free(head);
    free(head1);
    free(head2);
    free(head3);

    return 0;
}