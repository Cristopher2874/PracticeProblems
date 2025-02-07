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
        if(s.length() < 2){
            return s;
        }else{
            string longest = "";
            int start = 0;
            int maxLen = 0;
            for(int i = 1; i<s.length(); i++){
                //Odd cases
                auto[left1, right1] = palindrome(s,i-1,i+1);
                if(right1-left1+1 > maxLen){
                    start = left1;
                    maxLen = right1-left1+1;
                }

                //Even cases
                auto[left2, right2] = palindrome(s,i-1,i);
                if(right2-left2+1 > maxLen){
                    start = left2;
                    maxLen = right2-left2+1;
                }
            }
            return s.substr(start, maxLen);
        }
    }//Time O(n^2) Space O(1)
    
    pair<int,int> palindrome(string& s, int left, int right){
        while(left>=0 && right<s.length() && s[left]==s[right]){
            left--;
            right++;
        }
        return {left+1, right-1};
    }
    
};

int main(){
    string word = "babad";
    Solution s;
    cout<<s.longestPalindrome(word);
    return 0;
}