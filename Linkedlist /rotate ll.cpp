leetcode 61 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr || k==0) return head;
        ListNode* tail=head;
        int n=1;
        while(tail->next!=nullptr){
            n++;
            tail=tail->next;
        }

        k=k%n;
        if(k==0) return head;
        //make node circular
        tail->next=head;
        //find new tail
        int steps=n-k-1;
        ListNode* newtail=head;

        while(steps--){
            newtail=newtail->next;
        }
        ListNode* newhead=newtail->next;
        newtail->next=nullptr;

        return newhead;

        
    }
};
