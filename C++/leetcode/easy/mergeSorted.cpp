#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        m--;
        n--;
        while(n>=0){
            while(nums1[m]>=nums2[n]&&m>=0&&n>=0){
                m--;
            }
            while(nums1[m]<=nums2[n]&&m>=0&&n>=0){
                nums1.insert(nums1.begin()+m+1,nums2[n]);
                nums1.pop_back();
                n--;
            }
        }
    }
};

int main(){
    vector<int> nums = {1,7,0,0,0,0};
    vector<int> nums2 = {2,3,5,10};
    Solution s;
    s.merge(nums,2,nums2,4);
    for(auto square:nums){
        cout<<square<<" ";
    }
    return 0;
}