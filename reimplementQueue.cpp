#include<iostream>
using namespace std;

class Queue{
    int *arr;
    int front;
    int back;
    int size;
    int currentSIze;
    public:
    Queue(){
        size = 1000;
        front = -1;
        back = -1;
        currentSIze = 0;
        arr = new int[size];
    }
    void push(int val){
        if(front == -1){
            front++;
            back++;
            arr[back] = val;
            currentSIze++;
        }else{
            back++;
            arr[back] = val;
            currentSIze++;
        }
    }

    int pop(){
        if(front == -1){
            cout<<"Queue Empty\n Exiting..."<<endl;
        }
        if(front == back){
            cout<<"Error"<<endl;
        }
        int x = arr[front];
        front++;
        currentSIze--;
        return x;
    }

    int top(){
        if(front == -1){
            cout<<"Queue is Empty"<<endl;
            exit(1);
        }
        return arr[front];
    }

    int new_size(){
        return currentSIze;
    }
};

int main(){
    Queue q;
    q.push(4);
    q.push(5);
    q.push(6);
    cout << "The peek of the queue before deleting any element " << q.pop() << endl;
    cout << "Size " << q.new_size() << endl;
    cout<<"Current Top "<<q.top()<<endl;
    cout << "The peek of the queue before deleting any element " << q.pop() << endl;
    cout << "Size " << q.new_size() << endl;
    cout<<"Current Top "<<q.top()<<endl;
    return 0;
}