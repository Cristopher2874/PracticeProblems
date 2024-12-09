#include <iostream>
#include <vector>

using namespace std;

int maximumWealth(vector<vector<int>>& accounts);

int main(){
    vector<vector<int>> accounts = {{1,5}, {7,2}, {3,2,10}};
    int max = maximumWealth(accounts);
    cout << max << endl;
    return 0;
}

int maximumWealth(vector<vector<int>>& accounts) {
    int max = 0;
    int temp;
    for(int i=0;i<accounts.size();i++){
        temp=0;
        for(int j = 0 ; j < accounts[i].size() ; j++){
            temp+=accounts[i][j];
        }
        if(temp>max) 
            max = temp;
    }
    return max;
}