gfg

Time: O(H + k) (worst case O(N))
Space: O(H)
int kthLargest(TreeNode* root, int k) {

    stack<TreeNode*> st;

    while (true) {

        while (root) {
            st.push(root);
            root = root->right;
        }

        root = st.top();
        st.pop();

        k--;

        if (k == 0)
            return root->val;

        root = root->left;
    }
}
