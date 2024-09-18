#include <iostream>
#include <vector>

using namespace std;

int n, m, a, b, idx;

int main() {
    cin>>n;
    cin>>m;
    cin>>a;
    cin>>b;
    char map_game[n][m];
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>map_game[i][j];
            if(map_game[i][j] == 'X'){idx++;}
        }
    }
    if(idx!=0){
        cout << 2;
    }else cout << n-a;
    return 0;
}