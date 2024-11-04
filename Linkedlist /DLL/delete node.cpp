#include <iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node{
    public:
    int data;
    Node* next;
    Node* back;
    public:
    Node(int data1,Node* next1,Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }
    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};
Node* convert(vector<int> &a){
    Node* head=new Node(a[0]);
    Node* prev=head;
    for(int i=1;i<a.size();i++){
     Node* temp=new Node(a[i],nullptr,prev);
     prev->next=temp;
     prev=temp;
    }
    return head;
}
void printlist(Node* head){
    Node* temp=head;
   while(temp){
       cout<<temp->data<<"->";
       temp=temp->next;
   }
cout<<"Nullptr";
}
void deletenode(Node* temp){
  Node* prev=temp->back;
  Node* front=temp->next;
  if(front==nullptr){ //last node
      temp->next=nullptr;
      temp->back=nullptr;
      free(temp);
      return;
  }
  prev->next=front;
  front->back=prev;
  
  temp->next=nullptr;
  temp->back=nullptr;
  free(temp);

}
int main() {
 vector<int> a={1,2,3,4,5};
 Node* head=convert(a);
 printlist(head);
 deletenode(head->next->next); //3
 deletenode(head->next);//2
 deletenode(head->next->next->next);//4
 cout<<"\n";
 printlist(head);
 return 0;
}
