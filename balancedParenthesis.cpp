#include<iostream>
#include<stack>
using namespace std;

bool isValid(string n){
    int s = n.size();
    stack<char> st;
    bool ans = true;
    
    for(int i=0;i<s;i++){
        if(n[i] == '(' or n[i] == '{' or n[i] == '['){
            st.push(n[i]);
        }else if(n[i] == ')'){
            if(st.top() == '('){
                st.pop();
            }else{
                ans = false;
                break;
            }
        }else if(n[i] == '}'){
            if(st.top() == '{'){
                st.pop();
            }else{
                ans = false;
                break;
            }
        }else if(n[i] == ']'){
            if(st.top() == '['){
                st.pop();
            }else{
                ans = false;
                break;
            }
        }
    }
    return ans && st.empty(); 
}

int main(){
    string s = "{([])}";

    if(isValid(s)){
        cout<<"Valid string"<<endl;
    }else{
        cout<<"Not a valid striing"<<endl;
    }
    return 0;   
}