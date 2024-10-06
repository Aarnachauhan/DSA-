#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int data1) {
        data=data1;
        next=nullptr;
    }
};
void printlist(Node* head) {
    while(head!=nullptr) {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"null";
}
int main()
{
 Node* vip = new Node(10);
    vip->next=new Node(20);
    vip->next->next = new Node(30);
    printlist(vip);
}
