#include<bits/stdc++.h>
using namespace std;

string n;
vector<string> vowels = {"A","E","I","O","U"};
int idx = 0;

int main() {
    cin>>n;
    for(char letter:n){
        if(find(vowels.begin(),vowels.end(), string(1,letter))!=vowels.end()){    
            idx++;
        }
    }
    cout<<(n.size())-idx<<" "<<idx;
    return 0;
}