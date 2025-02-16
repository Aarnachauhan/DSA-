lc 110
tc-O(n)
sc-o(n)

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfsheight(root)!=-1; //true else false
    }
    int dfsheight(TreeNode* root){
        if(root==NULL) return 0;
        int lh=dfsheight(root->left);
        if(lh==-1) return -1;
        int rh=dfsheight(root->right);
        if(rh==-1) return -1;

        if(abs(lh-rh)>1) return -1;
        return max(lh,rh) +1;
    }
};
