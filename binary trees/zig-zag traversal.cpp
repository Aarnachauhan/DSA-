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
2nd solution
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        bool dir=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> temp;
            while(n){
                TreeNode* frontNode=q.front();
                q.pop();
                temp.push_back(frontNode->val);
                if(frontNode->left){
                    q.push(frontNode->left);
                }
                if(frontNode->right){
                    q.push(frontNode->right);
                }
                n--;
            }
            if(dir==0 && !temp.empty()){
                ans.push_back(temp);
                dir=1;
            }
            else if(dir==1 && !temp.empty()){
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
                dir=0;
            }
        }
        return ans;
    }
};
