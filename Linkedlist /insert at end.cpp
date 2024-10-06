#include <iostream>
using namespace std;
struct Node{
   int data;
   Node* next;
   Node(int data1){
       data=data1;
       next=nullptr;
   }
};
void printlist(Node* head){
    Node* curr=head;
    for(curr=head;curr!=nullptr;curr=curr->next){
        cout<<curr->data<<"->";
    }
    cout<<"Null"<<endl;
}


 Node* insertend(Node* head,int data){
   Node* newnode=new Node(data);
   if(head==nullptr){
       return newnode;
   }
   Node* lastnode=head;
   while(lastnode->next!=nullptr){
       lastnode=lastnode->next;
   }
  lastnode->next=newnode;
  return head;
}

int main() {
    Node* head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    cout<<"linked list before";
    printlist(head);
    head=insertend(head,3);
    cout<<"linked list after";
   printlist(head);

    return 0;
}
