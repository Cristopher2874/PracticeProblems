#include <bits/stdc++.h>
using namespace std;

int getMaximumEatenDishCount(int N, vector<int> D, int K) {
  int numberDish = 0;
  vector<int> prev;
  prev.push_back(D[0]);
  ++numberDish;
  for(int i=0;i<N;i++){
    if(find(prev.begin(),prev.end(),D[i])==prev.end()){
        if(prev.size()<K){
            prev.insert(prev.begin(),D[i]);
            ++numberDish;
        }else{
            prev.pop_back();
            prev.insert(prev.begin(),D[i]);
            ++numberDish;
        }
    }else{
        continue;
    }
  }
  return numberDish;
}

int main() {
    //case 1
    cout<<getMaximumEatenDishCount(6,{1,2,3,3,2,1},1)<<"\n";
    cout<<getMaximumEatenDishCount(6,{1,2,3,3,2,1},2)<<"\n";
    cout<<getMaximumEatenDishCount(7,{1,2,1,2,1,2,1},2)<<"\n";
    return 0;
}

int getMaximumEatenDishCountGPT(int N, vector<int> D, int K) {
    unordered_set<int> recentDishes;
    deque<int> prev;
    int numberDish = 0;

    for(int i = 0; i < N; ++i) {
        // Check if the dish was eaten recently
        if (recentDishes.find(D[i]) == recentDishes.end()) {
            // Dish not eaten recently, we can eat it
            ++numberDish;
            prev.push_front(D[i]);  // Add the dish to the front of the deque
            recentDishes.insert(D[i]);

            // If the deque exceeds the size K, remove the oldest dish
            if (prev.size() > K) {
                int lastDish = prev.back();
                recentDishes.erase(lastDish);
                prev.pop_back();  // Remove from deque
            }
        }
    }

    return numberDish;
}