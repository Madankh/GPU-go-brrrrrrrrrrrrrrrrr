#include<iostream>
using namespace std;

int main(){
    // int n=10;
    // int* aptr=&n;


    // cout<<*aptr<<endl;
    // *aptr = 30;
    // cout<<*aptr<<endl;
    int arr[]={10,20,30};
    int *ptr = arr;
    // for(int i=0;i<3;i++){
    //     cout<<*ptr<<endl;
    //     ptr++;
    // }

    for(int i=0;i<3;i++){
        cout<<*(arr+i)<<endl;
        ptr++;
    }
    return 0;
}