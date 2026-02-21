gfg
tc-o(n)
sc-o(1)
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        if(!head || !(head->next)) return head;
        
        //create the head of one , two , three
        Node* zerohead = new Node(-1);
        Node* onehead = new Node(-1);
        Node* twohead= new Node(-1);
        
        Node *zero=zerohead;
        Node* one= onehead;
        Node* two=twohead;
        Node* temp=head;
        
        while(temp){
            if(temp->data==0){
                zero->next=temp;
                zero=zero->next;
            }
            else if(temp->data==1){
                one->next=temp;
                one=one->next;
                
            }
            else{
                two->next=temp;
                two=two->next;
            }
            temp=temp->next;
        }
        
        zero->next = (onehead->next) ? onehead->next : twohead->next;
    one->next = twohead->next;
    two->next = NULL;

    return zerohead->next;
        
    }
};
