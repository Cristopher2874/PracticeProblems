#include<bits/stdc++.h>
using namespace std;

class MyCircularQueue {
public:
    vector<int> line;
    int head=-1, tail=-1, size=0, current=0;
    MyCircularQueue(int k) {
        line.resize(k,-1);
        size=k;
    }
    
    bool enQueue(int value) {
        ++current;
        if(current>size){
            current--;
            return false;
        }
        else{
            line.insert(line.begin(),value);
            line.pop_back();
            int temp = line.size()-1;
            while(line[temp]<0){
                --temp;
            }
            head = line[temp];
            tail = value;
            return true;
        }
    }
    
    bool deQueue() {
        if(current<1) return false;
        else{
            int temp = line.size()-1;
            while(line[temp]<0&&temp>0){
                --temp;
            }
            line[temp] = -1;
            if(temp==0){
                head = -1;
                tail = -1;
            }else{
                head = line[temp-1];
                tail = line[0];
            }
            --current;
            return true;
        }
    }
    
    int Front() {
        return head;
    }
    
    int Rear() {
        return tail;
    }
    
    bool isEmpty() {
        return current==0;
    }
    
    bool isFull() {
        return line.size()==current;
    }
};

int main(){
    vector<string> calls = {"MyCircularQueue","enQueue","enQueue","enQueue","enQueue","Rear","isFull","deQueue","enQueue","Rear"};
    vector<int> params = {3,1,2,3,4,0,0,0,4,0};
    MyCircularQueue* obj = new MyCircularQueue(3);
    bool param_1 = obj->enQueue(1);
    cout<<param_1<<" ";
    bool param_7 = obj->enQueue(2);
    cout<<param_7<<" ";
    bool param_8 = obj->enQueue(3);
    cout<<param_8<<" ";
    bool param_9 = obj->enQueue(4);
    cout<<param_9<<" ";
    int param_4 = obj->Rear();
    cout<<param_4<<" ";
    bool param_6 = obj->isFull();
    cout<<param_6<<" ";
    bool param_2 = obj->deQueue();
    cout<<param_2<<" ";
    bool param_11 = obj->enQueue(4);
    cout<<param_11<<" ";
    int param_42 = obj->Rear();
    cout<<param_42<<" ";
    return 0;
}