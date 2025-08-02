gfg
/*
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};
*/

class Solution {
  public:
    Node *addNode(Node *head, int p, int x) {
        // code here
        Node* newnode=new Node(x);
        Node* temp = head;
        
        for(int i=0;i<p;i++){
            if(temp==nullptr) return head;
            temp=temp->next;
        }
        
        newnode->next=temp->next;
        newnode->prev=temp;
        
        if(temp->next!=nullptr){
            temp->next->prev=newnode;
        }
        temp->next=newnode;
        
        return head;
    }
};
