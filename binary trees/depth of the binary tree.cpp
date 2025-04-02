lc 104
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
