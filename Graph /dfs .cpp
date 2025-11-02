dfs- gfg
tc- // it will only traverse each node once.
sc- O(n) + o(n) + o(n) = o(n)
  //for storing n nodes , visited array , recursion stack space 
tc-o(n) + sigma (degrees) = o(n) + 2*E
//for every node we are iterating once but going and checking all its neighbours.
// sigma (degrees) = 2 * E 
  
  class Solution {
    private:
    void dfs(int node , vector<vector<int>> & adj , vector<int> &vis , vector<int> &ls){
        vis[node]=1;
        ls.push_back(node);
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,adj , vis , ls);
            }
        }
    }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int v=adj.size();
        vector<int> vis(v,0);
        int start=0;
        vector<int> ls;
        dfs(start,adj, vis , ls );
        return ls;
    }
};
