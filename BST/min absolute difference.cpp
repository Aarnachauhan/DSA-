lc 530

better:
tc-o(n)
sc-o(n)

class Solution {
public:
void inorder(TreeNode* root, vector<int> &res){
    if(root==nullptr) return;
    inorder(root->left,res);
    res.push_back(root->val);
    inorder(root->right,res);

}
    int getMinimumDifference(TreeNode* root) {
        vector<int> res;
        inorder(root,res);
        int ans=INT_MAX;
        for(int i=1;i<res.size();i++){
            ans=min(ans,res[i]-res[i-1]);
        }
      return ans;
    }
};


optimal:
tc-o(n)
sc-o(h) //recursion space 

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
int mindiff=INT_MAX;
TreeNode* prev=nullptr;

void inorder(TreeNode* root){
    if(!root) return;
    inorder(root->left);
    if(prev) mindiff=min(mindiff,abs(root->val - prev->val));
    prev=root;
    inorder(root->right);
}
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return mindiff;
    }
};
