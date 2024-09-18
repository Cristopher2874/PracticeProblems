#include <iostream>
#include <vector>

using namespace std;

int n, num;
vector<int> arrayD;

void thanos(vector<int>& n){
    n.erase(n.begin(),(n.end()-n.size()/2));
}

bool ordered(vector<int>& n){
    for(int i = 1; i < n.size(); ++i){
        if(n[i] < n[i-1]){
            return false;
        }
    }
    return true;
}

int main() {
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>num;
        arrayD.push_back(num);
    }
    while(!ordered(arrayD)){
        thanos(arrayD);
    }
    cout <<arrayD.size();
    return 0;
}