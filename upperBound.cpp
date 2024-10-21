#include<iostream>
#include<vector>
using namespace std;

int upperBound(vector<int> nums , int n, int k){
     int lower = 0;
     int high = n-1;
     int ans = n;

     while(lower <= high){
        int mid = (lower + high) / 2;
        if(nums[mid] > k){
            ans =  mid;
            high = mid - 1;
        }else{
            lower = mid+1;
        }
     }
     return ans;
}

int main(){
    vector<int> arr = {3,5,8,9,15,19};
    int n = 6;
    int x = 9;
    int ind = upperBound(arr , x , n);
    cout<<ind<<endl;
    return 0;
}