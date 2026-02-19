gfg

class Solution {
    
  public:
  int findlength(Node* slow , Node* fast){
      int cnt=1;
      fast=fast->next;
      while(slow!=fast){
          cnt++;
          fast=fast->next;
          
      }
      return cnt;
  }
    int lengthOfLoop(Node *head) {
        // code here
        Node* slow=head;
        Node* fast=head;
        
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return findlength(slow,fast);
        }
        return 0;
    }
};
