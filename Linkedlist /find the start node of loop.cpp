class Solution {
public:
//intuition- detect loop and then put slow to head and move slow and fast together
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) { //there is loop and it is collision point
                slow=head; //let fast stand on collision point
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                    //at a moment slow and fast will be at same point
                }
                return slow;
            }
        }
        return nullptr;
    }
};
