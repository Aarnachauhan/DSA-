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
    cout<<"Null";
}
Node* deletelast(Node* thread){
    if(thread==nullptr){
        return nullptr;
    }
    if(thread->next==nullptr){
        delete thread;
        return nullptr;
    }
    Node *curr=thread;
    while(curr->next->next!=nullptr){
        curr=curr->next;
    }
    delete(curr->next);
    curr->next=nullptr;
    return thread;
}


int main() {
    Node* thread=new Node(9);
    thread->next=new Node(10);
    thread->next->next=new Node(11);
    printlist(thread);
    thread=deletelast(thread);
    printlist(thread);

    return 0;
}
