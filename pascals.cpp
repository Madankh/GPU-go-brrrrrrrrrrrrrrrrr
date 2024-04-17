#include<iostream>
#include<vector>
using namespace std;
// int factorial(int n){
//     if(n == 0){
//         return 1;
//     };
//     int prev = factorial(n-1);
//     return n*prev;
// }

vector<vector<int>> pascalTriangle(int n){
    vector<vector<int>> ans(n); // Initialize ans with n empty vectors
    for(int i=0; i<n; i++){
        ans[i].resize(i+1); // Resize each vector to the appropriate size
        for(int j=0; j<i+1;j++){
            if(j==0 || j==i){
                ans[i][j] = 1;
            }else{
                ans[i][j] = ans[i-1][j] + ans[i-1][j-1];
            }
        }
    }
    return ans;
}


int main(){
    int n=5;
    vector<vector<int>> ans;
    ans = pascalTriangle(n);

    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }

    
    return 0;
}