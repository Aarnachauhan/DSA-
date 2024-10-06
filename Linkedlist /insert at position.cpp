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
Node* insertpos(Node* head,int data,int pos){
    if(pos<1){
        return head;
    }
    Node* curr=head;
    if(curr==nullptr){
        return head;
    }
    
    
    for( int i=1;i<=pos-2&&curr!=nullptr;i++){
        curr=curr->next;
    }
    Node* newnode=new Node(data);
    newnode->next=curr->next;
    curr->next=newnode;
    return head;
}

int main() {
    Node* head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    cout<<"linked list before";
    printlist(head);
    
    head=insertpos(head,3,2);
    cout<<"linked list after";
   printlist(head);

    return 0;
}
