#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isV(char a){
        return a=='a'||a=='e'||a=='i'||a=='o'||a=='u';
    }
    int f(string word, int k) {
        unordered_map<char,int> vowels;
        int vCount = 0, totalV = 0;
        int i=0,j=0,res=0;

        while(j<word.size()){
            if(isV(word[j])){
                ++totalV;
                if(vowels.find(word[j])!=vowels.end()){
                    if(vowels[j]<i){
                        ++vCount;
                    }
                    vowels[word[j]] = j;
                }else{
                    vowels[word[j]] = j;
                    ++vCount;
                }
            }
            while((j-i+1-totalV)>k){
                 if (isV(word[i])) {
                    if (vowels[word[i]] == i) vCount--;
                    totalV--;
                }
                i++;
            }
            if (vCount == 5) {
                int x = min({vowels['a'], vowels['e'], vowels['i'], vowels['o'], vowels['u']});
                res += (x - i + 1);
            }
            j++;
        }
        return res;
    }
    int countOfSubstrings(string word, int k) {
        return f(word, k) - f(word, k - 1);
    }
};

int main(){
    Solution s;
    string word = "havefun";
    int k = 3;
    cout<<s.countOfSubstrings(word,k);
    return 0;
}

//vps, aparte para uso personal
//fast api
//métodos http
//códigos http
//virtual env