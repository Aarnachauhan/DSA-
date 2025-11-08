


class Solution {
  public:
  bool dfs(int v, vector<vector<int>> &adj , vector<int> &vis,int parent){
      
      vis[v]=1;
      for(int i : adj[v]){
          if(!vis[i]){
              if(dfs(i,adj,vis ,v)==true) return true;
          }
          else if(i!=parent){
              return true;
          }
      }
      return false;
      
  }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto edge : edges){
            int u=edge[0]; // we are making adjancy list
            int v= edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
            
        }
        
        vector<int> vis(V,0); //visited array 
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,-1)){ //if we found cycle then return true;
                    return true; 
                }
            }
        }
        
        //end tak kuch nhi mila 
        return false;
        
    }
};
