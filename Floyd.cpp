#include<iostream>
using namespace std;

int main(){
    int n;
    int counter = 1;
    cin>>n;

    for (int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            cout<<counter++<<" ";
        }cout<<endl;
    }
    return 0;
}