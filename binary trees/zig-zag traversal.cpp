lc 103
tc-o(n)
sc-o(n)

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL) return result;

        queue<TreeNode*> q;
        q.push(root);
        bool leftright=true;

        while(!q.empty()){
            int size=q.size();
            vector<int> row(size);
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();

                q.pop();

                int index=(leftright)? i: (size-1-i);

                row[index]=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

                
            }
            leftright =!leftright;
                result.push_back(row);
        }
         return result;
    }
};
