lc 104


recursive code
tc-o(n)
sc-o(h)

int maxDepth(TreeNode* root) {

    if(root == NULL)
        return 0;

    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);

    return 1 + max(leftHeight, rightHeight);
}

level order traversal code:

class Solution {
public:
    int maxDepth(TreeNode* root) {
        int depth=0;
        if(root==NULL) return depth;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size=q.size();
            depth++;
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);

            }
        }
        return depth;
    }
};
