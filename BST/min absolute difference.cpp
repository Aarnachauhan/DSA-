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
