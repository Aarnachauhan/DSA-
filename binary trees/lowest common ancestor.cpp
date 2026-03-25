leetcode 236

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr) return nullptr;

        if(root==p || root==q) return root;

        TreeNode* leftn=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightn=lowestCommonAncestor(root->right,p,q);

        if(leftn!=nullptr && rightn!=nullptr){
            return root;
        }
        if(leftn!=nullptr) return leftn;

        return rightn;
    }
};
