lc 98

better 
inorder traversal
class Solution {
public:
TreeNode* prev=nullptr;
bool inord(TreeNode* node){
    if(node==nullptr) return true;
    if(!inord(node->left)) return false;
    if(prev && prev->val >= node->val) return false;
    prev=node;
    return inord(node->right) ;

}
    bool isValidBST(TreeNode* root) {
        return inord(root);
    }
};



optimal
tc-o(n)
sc-o(1)

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return valid(root,LONG_MIN , LONG_MAX);
    }

private:
bool valid(TreeNode* node ,long minimum , long maximum){
    if(!node) return true;

    if(!(node->val > minimum && node->val < maximum)) return false;

    return valid(node->left , minimum , node->val ) && valid(node->right,node->val , maximum);
}
};

