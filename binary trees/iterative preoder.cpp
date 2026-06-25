lc 144
tc-O(n)
sc=O(n) or O(h) where h is height of the tree

note:
So, in a queue, the nodes are processed in the order they are added, which is suitable for level-order traversal, not for preorder traversal.
first take right and put in stack and then take left and put it in stack


class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if(root==NULL) return preorder;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            root=st.top();
            st.pop();
            preorder.push_back(root->val);
            if(root->right!=NULL){
                st.push(root->right);
            }
            if(root->left!=NULL){
                st.push(root->left);
            }
        }
        return preorder;
    }
};
