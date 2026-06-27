lc 863

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void markparents(TreeNode* root,  unordered_map<TreeNode*,TreeNode*>& parents){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* node=q.front();
        q.pop();

        if(node->left){
            parents[node->left]=node;
            q.push(node->left);
        }
        if(node->right){
            parents[node->right]=node;
            q.push(node->right);
        }
    }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parents;
        markparents(root,parents);
        queue<TreeNode*> q;
        unordered_map<TreeNode*,bool> vis;
        q.push(target);
        vis[target]=true;
        int dist=0;
        while(!q.empty()){
            int size=q.size();
            if(dist==k) break;

            dist++;
            for(int i=0;i<size;i++){
                 TreeNode* node=q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                   vis[node->left]=true;
                   q.push(node->left);
                }
                if(node->right && !vis[node->right]){
                    vis[node->right]=true;
                    q.push(node->right);
                }
                if(parents[node] && !vis[parents[node]]){
                    vis[parents[node]]=true;
                    q.push(parents[node]);
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()-> val);
            q.pop();
        }
        return ans;
    }
};
