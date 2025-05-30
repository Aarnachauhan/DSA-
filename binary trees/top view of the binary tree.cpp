gfg 

tc-o(n)
sc-o(n)
note: as we are storing thing in map. map will store it from line -2 to 2 . 

class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans;
        if(root==nullptr) return ans;
        map<int,int> mpp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            
            Node* node=it.first;
            int line=it.second;
            
            if(mpp.find(line)==mpp.end()) mpp[line]=node->data;
            
            if(node->left!=nullptr) q.push({node->left,line-1});
            
            if(node->right!=nullptr) q.push({node->right,line+1});
            
            
        }
        
        for(auto it:mpp){
            ans.push_back(it.second);
            
        }
        return ans;
    }
};
