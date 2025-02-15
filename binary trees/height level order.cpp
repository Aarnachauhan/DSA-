lc  104
level order way



 int maxDepth(TreeNode* root) {
        int depth=0;
        if(root==NULL) return depth; // tree is empty 

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size=q.size(); //this stores the current size of the queue 
          //this represents the no of nodes in current level of the tree.
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
