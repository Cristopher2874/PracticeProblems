#include<bits/stdc++.h>
using namespace std;

int n,m,l,p;

int main() {
    cin>>n>>m>>l>>p;
    int nums = ((m-n)+1);
    int str = ((p-l)+1);
    int ans=1;
    int strans=1;
    for(int i=0;i<3;i++){
        ans *= nums;
        nums--;
    }
    for(int i=0;i<2;i++){
        strans *= str;
        str--;
    }
    cout << ans*strans;
    return 0;
}