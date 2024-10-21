#include<iostream>
using namespace std;

class Stack{
    int *arr;
    int top;
    int size;
    public:
    Stack(){
        top = -1;
        size = 10000;
        arr = new int[size];
    }
    void push(int val){
        top++;
        arr[top]=val;

    }
    int pop(){
        int x = arr[top];
        top--;
        return x;
    }
    int Top(){
        return arr[top];
    }
    int Size(){
        return top+1;
    }
};

int main(){
    Stack s;
    s.push(2);
    s.push(4);
    s.push(7);
    cout<<"Top of stack is before deleting any element "<<s.Top()<<endl;
    cout<<"Size of stack is before deleting any element "<<s.Size()<<endl;
    cout<<"deleting element "<<s.pop()<<endl;
    cout<<"Size of stack is before deleting any element "<<s.Size()<<endl;
    return 0;
}