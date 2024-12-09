#include <iostream>

using namespace std;

struct ListNode { //data structure to create the linked list
    int val;
    ListNode *next; //declaration of the name of the pointer
    ListNode() : val(0), next(nullptr) {} //value for the first empty node
    ListNode(int x) : val(x), next(nullptr) {} //value for the next n nodes
    ListNode(int x, ListNode *next) : val(x), next(next) {} //node pointing in another node
};

class Solution { //class declaration for the function that contains the solution
    public:
        ListNode* middleNode(ListNode* head) {
            if(head==nullptr){ //for a single list of an empty one
                return head;
            }
            int listSize=0;
            ListNode* temp = head;
            ListNode* middleList = new ListNode(0);
            ListNode* middlePtr = middleList;
            while(temp!=nullptr){
                temp = temp->next;
                listSize++;
            }
            temp = head;
            for(int i=0;i<listSize;i++){
                if(i<(listSize/2)){
                    temp = temp->next;
                    continue;
                }
                middlePtr->next = new ListNode(temp->val);
                //cout<<temp->val;
                middlePtr = middlePtr->next;
                temp = temp->next;
            }
            return middleList->next;
        }
        ListNode* middleNode2(ListNode* head) {
            ListNode* slow = head; // pointer to move one place
            ListNode* fast = head; // pointer to move double places
            //the middle node changes every addition of two new nodes
            while(fast != nullptr && fast->next != nullptr) {
                slow = slow->next; //move one node
                //cout<<slow->val;
                fast = fast->next->next; //move two nodes
            }
            return slow;
        }
};

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    Solution function; //object declaration to use the function
    ListNode* answer = function.middleNode2(head);
    return 0;
}

