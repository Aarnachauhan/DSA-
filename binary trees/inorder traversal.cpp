lc 94
tc,sc-o(n)
class Solution {
public:
void inorder(TreeNode* root,vector<int>&res){
    if(root==NULL) return;

    inorder(root->left,res);
    res.push_back(root->val);
    inorder(root->right,res);
    return;
}
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root,res);
        return res;
    }
};
