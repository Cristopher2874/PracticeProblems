#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> squares(nums.size());
        for(int i=0;i<nums.size();i++){
            squares.push_back(nums[i]*nums[i]);
            squares.insert(squares.begin(),nums[i]*nums[i]);
        }
        return nums;
    }
};

int main(){
    vector<int> nums = {12,345,23,21,4,23,45,-2};
    Solution s;
    for(int square:s.sortedSquares(nums)){
        cout<<square<<" ";
    }
    return 0;
}