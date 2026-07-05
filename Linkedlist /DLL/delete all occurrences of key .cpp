class Solution {
  public:

    // Function to delete a specified node from the linked list
    Node* deleteAllOccurOfX(Node* head, int x) {

        // code here
        Node* temp=head;
        while(temp!=nullptr){
            if(temp->data==x){
                Node* nextnode=temp->next;
                Node* prevnode=temp->prev;
                
                if(temp==head){
                    head=nextnode;
                }
                
                if(prevnode){
                    prevnode->next=nextnode;
                }
                
                if(nextnode){
                    nextnode->prev=prevnode;
                }
                delete temp;
                temp=nextnode;
            }
            else{
                temp=temp->next;
            }
        }
        return head;
    }
};
