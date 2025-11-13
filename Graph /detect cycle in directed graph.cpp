
gfg
class Solution {
public:
bool dfs(int node , vector<int> adj[] , vector<int> &vis,vector<int> &pathvis){
    vis[node]=1;
    pathvis[node]=1;
    for(int neigh : adj[node]){
        if(!vis[neigh]) {
                if(dfs(neigh, adj, vis, pathvis)) 
                    return true;  // cycle found
            }
            // Case 2: neighbour already in current path → cycle
            else if(pathvis[neigh]) {
                return true;
            }
    }
     pathvis[node] = 0;     // remove from path after recursion
     return false;
}
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int> adj[V];
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            
            adj[u].push_back(v);
            
        }
        vector<int> vis(V,0);
        vector<int> pathvis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathvis)) return true;
            }
        }
        return false;
    }
};
