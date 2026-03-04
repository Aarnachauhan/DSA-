gfg

class Solution {
  public:
    int getCount(Node* head) {
        // Code here
        Node* temp=head;
        if(head==nullptr) return 0;
        int cnt=0;
        while(temp->next!=nullptr){
            cnt++;
            temp=temp->next;
            
        }
        return cnt+1;
    }
};
