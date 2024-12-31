/*
Given two binary strings a and b, return their sum as a binary string.

Input: a = "11", b = "1"
Output: "100"

Input: a = "1010", b = "1011"
Output: "10101"
 
Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.

STRING MATH BIT MANIPULATION
*/

#include <bits/stdc++.h>

using namespace std;

class Solution{
    public:
        string addBinary(string a, string b){
            return "10";
        }
};

int main(){
    Solution s;
    string a="11";
    string b="1";
    cout<<s.addBinary(a,b);
    return 0;
}