#include<iostream>
#include<vector>
using namespace std;

void sortColors(vector<int> arr){
    int low=0;
    int index = 0;
    int high = arr.size();

    while (low<high){
        if(arr[low]==0){
            swap(arr[low] , arr[index]);
            low++;
            index++;
        }else if(arr[index] == 2){
            swap(arr[index] , arr[high]);
            high--;
        }else{
            index++;
        }
    }
    
};

int main(){
    vector<int> unso = {0,2,1,0,2,1};
    vector<int> sorted = sortColors(unso);
    for(int num : sorted){
        cout << num << " ";
    }
    return 0;
}