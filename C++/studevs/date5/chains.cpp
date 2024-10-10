#include<bits/stdc++.h>
using namespace std;

stack<char> stk;
int idx=0;
unordered_map<char, char> bracketPairs = {{')', '('}, {'}', '{'}, {']', '['},{'>','<'}};
string s;

int main() {
    cin>>s;
    for (char c : s) {
        if (bracketPairs.find(c) != bracketPairs.end()) {
            if (!stk.empty() && stk.top() == bracketPairs[c]) {
                stk.pop();
            } else {
                idx++;
                stk.pop();
            }
        } 
        else {stk.push(c);}
    }

    if(stk.empty()){
        cout<<idx;
    }else{
        cout<<"imposible";
    }
    return 0;
}