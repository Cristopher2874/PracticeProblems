#include <iostream>
#include <vector>

using namespace std;

int numberOfSteps(int num);

int main(){
    int n = 3;
    cout<<numberOfSteps(14);
    return 0;
}

int numberOfSteps(int num) {
    int idx=0;
    while(num>0){
        if(num%2 == 0){
            num = num/2;
        }else{
            num-=1;
        }
        ++idx;
    }
    return idx;
}

int numberOfSteps(int num) {
    int idx=0;
    while(num>0){
        if((num&1) == 0){ //& to compare using a bitmask
            num >>= 1; //shift the number by one position in binary
        }else{
            num-=1;
        }
        ++idx;
    }
    return idx;
}