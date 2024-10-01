#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]=nums[i]*nums[i];
        }
        sort(nums.begin(),nums.end());
        return nums;
    }
};

int main(){
    vector<int> nums = {12,345,23,21,4,23,45,-2};
    Solution s;
    vector<int> num2 = s.sortedSquares(nums);
    for(int square:num2){
        cout<<square<<" ";
    }
    return 0;
}