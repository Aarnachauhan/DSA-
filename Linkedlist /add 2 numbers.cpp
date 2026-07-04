note:whenever we need to create a new list. always create a dummy node. ALWAYS.
tc- 0(max(N1,N2))
SC- 0(MAX(N1,N2)) // this is used to store the data and not to solve the question.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyhead=new ListNode(0);
        ListNode* tail=dummyhead;
        int carry=0;

        while(l1 != nullptr || l2!=nullptr || carry !=0){
            int digit1=(l1 !=nullptr) ? l1->val : 0;
            int digit2=(l2 !=nullptr) ? l2->val : 0;

            int sum=digit1 + digit2 + carry;
            int digit=sum%10;
            carry=sum/10;

            ListNode* newnode= new ListNode(digit);
            tail->next=newnode;
            tail=tail->next;

            l1=(l1!=nullptr) ? l1 -> next: nullptr;
            l2=(l2!=nullptr) ? l2 -> next : nullptr;
        }

        ListNode* res=dummyhead->next;
        delete dummyhead;
        return res;
    }
};
