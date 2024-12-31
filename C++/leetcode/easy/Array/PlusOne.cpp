/*
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].

Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].

Constraints:

1 <= digits.length <= 100
0 <= digits[i] <= 9
digits does not contain any leading 0's.

ARRAY MATH
*/

#include <bits/stdc++.h>

using namespace std;

class Solution{
    public:
        vector<int> plusOne(vector<int>& digits){
            int temp=0;
            for(int i=digits.size()-1;i>=0;i--){
                temp=digits[i]+1;
                if(temp>=10){
                    digits[i]=(temp%10);
                }else{
                    digits[i]=temp;
                    temp=0;
                    break;
                }
            }
            if(temp!=0) digits.insert(digits.begin(),1);
            return digits;
        }
};

int main(){
    Solution s;
    vector<int> digits = {9,9};
    vector<int> result = s.plusOne(digits);
    for(size_t i=0;i<result.size();++i){
        cout << result[i] << " ";
    }
    return 0;
}