/*
BINARY SEARCH

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

Input: nums = [1,3,5,6], target = 5
Output: 2

Input: nums = [1,3,5,6], target = 2
Output: 1

Input: nums = [1,3,5,6], target = 7
Output: 4
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target>nums[nums.size()-1]) return nums.size();
        if(target<nums[0]) return 0;
        int front=(nums.size()-1);
        int back=0;
        int middle = front/2;
        while(nums[middle]!=target && middle!=back && middle!=front){
            if(nums[back]==target){
                return back;
            }else if(nums[front]==target){
                return front;
            }
            if(target>nums[middle]){
                back=middle;
                middle=middle+(front-back)/2;                
            }else{
                front=middle;
                middle=middle-(front-back)/2;
            }
        }
        if(nums[middle]<target){
            return middle+1;
        }else{
            return middle;
        }
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,3,5,6,7};
    cout<<s.searchInsert(nums, 8);
    return 0;
}