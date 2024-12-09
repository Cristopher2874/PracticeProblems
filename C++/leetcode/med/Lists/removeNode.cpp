#include <iostream>

using namespace std;

struct ListNode {
    int val; //value of the node
    ListNode *next; //pointer to the next node
    ListNode() : val(0), next(nullptr) {} //constructor of the list to inicialize the value to 0 and the pointer to null
    ListNode(int x) : val(x), next(nullptr) {} //construct that takes a value for the node and the next pointer to null
    ListNode(int x, ListNode *next) : val(x), next(next) {} //contructor to inicialize the value of the next pointer indicating the following node
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* edge = head;
        ListNode* target = nullptr;
        for(int i=0; i<n; i++) {
            edge = edge->next;
        }
        while(edge != nullptr){
            edge = edge->next;
            if(target==nullptr) target=head;
            else target=target->next;
        }
        if(target==nullptr){
            return head->next;
        }else{
            target->next = target->next->next;
        }
        return head;
    }
};

int main() 
{
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    ListNode* example = new ListNode(1);
    //example->next = new ListNode(2);
    Solution s;
    ListNode* l3 = s.removeNthFromEnd(l1,2);
    ListNode* test = l3;
    while(test!=nullptr){
        cout<<test->val<<"\n";
        test = test->next;
    }
    return 0;
}