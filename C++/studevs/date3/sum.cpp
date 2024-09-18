#include <iostream>

using namespace std;

int n, a;

int sumaG(int& n){
    return (n*(n+1))/2;
}

int main() {
    cin>>n;
    for(int i=n;i>0;--i){
        a+=sumaG(i);
    }
    cout << a;
    return 0;
}