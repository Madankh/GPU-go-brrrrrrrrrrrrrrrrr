#include<iostream>
#include<vector>
using namespace std;

int main(){
    string s;
    cin>>s;

    vector<int> dict(256, -1);
    int maxLen = 0, start = -1;
    
    for(int i=0;i<s.size(); i++){
        // cout<<dict[s[i]]<<" random"<<endl;
        if(dict[s[i]] > start){
            start = dict[s[i]];
            cout<<"dict "<<dict[s[i]];
        }
        dict[s[i]] = i;
        maxLen = max(maxLen , i-start);
    }

    cout<<maxLen<<endl;
    return 0; 
}