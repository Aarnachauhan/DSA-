lc 101 
tc-o(n)
sc-o(n)

bool mirror(BinaryTreeNode<int>*left, BinaryTreeNode<int>* right){
    if(left==nullptr && right==nullptr) return true;
    if(left==nullptr || right==nullptr) return false;
    if(left->data!=right->data) return false;

    return mirror(left->left , right->right) && mirror(left->right , right->left);
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    if(root==nullptr) return true;

    return mirror(root->left,root->right);


}
