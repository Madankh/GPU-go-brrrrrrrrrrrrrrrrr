#include<iostream>
#include<math.h>
using namespace std;

int Power(int n, int p){
    if(p == 0){
        return 1;
    }

    int prePower = Power(n, p-1);
    return n*prePower;
}

// int Sum(int n){
//     if(n==0){
//         return 0;
//     }
//     int preSum = Sum(n-1);
//     return n + preSum;
// }

int main(){
    int n = 5;
    cout<<Power(n , 2);
    // cout<<Sum(n)<<endl;
    return 0;
}