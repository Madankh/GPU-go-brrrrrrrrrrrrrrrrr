#include<iostream>
#include<vector>
using namespace std;


//  Brute force Approach
// int lowerBound(vector<int> arr, int n, int x){
//     for(int i=0; i<n; i++){
//         if(arr[i]>=x){
//             return i;
//         }
//     }
//     return n;
// }


//  Optimal Approch using binary search
int lowerBound(vector<int> arr , int n, int k){
    int lower = 0;
    int high = n-1;
    int ans = n;

    while(lower <= high){
        int mid = (lower + high)/2;
        if(arr[mid] >= k){
            ans =  mid;
            high = mid-1;
        }else{
            lower = mid + 1;
        }
    }

    return ans;
}

int main(){
    vector<int> arr = {3,5,8, 15, 19};
    int n=5;
    int x = 9;
    int ind = lowerBound(arr , n , x);
    cout<<ind;
    return 0;
}