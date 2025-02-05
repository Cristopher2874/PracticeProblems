/*
Given a string s, return the longest palindromic substring in s.

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Input: s = "cbbd"
Output: "bb"

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.

TWO POINTER TECHNIQUE STRING DYNAMIC PROGRAMMING
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() == 0){
            return "";
        }else if(s.length() == 1){
            return s;
        }else{
            string longest = "";
            for(int i=0; i<s.length(); ++i){
                
            }
        }
        return "";
    }
    
    bool palindrome(string s){
        for(int i= s.length()/2-1; i>=0; i--){
            if(s[i] != s[s.length()-i-1]){
                return false;
            }
        }
        return true;
    }
    
};

int main(){
    string word = "babad";
    Solution s;
    cout<<s.longestPalindrome(word);
    return 0;
}