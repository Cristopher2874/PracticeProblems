#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
    }
};

int main(){
    vector<int> nums = {1,7,7,9,0,0};
    vector<int> nums2 = {2,5};
    Solution s;
    s.merge(nums,4,nums2,2);
    for(auto square:nums){
        cout<<square<<" ";
    }
    return 0;
}