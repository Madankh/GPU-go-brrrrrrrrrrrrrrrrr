#include "bits/stdc++.h"
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
    
};

// void inorderTraversal(Node* node) {
//     if (node == NULL)
//         return;
//     inorderTraversal(node->left);
//     cout << node->data << " ";
//     inorderTraversal(node->right);
    
// }


int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // inorderTraversal(root);
    return 0;
}