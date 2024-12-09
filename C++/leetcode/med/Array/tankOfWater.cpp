#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height){
        int h1, h2, dis=height.size()-1, area, maxArea=0, minH,p1=0,p2=0;
        if(height.size()==2){
            return min(height[0],height[1]);
        }else if(height.size()==1||height.empty()){
            return 0;
        }
        while(dis>0){
            p1=0;
            p2=dis;
            while(p2<height.size()){
                h1=height[p1];
                h2=height[p2];
                minH=min(h1,h2);
                maxArea=maxArea<(minH*dis)?(minH*dis):maxArea;
                p1++;
                p2++;
            }
            dis--;
        }
        return maxArea;
    }
    int maxArea2(vector<int>& height){
        int h1, h2, dis=0, maxArea=0, minH,p1=0,p2=height.size()-1;
        while(p1!=p2){
            h1=height[p1];
            h2=height[p2];
            dis=p2-p1;
            if(h1>h2){
                minH=h2;
                maxArea=maxArea<(minH*dis)?(minH*dis):maxArea;
                p2--;
            }else{
                minH=h1;
                maxArea=maxArea<(minH*dis)?(minH*dis):maxArea;
                p1++;

            }
            
        }
        return maxArea;
    }
};

int main(){
    vector<int> nums = {1,8,6,2,5,4,8,3,7}; //49
    //vector<int> nums = {8,7,2,1}; //7
    //vector<int> nums = {4,3,2,1,4}; //16
    //vector<int> nums = {1,2,4,3}; //4
    //vector<int> nums = {2,3,4,5,18,17,6}; //17
    Solution s;
    int tank = s.maxArea2(nums);
    //maxarea is when the result is a square, or when the distance is the highest
    //maximize the height and the distance
    //stop when the max is not in distance or height
    cout<<tank;
    return 0;
}