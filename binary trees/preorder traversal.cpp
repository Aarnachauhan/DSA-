lc  144
tc-0(n)
sc-0(n)

class Solution {
public:
void preorder(TreeNode* root,vector<int> &res){
    if(root==NULL) return;

    res.push_back(root->val);
    preorder(root->left,res);
    preorder(root->right,res);
    return;
}
    vector<int> preorderTraversal(TreeNode* root) {
       vector<int> res;
       preorder(root,res);
       return res;

    }
};
