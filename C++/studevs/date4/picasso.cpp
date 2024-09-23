#include<bits/stdc++.h>
using namespace std;

long long n,m,f1,f2;

long long numberOfRectangles(long long num) {
    long long idx=0;
    while(num>0&&num%2==0){
        num=num/2;
        ++idx;
    }
    if(idx==0) return 1;
    return idx;
}

int main() {
    cin>>n>>m;
    f1=numberOfRectangles(n);
    f2=numberOfRectangles(m);
    if(f1==f2){
        cout << (f1*f2);
    }else cout << (f1*f2)*2;
    return 0;
}