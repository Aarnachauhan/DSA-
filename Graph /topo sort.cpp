gfg

class Solution {
  private:
  void dfs(int node,stack<int> &st, vector<vector<int>> &adj, vector<int> & vis ){
      vis[node]=1;
      for(int neigh: adj[node]){
          if(!vis[neigh]){
              dfs(neigh,st,adj,vis);
          }
      }
      st.push(node);
  }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
      //here edges is edge list 
      //we need to convert it to adj matrix :
        vector<vector<int>> adj(V);
        for (auto &it : edges){
            adj[it[0]].push_back(it[1]);
        }
        
        vector<int> vis(V,0);
        stack<int> st;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,st,adj,vis);
                
            }
        }
        
        vector<int> topo;
        while(!st.empty()){
            topo.push_back(st.top());
            st.pop();
        }
        return topo;
    }
};
