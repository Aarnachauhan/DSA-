lc 94
tc-o(n)
sc-O(1)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* curr=root;
        while(curr!=NULL){
            if(curr->left==nullptr){
                inorder.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* prev=curr->left;
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==nullptr){
                    prev->right=curr; //thread 
                    curr=curr->left;
                }
                else{
                    prev->right=nullptr; //cut the thread;
                    inorder.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return inorder;
    }
};
