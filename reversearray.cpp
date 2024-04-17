#include<iostream>
using namespace std;

void reverse(int nums[], int start, int end){
    while (start < end)
    {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--; // Corrected increment
    }
}

int main(){
    int arr[] = {1, 2, 3, 4};
    reverse(arr, 0, 3);

    for (int i = 0; i < 4; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}