#include <iostream>
#include <vector>

using namespace std;

vector<string> fizzBuzz(int n);

int main(){
    int n = 3;
    vector<string> answer = fizzBuzz(n);
    for(string word:answer){
        cout << word << endl;
    }
    return 0;
}

vector<string> fizzBuzz(int n) {
    vector<string> fizzBuzzRes;
    for(int i=1;i<=n;++i){
        if(i % 3 == 0 && i % 5 == 0){
            fizzBuzzRes.push_back("FizzBuzz");
        }else if(i % 3 == 0){
            fizzBuzzRes.push_back("Fizz");
        }else if(i % 5 == 0){
            fizzBuzzRes.push_back("Buzz");
        }else fizzBuzzRes.push_back(to_string(i));
    }
    return fizzBuzzRes;
}