class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        // Your code here
        if(head==nullptr){
            return head;
        }
        if(head->next==nullptr){
            return head;
        }
        
        
        DLLNode* last=nullptr;
        DLLNode* current=head;
        while(current!=nullptr){
            last=current->prev;
            
            current->prev=current->next;
            
            current->next=last;
            
            current=current->prev;
            
        }
        return last->prev;
        
        
    }
};
