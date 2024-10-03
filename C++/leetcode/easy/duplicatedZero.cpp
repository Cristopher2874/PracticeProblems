#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0){
                arr.insert(arr.begin()+i+1,0);
                arr.pop_back();
                i++;
            }
        }
    }
};

int main(){
    vector<int> nums = {0,0,1,3,4,0,5,6,7,8,9};
    Solution s;
    s.duplicateZeros(nums);
    for(auto square:nums){
        cout<<square<<" ";
    }
    return 0;
}