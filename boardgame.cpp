#include<iostream>
using namespace std;

int countPath(int s , int e){
    if(s==e){
        return 1;
    }
    if(s>e){
        return 0;
    }
    int count = 0;
    for(int i=0; i<=6;i++){
       count+=countPath(s+i, e);
    }

    
}

int main(){
    cout<<countPath(0,3)<<endl;
    return 0;
}