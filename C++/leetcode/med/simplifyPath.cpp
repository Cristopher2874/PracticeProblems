#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        if(path.size()==1)return path;
        stack<char> finalPath;
        string temp="";
        int idx=0,fast;
        finalPath.push(path[path.size()-1]);
        for(int i = path.size()-1;i>=0;--i){
            if(path[i]=='.'){
                int temp = i;
                while(temp>=0 && path[temp]=='.'){
                    temp--;
                    ++idx;
                }
            }
            if(finalPath.top()=='.'&&path[i]!='.'&&idx<3){
                finalPath.pop();
                while(path[i]=='/'&&i>0){
                    i--;
                }
                idx=0;
            }else if(finalPath.top()=='.'&&path[i]=='.'&&path[i-1]!='.'&&idx<3){
                finalPath.pop();
                i--;
                while(path[i]=='/'&&i>0){
                    i--;
                }
                while(path[i]!='/'&&i>0){
                    i--;
                }
                idx=0;
            }
            if(path[i]=='/'&&finalPath.top()=='/'){
                continue;
            }
            finalPath.push(path[i]);
        }
        while(!finalPath.empty()){
            temp+=finalPath.top();
            finalPath.pop();
        }
        if(temp.size()>1)temp.pop_back();
        return temp;
    }
    string test(string path){
        stack<string> pathSection;
        string res="";
        for(int i=0;i<path.size();i++){
            if(path[i]=='/'){
                continue;
            }
            string temp="";
            while(i<path.size()&&path[i]!='/'){
                temp+=path[i];
                i++;
            }
            if(temp=="."){
                continue;
            }else if(temp==".."){
                if(!pathSection.empty()){
                    pathSection.pop();
                }
            }else{
                pathSection.push(temp);
            }
            
        }
        while(!pathSection.empty()){
            res = "/" + pathSection.top()+res;
            pathSection.pop();
        }
        if(res.size()==0) return "/";
        return res;
    }
};

int main(){
    string s1 = "/.../a/../b/c/../d/./";
    Solution s;
    cout<<s.test(s1);
    return 0;
}