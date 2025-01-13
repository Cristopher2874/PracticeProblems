/*
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
Return k.

Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).

Constraints:
0 <= nums.length <= 100
0 <= nums[i] <= 50
0 <= val <= 100
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = nums.size();
        for(int i = k-1; i>=0; i--){
            if(nums[i] == val){
                nums.erase(nums.begin()+i); //erase element with iterator
                --k;
            }
        }
        return k;
    } // complexity n^2

    int removeElement2(vector<int>& nums, int val) { //two pointers
        int k = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] != val){
                nums[k] = nums[i]; //overwrite the value
                ++k;
            }
        }
        return k;
    } // complexity n
};

int main(){
    Solution s;
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    cout << s.removeElement(nums, val) << endl;
    for(auto num:nums){
        cout<<num<<" ";
    }
}