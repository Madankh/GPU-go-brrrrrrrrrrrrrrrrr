#include<iostream>
using namespace std;

void dec(int n){
    if(n==0){
        return;
    }

    cout<<n<<endl;
    dec(n-1);
}

void increase(int n){
    if(n==0){
        return;
    }

    increase(n-1);
    cout<<n<<endl;
}

int main(){
    int n;
    cin>>n;
    dec(n);
    increase(n);
    return 0;
}