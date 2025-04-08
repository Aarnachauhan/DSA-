
tc-o(n)
sc-o(n) ie. for screw tree( all nodes are at the left ) . we can also say o(h) where h is the height of the tree

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* node=root;
        vector<int> ino;
        while(true){
            if(node!=nullptr){
                st.push(node);
                node=node->left;
            }
            else{
                if(st.empty()==true) break;
                node=st.top();
                st.pop();
                ino.push_back(node->val);
                node=node->right;
            }
        }
        return ino;
    }
};
