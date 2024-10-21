#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    for(int i=1;i<=n; i++){
        for(int j=0; j<=n-i ; j++){
            cout<<" ";
        }
        int m=i;
        for(int k=2; k<=i;k++){
            cout<<m--<<" ";
        }
        for(int j=1;j<=i;j++){
            cout<<j<<" ";
        }cout<<endl;
    }
    return 0;
}