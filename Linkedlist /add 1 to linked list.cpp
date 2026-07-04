
gfg
tc-o(n)
sc-O(1)
Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;

    while(curr){
        Node* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

Node* addOne(Node* head) {

    head = reverse(head);

    Node* temp = head;
    int carry = 1;

    while(temp){
        int sum = temp->data + carry;
        temp->data = sum % 10;
        carry = sum / 10;

        if(carry == 0) break;

        if(temp->next == NULL){
            temp->next = new Node(carry);
            carry = 0;
            break;
        }
        temp = temp->next;
    }

    head = reverse(head);
    return head;
}


optimal : 
tc-o(n)
sc-o(n)
class Solution {
  public:
int helper(Node* head){
    if(head==nullptr) return 1;
    int carry=helper(head->next);
    int sum=head->data +carry;
    head->data=sum%10;
    return sum/10;
    
}
    Node* addOne(Node* head) {
      int carry=helper(head);
      if(carry){
          Node* newhead=new Node(carry);
          newhead->next=head;
          head=newhead;
      }
        return head;
    }
};
