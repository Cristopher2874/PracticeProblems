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
    vector<int> sortedSquaresFail(vector<int>& nums) {
        int n=0,i=0;
        vector<int> squares(nums.size(),0);
        while(nums[n]<0)n++;
        i=n;
        --n;
        nums[i]*=nums[i];
        nums[n]*=nums[n];
        while(n>=0&&i<=nums.size()){
            while(nums[i]>nums[n]){
                squares[i-(n+1)]=nums[n];
                if(n==0&&i==nums.size())return squares;
                n--;
                nums[n]*=nums[n];
            }
            while(nums[i]<nums[n]){
                squares[i-(n+1)]=nums[i];
                if(n==0&&i==nums.size())return squares;
                i++;
                nums[i]*=nums[i];
            }
        }
        return squares;
    }
    vector<int> sortedSquares2(vector<int>& nums) {
        int n = 0, i = nums.size() - 1;
        vector<int> squares(nums.size(), 0);
        int index = nums.size() - 1;

        while (n <= i) {
            if (abs(nums[n]) < abs(nums[i])) {
                squares[index--] = nums[i] * nums[i];
                i--;
            } else {
                squares[index--] = nums[n] * nums[n];
                n++;
            }
        }

        return squares;
    }
};

int main(){
    vector<int> nums = {-51,-4,-3,-2,-1,12,23,45,50};
    Solution s;
    vector<int> num2 = s.sortedSquares2(nums);
    for(int square:num2){
        cout<<square<<" ";
    }
    return 0;
}

/* To call and work with vectors
reverse(negative.begin(), negative.end());
        std::merge(positive.begin(), positive.end(),
           negative.begin(), negative.end(),
           std::back_inserter(result));
        return result;
*/