lc 199
tc-o(n)
sc-o(H) where h is the height of the tree.

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        recursion(root,0,res);
        return res;
    }
    void recursion(TreeNode* root,int level,vector<int> &res){
        if(root==nullptr) return;
        if(res.size()==level) res.push_back(root->val);
        recursion(root->right,level+1,res);
        recursion(root->left,level+1,res);
    }
};
