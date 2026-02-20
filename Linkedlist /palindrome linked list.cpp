lc 234

brute -
 tc- o(n)
  sc-o(n)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
       
        while(head!=nullptr){
            arr.push_back(head->val);
            head=head->next;
        }

        //to check if array is palindrome or not
        int left=0;
        int right=arr.size()-1;
       while(left<right){
        if(arr[left]!=arr[right]){
            return false;
        }
        left++;
        right--;

       }
       return true;
    }
};

optimal
tc-o(n)
sc-o(1)

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;

        }

        ListNode* prev=nullptr;
        while(slow){
            ListNode* temp=slow->next;
            slow->next=prev;
            prev=slow;
            slow=temp;
        }
        ListNode* first = head;
        ListNode* second = prev;

        while (second) {
            if (first->val != second->val) {
                return false;
            }
            first = first->next;
            second = second->next;
        }

        return true;      
    }
};
