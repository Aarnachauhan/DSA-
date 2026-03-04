gfg
class Solution {
  public:
    bool searchKey(Node* head, int key) {
        // Code here
        Node* temp=head;
        while(temp!=nullptr){
            if(temp->data==key) return true;
            else temp= temp->next;
        }
        return false;
    }
};
