#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int data1){
      data=data1;
      next=nullptr; 
    }
};
Node* convert(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* move=head;
    int n=arr.size();
    for(int i=1;i<n;i++){
        Node* temp=new Node(arr[i]);
        move->next=temp;
        move=temp;
    }
    return head;
}
void printlist(Node* head){
    Node* first=head;
    while(first!=nullptr){
        cout<<first->data<<"->";
        first=first->next;
    }
    cout<<"null";
}
Node* inserthead(int val,Node* head){
  //return new Node(head,val);
  Node* newnode=new Node(111);
   newnode->next = head;
    head = newnode;
}

int main() {

    vector<int> arr={12,34,56,23};
    Node*head=convert(arr);
    printlist(head);
    cout<<"\n";
    head=inserthead(111,head);
    printlist(head);
    return 0;
}
