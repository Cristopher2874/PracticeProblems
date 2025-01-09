/*
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python. 

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
 
Constraints:

0 <= x <= 231 - 1

MATH BINARY SEARCH
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long right = x, left = 1, middle = 0;
        while (right >= left){
            middle = left + (right - left) / 2;
            if(middle*middle==x || middle < 1){
                return middle < 1 ? 1 : middle;
            }else if(middle*middle>x){
                right = middle-1;
            }else{
                left = middle+1;
            }
        }
        return right; //bacause is the closest to the square root
    }
};

int main(){
    Solution s;
    cout<<s.mySqrt(11);
    return 0;
}