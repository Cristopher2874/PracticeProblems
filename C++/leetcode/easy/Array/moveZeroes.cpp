/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:

Input: nums = [0]
Output: [0]
 
Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 
Follow up: Could you minimize the total number of operations done?

ARRAYS TWO POINTER IN PLACE OPERATION
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()<=1) return;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==0){
                int temp = i+1;
                while (nums[temp]==0 && temp < nums.size()){
                    temp++;
                    if(temp>nums.size()-1) return;
                }
                nums[i] = nums[temp];
                nums[temp]=0;
            }
        }
    }
};

int main(){
    vector<int> nums = {-1,0,12,5,0,0,-4,35,0,0,0,0,7};
    Solution s;
    s.moveZeroes(nums);
    for(auto num:nums){
        cout<<num<<" ";
    }
    return 0;
}