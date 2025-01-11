/*
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

Input: head = [1,1,2]
Output: [1,2]

Input: head = [1,1,2,3,3]
Output: [1,2,3]

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.

LINKED LIST
*/

#include <bits/stdc++.h>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next){}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr){ //for a single list of an empty one
                return head;
        }
        ListNode* temp = head; //to iterate through the list without losing the original head
        //Temp is the pointer to current node, head is pointer to the first node
        //Changes of temp->next will change head->next
        //Temp is another pointer to the same memory reference
        while(temp != nullptr && temp->next != nullptr){
            if(temp->val == temp->next->val){ //actual value is the same as the next one
                temp->next = temp->next->next; //skip the next node
                //pointer to next node is assigned to the pointer of the next node of the next node
            }else{
                temp = temp->next; //move to the next node
            }
        }
        return head;
    }
};

int main(){
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    ListNode* temp = s.deleteDuplicates(head);
    while(temp != nullptr){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    return 0;
}