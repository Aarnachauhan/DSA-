lc 230
better
class Solution {
public:
void inorder(TreeNode* root, vector<int> &v){
    if(root==nullptr) return;
    inorder(root->left,v);
    v.push_back(root->val);
    inorder(root->right,v);
}
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        inorder(root,v);
        return v[k-1];
    }
};

optimal
