#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

bool isValid(string s);

int main() 
{
    string s = "([]{}))(";
    cout << isValid(s);
    return 0;
}

bool isValid(string s) {
    stack<char> stk; //create a stack to storage the order of the brackets (libreary needed)
    unordered_map<char, char> bracketPairs = {{')', '('}, {'}', '{'}, {']', '['}}; //match each pair in a map

    for (char c : s) { //other way to indicate the for loop without varible
        // for a closing bracket case
        if (bracketPairs.find(c) != bracketPairs.end()) {
            // check if the stack is not empty and if the top matches the open bracket
            if (!stk.empty() && stk.top() == bracketPairs[c]) {
                stk.pop();
            } else {
                return false;
            }
        } 
        // add if it is an opening bracket
        else {stk.push(c);}
    }
    
    // If the stack is empty, all brackets were closed in order
    return stk.empty();
}
