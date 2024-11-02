#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};

Node* deletenode(Node* head, int pos){
    Node* prev;
    Node* temp=head;
    //list is empty
    if(temp==nullptr){
        return head;
    }
    //pos=1
    if(pos==1){
        head=temp->next;
        free(temp);
        return head;
    }    
    //pos is in middle;
   for(int i=1;i!=pos;i++){
       prev=temp;
       temp=temp->next;
   }
   if(temp!=nullptr){
       prev->next=temp->next;
       free(temp);
   }
   //pos not found
   else{
       cout<<"Data not found";
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
    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    cout<<"original list"<<"\n";
    printlist(head);
    int pos=3;
    head=deletenode(head,pos);
    cout<<"\n new list\n";
    printlist(head);
    // Cleanup remaining nodes
   
 
    return 0;
}
