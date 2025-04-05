
lc 124
tc--o(n) as every node is visited once
sc-o(1)

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        height(root,maxi);
        return maxi;
    }

    int height(TreeNode* root, int &maxi){
        if(root==nullptr) return 0;
        int lh=max(0,height(root->left,maxi)); //here we are using 0 because what if there is -ve node value
        int rh=max(0,height(root->right,maxi));

        maxi=max(maxi,lh+rh+ root->val);
        return max(lh,rh)+ root->val;

    }
};
