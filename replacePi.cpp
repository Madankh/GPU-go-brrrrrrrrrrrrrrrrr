#include<iostream>
using namespace std;

void repalcePi(string s){
    if(s.length() == 0){ // base case
        return;
    }
    if(s[0]== 'p' && s[1] == 'i'){
        cout<<"3.14";
        repalcePi(s.substr(2));
    }
    else{
        cout<<s[0];
        repalcePi(s.substr(1));
    }

}

int main(){
    repalcePi("pipppppiiiipi");
    return 0;
}