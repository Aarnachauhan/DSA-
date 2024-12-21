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
