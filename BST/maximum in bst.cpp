no platform

TreeNode* findMax(TreeNode* root) {
    if(root == nullptr || root->right == nullptr)
        return root;

    return findMax(root->right);
}
