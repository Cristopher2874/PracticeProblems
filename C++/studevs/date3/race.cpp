#include <iostream>
#include <vector>

using namespace std;

int m,t,u,f,d,go=0,back=0,timerRoad;
vector<int> roads;
vector<int> backHome;
char road;

int main() {
    cin>>m;
    cin>>t;
    cin>>u;
    cin>>f;
    cin>>d;
    for(int i=0;i<t;++i){
        cin>>road;
        switch (road)
        {
        case 'U':
            roads.push_back(u);
            backHome.push_back(d);
            break;
        case 'F':
            roads.push_back(f);
            backHome.push_back(f);
            break;
        case 'D':
            roads.push_back(d);
            backHome.push_back(u);
            break;
        default:
            break;
        }
    }
    for(int i=0;i<roads.size();++i){
        timerRoad=i;
        go+=roads[i];
        back+=backHome[i];
        if((go+back)>=m){
            break;
        }
    }
    cout<<timerRoad;
    return 0;
}