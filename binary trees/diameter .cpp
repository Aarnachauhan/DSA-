gfg, lc
tc-O(n)
sc-o(n)

//height is the no of nodes
class Solution {
public:
int height(TreeNode* node , int &dia){
    if(node==nullptr) return 0;
    int left=height(node->left,dia);
    int right=height(node->right,dia);
     dia=max(dia,left+right);
     return 1+ max(left,right);
    
}
    int diameterOfBinaryTree(TreeNode* root) {
        int dia=0;
        height(root,dia);
        return dia;
    }
};
