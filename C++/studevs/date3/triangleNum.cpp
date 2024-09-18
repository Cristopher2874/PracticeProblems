#include <iostream>
#include <vector>

using namespace std;

int n, num;
vector<int> results;

int sumaG(int& n){
    return (n*(n+1))/2;
}

int main() {
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>num;
        results.push_back(sumaG(num));
    }
    for(int number:results){
        cout <<number<<"\n";   
    }
    return 0;
}