lc 199

better:
tc-o(n)
    sc-o(n)
class Solution {
public:

    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;

        if(root==nullptr)
            return ans;

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){

            int size=q.size();

            for(int i=0;i<size;i++){

                TreeNode* node=q.front();
                q.pop();

                if(i==size-1)
                    ans.push_back(node->val);

                if(node->left)
                    q.push(node->left);

                if(node->right)
                    q.push(node->right);
            }
        }

        return ans;
    }
};


optimal:
tc-o(n)
sc-o(H) where h is the height of the tree.

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        recursion(root,0,res);
        return res;
    }
    void recursion(TreeNode* root,int level,vector<int> &res){
        if(root==nullptr) return;
        if(res.size()==level) res.push_back(root->val);
        recursion(root->right,level+1,res);
        recursion(root->left,level+1,res);
    }
};
