gfg
tc-O((E+V) * logV) with the help of a binary heap.
Auxiliary Space: O(V)

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj[V];
        
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        priority_queue<pair<int,int> , vector<pair<int,int>>,
        greater<pair<int,int>>> pq;
        
        vector<bool>vis(V,0);
        
        int minwt=0;
        
        pq.push({0,0});
        
        while(!pq.empty()){
            auto [wt, node]=pq.top();
            pq.pop();
            
            if(vis[node]) continue;
            else{
                vis[node]=1;
                minwt+=wt;
            }
            
            for(auto &it : adj[node]){
                if(!vis[it[0]]) pq.push({it[1],it[0]});
            }
        }
        return minwt;
        
    }
};
