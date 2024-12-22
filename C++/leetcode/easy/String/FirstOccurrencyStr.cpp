/*
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.length() == 0 || needle.length() == 0){
            return -1;
        }else if(haystack.length() < needle.length()){
            return -1;
        }else{
            for(int i=0; i<(haystack.length()-(needle.length()-1)); i++){
                if(haystack.substr(i, needle.length()) == needle){
                    return i;
                }
            }
        }
        return -1;
    }
    int strStr2(string haystack, string needle) {
        if(needle.length() == 0){
            return -1;
        }
        return haystack.find(needle);
    }
};

int main(){
    string haystack = "leetcode", needle = "a";
    Solution s;
    cout<<s.strStr2(haystack, needle)<<endl;
    return 0;
}