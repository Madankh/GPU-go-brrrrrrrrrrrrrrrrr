#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

Node* insertAtTail(Node* &head , int val){
    Node* n = new Node(val);
    if(head == NULL){
        head = n;
        return head;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}
void display(Node* head){
    if(head == NULL){
        return;
    }
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }cout<<"NULL"<<endl;
}

void deletion(Node* &head, int val){
    Node* temp = head;
    while(temp->next->data != val){
        temp = temp->next;
    }
    Node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

int main(){
    Node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head , 2);
    insertAtTail(head , 3);
    insertAtTail(head, 5);
    deletion(head, 2);
    display(head);
}