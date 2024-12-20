tc-O(2n)
sc-o(1)
  Node* reversell(Node* head){
    if(head==NULL || head->next==NULL) return head;
     Node* temp=head;
     Node* prev=NULL;
     while(temp!=NULL){
         Node* front=temp->next; //store the next node in front
         temp->next=prev; //reverse the direction
         prev=temp; 
         temp=front;
     }
  return prev;
}



bool isPalindrome(Node *head)
{
    // write your code here
  if(head==NULL || head->next==NULL) return true ;
  Node* slow=head;
  Node* fast=head;
  while(fast->next!=NULL && fast->next->next!=NULL){
      slow=slow->next; 
      fast=fast->next->next;
      //by the end of this loop, slow will be at mid and fast will be at the second last.
  }
  Node* prev=reversell(slow->next);
  Node* first=head;
  Node* second=prev;
  while(second!=NULL){
      if(first->data!=second->data){
          reversell(prev); //false dene se phele reverse krdo list
          //return as it was 
          return false;
      }
      first=first->next;
      second=second->next;

  }
  reversell(prev); //true dene se phele reverse krdo
  return true;

}
