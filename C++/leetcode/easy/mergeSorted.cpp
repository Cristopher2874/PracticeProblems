#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx=0,i=0;
        while(idx<n||i<m){
            if(nums2[idx]<nums1[i]){
                nums1.insert(nums1.begin()+i,nums2[idx]);
                nums1.pop_back();
                idx++;
                i++;
            }else{
                i++;
            }
        }
    }
};

int main(){
    vector<int> nums = {1,2,3,7,0,0,0,0};
    vector<int> nums2 = {0,2,3,5};
    Solution s;
    s.merge(nums,4,nums2,4);
    for(auto square:nums){
        cout<<square<<" ";
    }
    return 0;
}