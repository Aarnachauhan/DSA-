lc 700
tc-o(log2n)
sc-o(1)

iterative:
    class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {

        while(root != nullptr){

            if(root->val == val)
                return root;

            if(val < root->val)
                root = root->left;
            else
                root = root->right;
        }

        return nullptr;
    }
};


recursive
tc-o(logn)
sc-O(logn)
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root){
            return nullptr;
        }

        if(root->val==val){
            return root;
        }
        else if(root->val > val){
            return searchBST(root->left,val);
        }
        else{
            return searchBST(root->right,val);
        }
    }
};
