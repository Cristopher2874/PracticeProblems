/*
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal 
substring
 consisting of non-space characters only.

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
 
Constraints:

1 <= s.length <= 104
s consists of only English letters and spaces ' '.
There will be at least one word in s.
*/


#include <bits/stdc++.h>

using namespace std;

class Solution{
    public:
    int lengthOfLastWord(string s) {
        //search for a split method that splits the string by spaces and takes the last item
        // problem, the lasst item could contain spaces
        // iterate from the end until we find a non-space character
        // continue iterate until we find a space character
        // return the number of iterations
        return s.length();
    }
};

int main(){
    Solution s;
    string str = "  Hello World   ";
    cout<<s.lengthOfLastWord(str)<<endl;
    return 0;
}