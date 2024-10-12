/*
0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string temp="";
        int max=0;
        for(int i=0;i<s.size();i++){
            size_t found = temp.find(s[i]);
            if(found!=string::npos){
                temp = temp.substr(found+1);
            }
            temp+=s[i];
            max=max>temp.size()?max:temp.size();
            cout<<s.size()-i;
            //int num= stoi("123"); for str to int
        }
        return max;
    }
};

int main(){
    string s1 = "ctnkh";
    Solution s;
    cout<<s.lengthOfLongestSubstring(s1);
    return 0;
}