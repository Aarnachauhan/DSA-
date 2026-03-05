gfg
/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    Node* delPos(Node* head, int x) {
        // code here
        if(!head) return nullptr;
        //1st node
        if(x==1){
            head=head->next;
            head->prev=nullptr;
            return head; 
        }
        
        Node *temp=head;
        int cnt=1;
        while(temp && cnt<x){
            temp=temp->next;
            cnt++;
        }
        if(temp==nullptr) return head;
        temp->prev->next=temp->next;
        
        if(temp->next){
            temp->next->prev= temp->prev;
        
        }
        return head;
        
    }
};
