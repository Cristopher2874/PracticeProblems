#include<bits/stdc++.h>
using namespace std;

int idx = 0;

//queue<string> babies;
stack<string> women;

char event;
string client;

int main() {
    cin>>idx;
    for(int i=0;i<idx;i++){
        cin>>event;
        cin>>client;
        if(event == 'B'){
            //babies.push(client);
            //cout<<babies.front()<<" ";
            //babies.pop();
            cout<<client<<" ";
            cout<<women.top();
            women.pop();
            cout<<"\n";
        }else{
            women.push(client);
        }
    }
    return 0;
}