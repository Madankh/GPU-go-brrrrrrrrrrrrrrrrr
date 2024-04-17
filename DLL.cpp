#include<iostream>
#include<vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* back;
    Node(int val) {
        data = val;
        next = nullptr;
        back = nullptr;
    }
    Node(int val, Node* next1, Node* next2) {
        data = val;
        next = next1;
        back = next2;
    }
};

Node* ConvertArrDLL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

Node* deleteHead(Node* head){
    if(head == nullptr || head->next == nullptr){
        return nullptr;
    }
    Node* prev = head;
    head = head->next;

    head->back = nullptr;
    prev->next = nullptr;

    delete prev;
    return head;
}



void print(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> arr = { 12,5,8,7 };
    Node* head = ConvertArrDLL(arr);
    Node* temp = deleteHead(head);
    print(temp);
    return 0;
}
