gfg
recursive way
tc-o(n)
sc-o(n)
note:
why we chose -1 insted of 0;
for leaf nodes = 1+max(-1,-1) will give 0
but if we take 0 , even leaf node height will be 1;


class Solution {
  public:
    // Function to find the height of a binary tree.
    int height(Node* node) {
        // code here
        if(node==NULL) return -1;
        
        int l=height(node->left);
        int r=height(node->right);
        
        return 1+ max(l,r);
