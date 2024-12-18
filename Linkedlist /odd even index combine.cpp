tc-0(n/2) *2 approx= o(n)
sc-o(1)

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr  || head->next==nullptr) {
            return head;
        }
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* evenhead=head->next;

        while(even!=nullptr && even->next!=nullptr){
            odd->next=odd->next->next;
            even->next=even->next->next;

            odd=odd->next;
            even=even->next;
        }
        odd->next=evenhead;
        return head;
    }
};
