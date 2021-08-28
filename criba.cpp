#include<iostream>
#include<math.h>
using namespace std;

bool notPrime[100005];
void criba(int n){
    for(int i=2; i*i<=n; i++){
        if(notPrime[i])continue;
        for(int j=i*i; j<=n; j+=i){
            notPrime[j] = true;
        }
    }
}

int main(){
    int n,m;
    cin >> n;
    criba(n);
    for(int i=1; i<=n; i++){
        if(!notPrime[i])cout << i<<" ";
    }
}
