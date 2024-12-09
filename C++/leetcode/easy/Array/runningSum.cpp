#include <iostream>
#include <vector>
using namespace std;

vector<int> runningSum(vector<int>& nums);
vector<int> nums = {1,2,3,4,5};

int main() {
  vector<int> sum = runningSum(nums);
  for(size_t i=0;i<sum.size();++i){
    cout << sum[i] << " ";
  }
  return 0;
}

vector<int> runningSum(vector<int>& nums){ //less time more memory
    if(nums.size()==1) return nums;
    int sum;
    vector<int> result;
    for(size_t i=0; i<nums.size();++i){
        sum += nums[i];
        result.push_back(sum);
    }
    return result;
}

vector<int> runningSum(vector<int>& nums) { //more time, less memory
        vector<int> running_sum;
        int sum=0;
        for(int num : nums){
            sum += num;
            running_sum.push_back(sum);
        }
        return running_sum;
}