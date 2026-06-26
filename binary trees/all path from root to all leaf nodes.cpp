gfg
problem name : Root to Leaf Paths



class Solution {
  public:
void solve(Node* node ,vector<vector<int>> &ans ,vector<int> &path  ){
    if(node==nullptr) return;
     path.push_back(node->data);
     
    if(node->left ==nullptr && node->right==nullptr){
        ans.push_back(path);
        path.pop_back();
        return;
    }
    
    
    solve(node->left,ans,path);
    solve(node->right,ans,path);
    
    path.pop_back();
    
}
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> ans;
        vector<int> path;
        solve(root,ans,path);
        if(root==nullptr) return ans;
        return ans;
        
    }
};
