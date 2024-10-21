#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> s={-2,10,1,3,2,-1,4,5};
    int k=3;
    int sum=0;
    int ans = INT_MAX;
    for(int i=0; i<k; i++){
        sum+=s[i];
    }
    ans = min(ans , sum);
    for(int i=1; i<s.size(); i++){
        sum= sum - s[i-1]+s[i+k-1];
        ans = min(sum, ans);
    }
    cout<<ans<<endl;
    return 0;
}