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

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        if (s.size() == 0)
            return 0;
        int i = s.size() - 1;
        int len=0;
        while (i >= 0 && s[i] == ' ')
        {
            --i;
        }
        while (i >= 0 && s[i] != ' ')
        {
            ++len;
            --i;
        }
        return len;
    }
};

int main()
{
    Solution s;
    string str = "";
    cout << s.lengthOfLastWord(str) << endl;
    return 0;
}