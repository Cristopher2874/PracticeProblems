#include<bits/stdc++.h>
using namespace std;

long long n,m,f1,f2,ans;

int main() {
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m;
        f1+=m;
        f2+=(m*m);
    }
    ans = ((f1*f1)-(f2))/2;
    cout << ans;
    return 0;
}

//sum of the products in an array