gfg
tc-o(v+e)
sc-o(n)
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        //we will create a adjancy list from edges list
        vector<vector<int>> adj(V);
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            
            adj[u].push_back(v);
        }
        //count the indegrees of each node
         vector<int> indegree(V, 0);
        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                indegree[v]++;
            }
        }
        //push the node which has indegree=0
        
        queue<int> q;
        
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        //bfs
        vector<int> bfs;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            bfs.push_back(node);
            
            
            for(int neigh: adj[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }
        
        
       return bfs; 
        
    }
};
