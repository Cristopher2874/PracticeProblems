#include<bits/stdc++.h>
using namespace std;

int n,t,l,idx;
unordered_map<int,string> omi;
string abc,temp;

int main() {
    cin>>n;
    cin>>t;
    cin>>abc;
    for(int i = 0; i<t; i++){
        cin>>l;
        cin>>temp;
        //omi[l]=temp;
        if(l>abc.size()||l>4){
            cout<<"0"<<"\n";
        }else{
            for(int j=0;j<l;j++){
                if(!(abc.find(temp[j]))){
                    //cout<<"0"<<"\n";
                    j=l;
                }else idx++;
            }
            if(idx==l){
                cout<<"1"<<"\n";
                idx=0;
            }else{
                cout<<"0"<<"\n";
            }
        }
    }
    return 0;
}