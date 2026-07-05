
tc-o(N)
sc-o(n)

  /*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr) return head;
        unordered_map<Node* , Node*> mpp;
        Node* newhead=new Node(head->val);

         mpp[head] = newhead;
         
        Node* oldtemp=head->next;
        Node* newtemp=newhead;

        while(oldtemp!=nullptr){
            Node* copynode=new Node(oldtemp->val);

            mpp[oldtemp]=copynode;
           newtemp->next=copynode;
           
           oldtemp=oldtemp->next;
           newtemp=newtemp->next;

        }
        oldtemp=head;
        newtemp=newhead;
        while(oldtemp!=nullptr){
            newtemp->random=mpp[oldtemp->random];
            oldtemp=oldtemp->next;
            newtemp=newtemp->next;
        }
        return newhead;

    }
};
