#include<iostream>
using namespace std;

void towerofHanod(int n, char src, char dest, char helper){
    if(n==0){
        return; // base case
    }
    towerofHanod(n-1, src , helper,dest);
    cout<<"Move from "<<src<<" to "<<dest<<endl;
    towerofHanod(n-1, helper , dest , src);
}

int main(){
    towerofHanod(3, 'A', 'C' , 'B');
    return 0;
}