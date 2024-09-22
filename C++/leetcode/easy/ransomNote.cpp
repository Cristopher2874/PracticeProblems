#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> randsomNoteKey;
        for(const char& p:magazine){
            if (randsomNoteKey.find(p) != randsomNoteKey.end()) {
                randsomNoteKey[p] = randsomNoteKey[p]+1;
                continue;
            }else{
                randsomNoteKey[p] = randsomNoteKey[p]++;
            }
        }
        for(const char& p:ransomNote){
            if (randsomNoteKey.find(p) == randsomNoteKey.end()||randsomNoteKey[p]<0) {
                return false;
            }else{
                randsomNoteKey[p] = randsomNoteKey[p]--;
            }
        }
        return true;
    }
    bool canConstruct2(string ransomNote, string magazine) {
        unordered_map<char, int> dictionary;

        // Iterate through the magazine and count characters
        for (char c : magazine) {
            if (dictionary.find(c) == dictionary.end()) { //reduces step to 1 instead of 0
                dictionary[c] = 1;
            } else {
                dictionary[c]++;
            }
        }

        // Iterate through the ransom note and check character counts
        for (char c : ransomNote) {
            if (dictionary.find(c) != dictionary.end() && dictionary[c] > 0) {
                dictionary[c]--;
            } else {
                return false;
            }
        }

        return true;
    }
};

int main(){
    return 0;
}

// magazine.toCharArray() convert string to char array
//alphabets_counter[c-'a']++; returns the value of the ascii character that is in that position