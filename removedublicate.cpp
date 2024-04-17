#include<iostream>
#include<vector>
using namespace std;

vector<int> removeDublicate(int arr[] , int n){
    vector<int> a;
    for(int i=0; i<n; i++){
        if(arr[i-1] != arr[i]){
            a.push_back(arr[i]);
                
        }
    }
    return a;
}

int main(){
    int arr[] = {1,1,2,2,3,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> result = removeDublicate(arr , n);
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}