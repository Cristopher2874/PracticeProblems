#include <iostream>

using namespace std;

struct ListNode {
    int val; //value of the node
    ListNode *next; //pointer to the next node
    ListNode() : val(0), next(nullptr) {} //constructor of the list to inicialize the value to 0 and the pointer to null
    ListNode(int x) : val(x), next(nullptr) {} //construct that takes a value for the node and the next pointer to null
    ListNode(int x, ListNode *next) : val(x), next(next) {} //contructor to inicialize the value of the next pointer indicating the following node
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

int main() 
{
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    ListNode* l3 = addTwoNumbers(l1,l2);
    cout<<0;
    return 0;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* sum = new ListNode(0); //list  to follow the operations
    ListNode* sumPtr = sum;  //pointer that moves thought the list
    int excedent=0;

    while (l1 != nullptr || l2 != nullptr) {
        int a,b;
        if(l1 != nullptr){ //check if there are valid nodes in continuation
            a = l1->val; //get the value of the node
        }else a = 0;
        if(l2 != nullptr){
            b = l2->val;
        }else b = 0;

        int sum = a+b+excedent; //sum the values
        excedent = sum / 10; //calculate the excedent of the sum
        sumPtr->next = new ListNode(sum%10); //create a new node from the previos with the value of the sum
        sumPtr = sumPtr->next; //move forward the pointer

        if(l1!=nullptr) l1 = l1->next; //move the pointers from the lists
        if(l2!=nullptr) l2 = l2->next;
    }

    if(excedent>0){
        sumPtr->next = new ListNode(excedent);
    }

    return sum->next;
}