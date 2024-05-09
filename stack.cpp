#include<iostream>
using namespace std;
#define n 100

class stack{
    public:
    int *arr;
    int top;

    public:
    stack(){
        arr = new int[n];
        top = -1;
    }

    void push(int x){
        if(top == n-1){
            cout<<"Stack overflow"<<endl;
            return;
        }
        top++;
        arr[top] = x;
    }

    void pop(){
        if(top == -1){
            cout<<"No element found"<<endl;
            return;
        }
       top--; 
    }

    void Top(){
        if(top == -1){
            cout<<"No element found"<<endl;
            return;
        };
        return arr[top];
    }
}

int main(){
    
    return 0;
}