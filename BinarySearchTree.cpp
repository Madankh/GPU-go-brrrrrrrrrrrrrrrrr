#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left,*right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    } 
};

Node* insertBST(Node *root, int val){
    if(root == NULL){
        root = new Node(val);
        return root;
    }
    if(val < root->data){
        root->left = insertBST(root->left , val);
    }else{
        root->right = insertBST(root->right , val);
    }
    return root;
}

void inorder(Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    Node *root = NULL;
    root = insertBST(root , 5);
    root = insertBST(root, 1);
    root = insertBST(root, 3);
    root = insertBST(root , 4);
    root = insertBST(root , 2);
    root = insertBST(root , 7);
    inorder(root);
    return 0;
}