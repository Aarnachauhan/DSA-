tc-o(n/2)
sc-o(1)
did this on my ownnnn yay
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==nullptr ) return nullptr;
        if(head->next==nullptr) return nullptr;
        ListNode* slow=head;
        ListNode* prev=head;
        ListNode* fast=head;

        slow=slow->next;
        fast=fast->next->next;
        while(fast!=nullptr && fast->next!=nullptr){
         prev=prev->next;
        slow=slow->next;
        fast=fast->next->next;

        }
        prev->next=slow->next;
        delete(slow);
        return head;
    }
};

leetcode solution

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
      if (!head || !head->next) return nullptr;

        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (prev) prev->next = slow->next;  // Remove middle node
        delete slow;  // Free memory

        return head;
    }
};
