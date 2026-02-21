gfg
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
