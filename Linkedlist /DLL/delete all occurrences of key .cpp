Node * deleteAllOccurrences(Node* head, int k) {
    // Write your code here
    Node* temp=head;
    while(temp!=nullptr){
        if(temp->data==k){
            if(temp==head){
                head=temp->next;
            }
            Node* nextnode=temp->next;
            Node* prevnode=temp->prev;
            if(nextnode!=nullptr) nextnode->prev= prevnode;
            if(prevnode!=nullptr) prevnode->next= nextnode;

            free(temp);
            temp=temp->next;
        }

        else {
            temp = temp->next;
        }
    }

    return head;
}
