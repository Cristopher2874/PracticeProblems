#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int idx=0;
        int max=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                idx++;
            }else{
                max=max>idx?max:idx;
                idx=0;
            } 
        }
        max=max>idx?max:idx;
        return max;
    }
};

int main(){
    vector<int> nums = {1,1,1,1,0,0,0,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1};
    Solution s;
    cout<<s.findMaxConsecutiveOnes(nums);
    return 0;
}