#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//u can also use class in place of struct.
struct Node{
    //declare
    public:
    int data;
    Node* next;
    //store a pointer
    //initialise 
    public:
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
};

int main() {
  vector<int> a={1,2,5,6,2};
  Node* y=new Node(a[0],nullptr);
  //stores pointer to the memory location
  cout<<y->data;

  cout<<y->next;

    return 0;
}
