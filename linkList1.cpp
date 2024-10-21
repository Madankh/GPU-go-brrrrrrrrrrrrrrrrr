#include<iostream>
using namespace std;

struct Node{
    public:
    int data;
    Node *next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtTail(Node* &head, int val){
    Node* n = new Node(val);
    if(head == NULL){
        head = n;
        return;
    }
    Node* temp = head;
    if(temp != NULL){
        temp = temp->next;
    }
    temp->next = n;
}


int main(){

    return 0;
}