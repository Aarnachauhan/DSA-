gfg, lc
tc-O(n)
sc-o(n)

//height is the no of nodes

class Solution {
  public:
    int diameter(Node* root) {
        // Your code here
        int dia=0;
        height(root,dia);
        return dia;
    }
    private:
    int height(Node* root, int &dia){
        if(root==NULL) return 0;
        int l=height(root->left,dia);
        int r=height(root->right,dia);
        dia=max(dia,l+r);
        return 1+max(l,r);
    }
