#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left= NULL;
        right=NULL;
    };
};

void printLevelOrder(Node* root){
    if(root == NULL){
        return;
    }
    
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        if(node != NULL){
            cout<<node->data<<" ";
            if(node->left != NULL){
                q.push(node->left);
            }
            if(node->right != NULL){
                q.push(node->right);
            }
        }else if(!q.empty()){
            q.push(NULL);
        }
    }
}

int sumATK(Node* root , int K){
    if(root == NULL){
        return -1;
    }
    
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int level = 0;
    int sum =0;
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        
        
        if(node != NULL){
            if(level == K){
               sum+=node->data; 
            };
            if(node->left){
                q.push(node->left);
            };
            if(node->right){
                q.push(node->right);
            };
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        };
    };
    return sum;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout<<sumATK(root,1);
    ///Level order Travers
    // printLevelOrder(root);
    return 0;
}





