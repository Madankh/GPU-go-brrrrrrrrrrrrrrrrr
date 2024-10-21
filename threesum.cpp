#include "bits/stdc++.h"
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    int target;
    cin>>target;

    vector<int> arr(n);

    for(auto &i : arr){
        cin>>i;
    }

    bool found = false;
    sort(arr.begin() , arr.end());
    for(int i=0; i<n;i++){
        int lo = i+1, hi = n-1;
        while(lo<hi){
            int current = arr[i] + arr[lo] + arr[hi];
            if(current == target){
                found = true;
            }
            if(current< target){
                lo++;
            }else{
                hi--;
            }
        }
    }

    if(found){
        cout<<"True";
    }else{
        cout<<"False";
    }

    return 0;
}