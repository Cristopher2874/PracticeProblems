#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(int num:nums){
            string temp = to_string(num);
            if(temp.size()%2==0) count++;
            cout<<temp.size()<<" "<<num<<"\n";
        }
        return count;
    }
};

int main(){
    vector<int> nums = {12,345,23,21,456,23412,4565,65452};
    Solution s;
    cout<<s.findNumbers(nums);
    return 0;
}