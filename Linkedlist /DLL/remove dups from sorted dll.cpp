gfg
class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        // Your code here
        if(head==nullptr || head->next==nullptr) return head;
        Node *curr=head;
        while(curr->next!=nullptr){
            if(curr->next->data==curr->data){
                Node *dup=curr->next;
                curr->next=dup->next;
               if(dup->next != NULL) {
                dup->next->prev = curr;
            }
            delete dup;
            }
            else{
                curr=curr->next;
            }
            
        }
        return head;
    }
};
