Node* insertpos(Node* head, int val,int k){
    if(head==nullptr){
        return head;
    }
    if(k==1){
        return new Node(val,head);
    }
    int cnt=0;
    Node* temp=head;
    while(temp!=nullptr){
        cnt++;
        if(cnt==k-1){
            Node* x=new Node(val, temp->next);
            temp->next=x;
            break;
        }
    temp=temp->next;
     
    }
return head;
    
}
