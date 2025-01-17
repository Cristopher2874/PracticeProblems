/*
Given an array of integers arr, return true if and only if it is a valid mountain array.

Recall that arr is a mountain array if and only if:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

Input: arr = [0,3,2,1]
Output: true

Constraints:

1 <= arr.length <= 104
0 <= arr[i] <= 104
*/
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<=2) return false;
        if(arr[0]>=arr[1]) return false;
        if(arr[(arr.size()-1)]>=arr[(arr.size()-2)]) return false;
        int peak = arr[1];
        int down = arr[0];
        int i = 2;
        while(peak<arr[i] && i<arr.size()){
            peak = arr[i];
            ++i;
        }
        if(peak == arr[i]) return false;
        down=peak;
        while(peak>arr[i]&&i<arr.size()-1&&down>arr[i]){
            down=arr[i];
            ++i;
        }
        return i==arr.size()-1;
    } //time complexity: O(n) space complexity: O(1)

    bool bestSolution(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return false;

        int i = 0;

        // Ascend to the peak
        while (i + 1 < n && arr[i] < arr[i + 1]) {
            i++;
        }

        // Peak can't be the first or last element
        if (i == 0 || i == n - 1) return false;

        // Descend from the peak
        while (i + 1 < n && arr[i] > arr[i + 1]) {
            i++;
        }

        return i == n - 1;
    }
};

int main(){
    Solution s;
    vector<int> arr = {1,2,3,0,1};
    cout<<s.validMountainArray(arr);
    return 0;
}