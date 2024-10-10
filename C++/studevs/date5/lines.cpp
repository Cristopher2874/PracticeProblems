#include<bits/stdc++.h>
using namespace std;

int idx = 0,lin;

queue<string> line1;
stack<string> line2;

char event;
string client;

int main() {
    cin>>idx;
    for(int i=0;i<idx;i++){
        cin>>event;
        cin>>lin;
        if(event == 'E'){
            cin>>client;
            if(lin == 1){
                line1.push(client);
            }else{
                line2.push(client);
            }
        }else{
            if(lin == 1 && !line1.empty()){
                cout<<line1.front();
                line1.pop();
            }else if(!line2.empty()){
                cout<<line2.top();
                line2.pop();
            }else cout<<"";
        }
            cout<<"\n";
    }
    return 0;
}