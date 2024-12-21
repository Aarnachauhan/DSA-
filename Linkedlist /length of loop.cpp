brute; hashing
hashing is used to memorize the node/element .
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int lengthOfLoop(Node *head) {
    // Write your code here
unordered_map<Node* ,int> mpp;
Node* temp=head;
int timer=0;
while(temp!=nullptr){
    if(mpp.find(temp)!=mpp.end()){
        int length=timer-mpp[temp];
        return length;
    }
    //store the current node and its value as timer
    mpp[temp]=timer;
    temp=temp->next;
    timer++;
}
return 0;
}

optimal
class Solution {
  public:
    // Function to find the length of a loop in the linked list.
 int findlength(Node* slow,Node* fast){
   int cnt=1;
   fast=fast->next;
   while(slow!=fast){
    cnt++;
    fast=fast->next;
      
   }
   
  return cnt;
     
 }   
    
  
    
    
    int countNodesinLoop(Node *head) {
        // Code here
        Node* slow=head;
        Node* fast=head;
        while(fast!=nullptr&& fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if (slow==fast) return findlength(slow,fast);
        }
        return 0;
    }
};


















