/*
Given an array arr of integers, check if there exist two indices i and j such that :

i != j
0 <= i, j < arr.length
arr[i] == 2 * arr[j]

Input: arr = [10,2,5,3]
Output: true
Explanation: For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]

Input: arr = [3,1,7,11]
Output: false
Explanation: There is no i and j that satisfy the conditions.
 
Constraints:
2 <= arr.length <= 500
-103 <= arr[i] <= 103
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        vector<int> rest(arr.size(), false);
        for(int i = 0; i<arr.size(); ++i){
            rest[i] = arr[i]*2;
            auto it = find(arr.begin(), arr.end(), rest[i]); //iterator
            if(it!=arr.end() && distance(arr.begin(), it) != i){ //if element is found and it is not the same element
                return true;
            }
        }
        return false;
    } //time complexity: O(n^2) and space complexity: O(n)
    
    bool bestoSolution(vector<int>& arr){
        set<int> seen;
        for(auto i: arr){
            if(seen.count(i*2) || (i%2==0 && seen.count(i/2))){
                return true;
            }
            seen.insert(i);
        }
        return false;
    }//time complexity: O(n) since set search is constant
};

int main(){
    Solution s;
    vector<int> arr = {-2,0,10,-19,4,6,-8};
    cout<<s.bestoSolution(arr)<<endl;
    return 0;
}