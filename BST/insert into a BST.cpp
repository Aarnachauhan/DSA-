lc 701



class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr) return new TreeNode(val);

        TreeNode* temp=root;
        while(root){
            if(root->val<=val){
                if(root->right!=nullptr) root=root->right;
                else {
                    root->right=new TreeNode(val);
                    break;
                }
            }
            else{
                if(root->left!=nullptr){
                    root=root->left;
                }
                else{
                    root->left=new TreeNode(val);
                    break;
                }
            }
           
        }
        return temp;
    }
};
