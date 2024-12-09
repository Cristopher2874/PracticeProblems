#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(nums2.empty()) return;
        m--;
        n--;
        if(m<0) m=0;
        if(n<0) n=0;
        while(n>=0){
            while(nums1[m]>=nums2[n]&&m>=0&&n>=0){
                m--;
                if(m<0) break;
            }
            while(nums1[m]<=nums2[n]&&m>=0&&n>=0){
                nums1.insert(nums1.begin()+m+1,nums2[n]);
                nums1.pop_back();
                n--;
                if(n<0) break;
            }
        }
    }
    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};

int main(){
    vector<int> nums = {0};
    vector<int> nums2 = {1};
    Solution s;
    s.merge(nums,0,nums2,1);
    for(auto square:nums){
        cout<<square<<" ";
    }
    return 0;
}