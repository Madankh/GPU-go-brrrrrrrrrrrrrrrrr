#include<iostream>
using namespace std;

int add(int n, int m){
    int sum = n+m;
    return sum;
}

int main(){
    int n,m;
    cin>>n>>m;
    cout<<add(n,m);
    return 0;
}