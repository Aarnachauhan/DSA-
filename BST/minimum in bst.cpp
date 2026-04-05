gfg

class Solution {
  public:
    int minValue(Node* root) {
        // code here
        Node* curr=root;
        int mini=curr->data;
        while(curr!=nullptr){
          if(curr->data<mini) mini=curr->data;
           curr=curr->left;
        }
        return mini;
    }
};
