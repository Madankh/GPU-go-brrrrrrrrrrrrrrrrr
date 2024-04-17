#include<iostream>
#include<vector>
using namespace std;

vector<int> twosum(vector<int> &nums , int target){
    
}

int main(){
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> result = twosum(nums, target);
    
    if(result.size() == 2){
        cout<<"Indics "<<result[0]<<result[1];
    }else{
        cout<<"No indics found"<<endl;
    }
    return 0;
}