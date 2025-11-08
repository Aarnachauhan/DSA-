gfg




class Solution {
  public:
  bool bfs(int start, vector<vector<int>> &adj , vector<int> &vis){
      queue<pair<int , int>> q;
      vis[start]=1;
      q.push({start,-1});
      
      while(!q.empty()){
          int node=q.front().first;
          int parent=q.front().second;
          q.pop();
          
          for(auto neigh: adj[node]){
              if(!vis[neigh]){
                  vis[neigh]=1;
                  q.push({neigh,node});
              }
              //neigh is already visited
              else if(neigh !=parent){
                  return true;
              }
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
                if(bfs(i,adj,vis)){ //if we found cycle then return true;
                    return true; 
                }
            }
        }
        
        //end tak kuch nhi mila 
        return false;
        
    }
};
