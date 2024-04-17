#include<iostream>
using namespace std;

#define n 20

class queue{
    int *arr;
    int front;
    int back;

    public:
    queue(){
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void push(int x){
        if(back == n-1){
            cout<<"Queue overflow"<<endl;
            return;
        }
        back++;
        arr[back] = x;

        if(front == -1){
            front++;
        }
    }

    void pop(){
        if(front == -1 || front > back){
            cout<<"No element in queue"<<endl;
            return;
        }
        front++;
    }

    int peek(){
        if(front == -1 || front > back){
            cout<<"No element in queue"<<endl;
            return -1;
        }

        return arr[front];
    }

    bool empty(){
        if(front == -1 || front > back){
            return true;
        }
        return false;
    }
};

int main(){
    queue q;
    q.push(3);
    q.push(2);
    q.push(1);

    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    q.pop();
    cout<<q.empty();
    return 0;
}