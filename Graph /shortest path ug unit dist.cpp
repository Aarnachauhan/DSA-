gfg
class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        vector<int> adj[V];
        for(auto &it :edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
        
        vector<int> dist(V,1e9);
        queue<int> q;
        dist[src]=0;
        q.push(src);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto &it:adj[node]){
                if(dist[node]+1<dist[it]){
                    dist[it]=1+ dist[node];
                    q.push(it);
                }
            }
        }
        for(int i = 0 ;i < V ; i++){
            if(dist[i] == 1e9) dist[i] = -1;
        }
        return dist;
        
    }
};
