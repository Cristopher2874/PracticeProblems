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
    stack<char> stk;
    unordered_map<char, char> bracketPairs = {{')', '('}, {'}', '{'}, {']', '['}};

    for (char c : s) {
        // If it's a closing bracket
        if (bracketPairs.find(c) != bracketPairs.end()) {
            // Check if the stack is not empty and the top of the stack matches the corresponding opening bracket
            if (!stk.empty() && stk.top() == bracketPairs[c]) {
                stk.pop();
            } else {
                return false;
            }
        } 
        // If it's an opening bracket
        else {
            stk.push(c);
        }
    }
    
    // If the stack is empty, all brackets were balanced
    return stk.empty();
}
