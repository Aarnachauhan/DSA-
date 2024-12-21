


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1=headA;
        ListNode* temp2=headB;

        while(temp1 != temp2){
           temp1=temp1==nullptr?headB:temp1->next; //jab ek ka nullptr aa jaye toh dusri ll k head per bhej do
           temp2=temp2==nullptr?headA:temp2->next; //same
        }
        return temp1;
    }
};
