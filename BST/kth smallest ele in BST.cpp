lc 230
better
class Solution {
public:
void inorder(TreeNode* root, vector<int> &v){
    if(root==nullptr) return;
    inorder(root->left,v);
    v.push_back(root->val);
    inorder(root->right,v);
}
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        inorder(root,v);
        return v[k-1];
    }
};

optimal - morris + cnt
tc-o(n)
sc-o(1)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    int helper(TreeNode* root, int k, int& preOrder)
    {
        if(root == NULL) return -1;

        if(root->left)
        {
            int leftAns = helper(root->left, k, preOrder);

            if(leftAns != -1) return leftAns;
        }

        if(preOrder + 1 == k) return root->val;
        
        preOrder = preOrder + 1;

        if(root->right)
        {
            int rightAns = helper(root->right, k, preOrder);

            if(rightAns != -1) return rightAns;
        }

        return -1;
    }

    int kthSmallest(TreeNode* root, int k) {
        int preOrder = 0;

        return helper(root, k , preOrder);
    }
};
