/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 
Constraints:

1 <= n <= 45

MATH DYNAMIC PROGRAMMING MEMORIZATION
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    map<int, int> dp; //store the previous values

    int climbStairs(int n) {
        if(n == 1) return 1;
        if (n == 2) return 2;
        if(dp.find(n) != dp.end()) return dp[n];
        else{
            dp[n] = climbStairs(n-1) + climbStairs(n-2);
            return dp[n];
        }
    }
};

int main(){
    Solution s;
    cout<<s.climbStairs(45);
    return 0;
}