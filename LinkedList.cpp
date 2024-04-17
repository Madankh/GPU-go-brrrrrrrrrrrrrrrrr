#include<bits/stdc++.h>
// #include<vector>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;

    public:
    Node(int val, Node* next1){
        data = val;
        next = next1;
    }

    public:
    Node(int val){
        data = val;
        next = nullptr;
    }
};

Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node* removesHead(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head; 
}

Node* removeTail(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    while(temp->next->next != nullptr){
        temp = head->next;
    }
    temp->next = nullptr;
    return temp = head;
    
}

Node* remove(Node* head , int val){
    if(head == nullptr) return head;
    Node* temp = head;
    while(temp->data == val){
        
    }
}

void display(Node* head){
    while(head !=nullptr){
        cout<<head->data<<" ";
        head = head->next;
    }cout<<endl;
}

int main(){
    vector<int> arr = {9,7,6,6,4,7,5,9,5,3};
    Node* head = convertArr2LL(arr);
    display(head);
    head = removesHead(head);
    display(head);
    head = removeTail(head);
    display(head);
    return 0;
}