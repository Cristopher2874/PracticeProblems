#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx=0,idx2=0;
        for(int i=0;i<m;i++){
            if(nums1[i]>=nums2[idx]){
                nums1.insert(nums1.begin()+i,nums2[idx]);
                nums1.pop_back();
                i++;
                idx++;
            }
            idx2=i;
        }
        if(nums1[idx2]<nums2[idx]){
            for(int i=0;idx<n;i++){
                nums1.insert(nums1.begin()+m+i+1,nums2[idx]);
                nums1.pop_back();
                idx++;
            }
        }else{
            int control=0;
            while(nums1[idx2]>nums2[idx]&&idx<n){
                nums1.insert(nums1.begin()+(m)+control,nums2[idx]);
                nums1.pop_back();
                ++idx;
                ++idx2;
                ++control;
            }
            for(int i=0;idx<n;i++){
                nums1.insert(nums1.begin()+idx2+1,nums2[idx]);
                nums1.pop_back();
                idx++;
            }
        }
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