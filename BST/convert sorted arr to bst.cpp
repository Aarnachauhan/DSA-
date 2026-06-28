lc 108

tc-o(logn)
sc-o(logn)

class Solution {
public:
TreeNode* solve(vector<int> & nums, int left , int right){
    if(left>right) return nullptr;

    int mid=(left+right)/2;
    TreeNode* node=new TreeNode(nums[mid]);
    node->left=solve(nums,left,mid-1);
    node->right=solve(nums,mid+1,right);
    return node;

}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums,0, nums.size()-1);
    }
};
