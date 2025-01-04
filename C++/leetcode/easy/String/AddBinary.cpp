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
            string result = "";
            int lastA=a.size()-1, lastB=b.size()-1, carry=0;
            while(lastA>=0||lastB>=0){
                int sum = carry;
                if(lastA>=0 && lastB>=0){
                    sum=sum^(a[lastA--]^b[lastB--]);
                }else if(lastB>=0){
                    sum=sum^(0^b[lastB--]);
                }else{
                    sum=sum^(a[lastA--]^0);
                }

                carry = sum&1;
                result.push_back((sum+'0'));
                sum=0;
            }

            /*
            1+1 = 0 carry 1
            1+0 = 1 carry 0
            0+1 = 1 carry 0
            0+0 = 0 carry 0
            */
           result.reserve();
           if(carry) result.push_back('1');
           return result;
        }
};

int main(){
    Solution s;
    string a="11";
    string b="1";
    cout<<s.addBinary(a,b);
    return 0;
}