/*
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

Constraints:

1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
nums is sorted in non-decreasing order.

 */

 #include <bits/stdc++.h>

using namespace std;

class Solution{
public: 
    int removeDuplicates(vector<int>& nums){
        int k = 0;
        for(size_t i = 1; i<nums.size(); i++){
            if(nums[k]!=nums[i]){
                nums[k+1] = nums[i];
                ++k;
            }else if(nums[k]>nums[i]){
                return k+1;
            }
        }
        return k+1;
    }
};

int main(){
    Solution s;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    cout<<s.removeDuplicates(nums)<<endl;
    for(auto num:nums){
        cout<<num<<" ";
    }
    return 0;
}