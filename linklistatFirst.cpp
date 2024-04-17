#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    };
};

Node* insertAtFirst(int val, Node* &head){
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
    return head;
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

int main(){
    Node* head = new Node(1);
    head = insertAtFirst(40, head);
    head = insertAtFirst(50 , head);
    display(head);
    return 0;
}