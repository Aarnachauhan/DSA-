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
   cout<<"null";
}


int main() {
 vector<int> a={1,2,3,4,5};
 Node* head=convert(a);
 printlist(head);
    return 0;
}
