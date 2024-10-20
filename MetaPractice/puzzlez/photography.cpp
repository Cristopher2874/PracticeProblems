#include <bits/stdc++.h>
using namespace std;

int getArtisticPhotographCount(int N, string C, int X, int Y) {
  int count = 0;
  int right=0,left=0,pCountR=0,bCountR=0,pCountL=0,bCountL=0;
  for(int i=1;i<N-1;++i){
    if(C[i]=='A'){
        right = i+Y>N? N : i+Y;
        left = i-Y<0? 1 : i-Y;
        while(right>i&&left<i&&(right-i)>=X&&(i-left)>=X){
            if(C[right]=='B'){
                ++bCountR;
            }else if(C[right]=='P'){
                ++pCountR;
            }
            if(C[left]=='B'){
                ++bCountL;
            }else if(C[left]=='P'){
                ++pCountL;
            }
            --right;
            ++left;
        }
        count += ( min(pCountR,bCountL) + min(pCountL,bCountR));
        right=0;left=0;pCountR=0;bCountR=0;pCountL=0;bCountL=0;
    }
  }
  return count;
}

int main() {
    //case 1
    cout<<getArtisticPhotographCount(5,"APABA",1,2)<<"\n";
    cout<<getArtisticPhotographCount(5,"APABA",2,3);
    cout<<getArtisticPhotographCount(8,".PBAAP.B",1,3);
    return 0;
}