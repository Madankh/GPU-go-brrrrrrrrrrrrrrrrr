#include<iostream>
using namespace std;

bool isPrime(int n, int m){
    bool isPrimeNumber = false;
    if((n+m)%2==0){
        isPrimeNumber = true;
    }else{
        isPrimeNumber = false;
    }
    return isPrimeNumber;
}

int main(){
    int n,m;
    cin>>n>>m;
    int primeOrNot = isPrime(n,m);
    if(primeOrNot == 1){
        cout<<"Prime";
    }else{
        cout<<"Not prime";
    }
    return 0;
}