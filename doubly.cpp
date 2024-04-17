#include<iostream>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;
    Node* prev;
    
    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insertAtHead(Node* &head, int val){
    Node* n = new Node(val);
    n->next = head;
    if(head != NULL){
        head->prev = n;
    }
    head = n;
}

void insertAtTail(Node* &head, int val){
    Node* n = new Node(val);
    if(head == NULL){
        insertAtHead(head, val);
        return;
    }
    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" "<<" ";
        temp= temp->next;
    }cout<<endl;
};

int main(){
    Node* head = NULL;
    insertAtTail(head, 2);
    insertAtTail(head , 3);
    insertAtTail(head, 5);
    display(head);
    return 0;
}