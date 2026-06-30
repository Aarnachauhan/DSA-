lc 1373


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
int ans=0;
   struct NodeValue{
    bool isBST;
    int mini ; 
    int maxi;
    int sum;
   };
   NodeValue dfs(TreeNode* root){
    if(root==nullptr) return {true,INT_MAX, INT_MIN, 0};
    NodeValue left=dfs(root->left);
    NodeValue right=dfs(root->right);

    if(left.isBST && right.isBST && left.maxi <root->val && right.mini > root->val){
        int currsum=left.sum + right.sum + root->val;
        ans=max(ans,currsum);

        return {true,
        min(left.mini , root->val),
        max(right.maxi , root->val),
        currsum};

    }

    return {false,0,0,0};
   }
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
