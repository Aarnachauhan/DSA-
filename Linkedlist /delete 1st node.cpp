#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node*next;
    Node(int data1) {
        data=data1;
        next=nullptr;
    }
};
void print(Node* head){
   while(head!=nullptr){
       cout<<head->data<<"->";
       head=head->next;
   }
   cout<<endl;
}

int main() {
    Node* head = new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    print(head);
    Node* curr = head;
    head=head->next;
    delete(curr);
    while(head!=nullptr) {
        cout<<head->data<<" ";
        head=head->next;
    }
}
