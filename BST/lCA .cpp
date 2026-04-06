lc 235
tc-o(height) 
sc-o(1)


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root){
            if(p->val > root->val && q->val > root->val) root=root->right;
            else if(p->val < root->val && q->val < root->val){
                root=root->left;
            }
            else{
                return root;
            }
        }
        return nullptr;
    }
};
