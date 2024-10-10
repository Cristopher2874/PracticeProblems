#include<bits/stdc++.h>
using namespace std;

string n;
int idx = 0;
vector<char> key = {'a', 'b', 'c', 'd', '(', ')'};

int main() {
    cin>>n;
    if (n.empty()) {
        cout<<"0";
        return 0;
    }
    for(char letter:n){
        if(find(key.begin(),key.end(), letter)==key.end()){
            cout<<"0";
            return 0;
        }
        if(letter != '('&&letter != ')') continue;
        if(letter == '('){
            idx++;
        }else{
            idx--;
        }
        if(idx < 0){
            cout<<"0";
            return 0;
        }
    }
    if(idx != 0) cout<<"0";
    else cout<<"1";
    return 0;
}