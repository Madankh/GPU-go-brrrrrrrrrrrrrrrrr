#include<iostream>
using namespace std;
#include<vector>

void rotate(vector<int>& nums, int k) {
    vector <int> temp(nums.size());
    for(int i = 0;i<nums.size();i++){
        temp[(i+k)%nums.size()] = nums[i];
    } 
    nums = temp;
}


int main(){
    rotate();
    return 0;
}
