#include<iostream>
using namespace std;

void bubblesort(int arr[], int n){
    if (n == 1) return;
    for(int i=0; i<n-1; i++){
        if(arr[i]>arr[i+1]){
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
    bubblesort(arr , n-1);
}

int main(){
    int arr[] = {12, 46 , 24 , 52 , 20 , 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Before using bubble sort : "<<endl;
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    bubblesort(arr , n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout<<" \n";
    return 0;
}