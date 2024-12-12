/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Input: list1 = [], list2 = []
Output: []

Input: list1 = [], list2 = [0]
Output: [0]

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
*/

#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr&&list2==nullptr){ //for a single list of an empty one
            return list1;
        }else if(list1==nullptr){
            return list2;
        }else if(list2==nullptr){
            return list1;
        }else{
            ListNode* head = new ListNode(0);
            ListNode* headPtr = head;
            ListNode* firstPtr = list1;
            ListNode* secondPtr = list2;
            while(firstPtr!=nullptr&&secondPtr!=nullptr){
                if(firstPtr->val > secondPtr->val){
                    headPtr->next = new ListNode(secondPtr->val);
                    headPtr = headPtr->next;
                    secondPtr = secondPtr->next;
                }else{
                    headPtr->next = new ListNode(firstPtr->val);
                    headPtr = headPtr->next;
                    firstPtr = firstPtr->next;
                }
            }
            if(firstPtr==nullptr){
                while(secondPtr!=nullptr){
                    headPtr->next = new ListNode(secondPtr->val);
                    headPtr = headPtr->next;
                    secondPtr = secondPtr->next;
                }
            }else{
                while(firstPtr!=nullptr){
                    headPtr->next = new ListNode(firstPtr->val);
                    headPtr = headPtr->next;
                    firstPtr = firstPtr->next;
                }
            }
            return head->next;
        }
    }
};

int main(){
    ListNode* m1 = new ListNode(2);
    m1->next = new ListNode(3);
    ListNode* m2 = new ListNode(1);
    //m2->next = new ListNode(4);
    //m2->next->next = new ListNode(5);
    Solution s;
    ListNode* sol = s.mergeTwoLists(m1,m2);
    ListNode* solPtr = sol;
    while (solPtr!=nullptr){
        cout<<solPtr->val;
        solPtr = solPtr->next;
    }
    return 0;
}