#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    int maxValue = -1999999;
    for(int i=0;i<n;i++){
        maxValue = max(maxValue , arr[i]);
        cout<<maxValue<<" ";
    }


    return 0;
}