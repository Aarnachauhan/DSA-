lc 99
tc-o(n)
sc-o(h) //recursive stack

class Solution {
public:
TreeNode* first = NULL;
    TreeNode* middle = NULL;
    TreeNode* last = NULL;
    TreeNode* prev = NULL;
void inorder(TreeNode* root){
    if(root==nullptr) return;
    inorder(root->left);
    if(prev && prev->val > root->val){
        if(first==nullptr){
            first=prev;
            middle=root;
        }
        else last=root;
    }
    prev=root;
    inorder(root->right);
}

    void recoverTree(TreeNode* root) {
        inorder(root);
        if(last){
            swap(first->val,last->val);
        }
        else{
            swap(first->val , middle->val);
        }
    }
};

optimal by morris traversal
