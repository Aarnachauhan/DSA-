lc 222
better solution:
tc-o(n)
sc-o(h)
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;

        return 1+ countNodes(root->left) + countNodes(root->right);
    }
};


optimal solution:
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int count=0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            count++;

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);

        }
        return count;
    }
};
