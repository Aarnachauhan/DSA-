lc 114
better solution
tc-o(n)
sc-o(n)
class Solution {
public:

void preorder(TreeNode* node, vector<TreeNode*> &pre){
    if(node==nullptr) return;

    pre.push_back(node);
    preorder(node->left,pre);
    preorder(node->right,pre);
}
    void flatten(TreeNode* root) {
        vector<TreeNode*> ans;
        preorder(root,ans);
        int n=ans.size();
        for(int i=0;i<n-1;i++){
           ans[i]->left=nullptr;
           ans[i]->right=ans[i+1];
        }
        if(!ans.empty()){
            ans.back()->left=nullptr;
            ans.back()->right=nullptr;
        }
    }
};

optimal
