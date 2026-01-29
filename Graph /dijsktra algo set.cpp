gfg
why we prefer set and not pq

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
         // 1. Build adjacency list
        vector<vector<pair<int,int>>> adj(V);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt}); // remove if directed
        }
        
        // 2. Distance array
        vector<int> dist(V, 1e9);
        dist[src] = 0;
        
        // 3. Set: {distance, node}
        set<pair<int,int>> st;
        st.insert({0, src});
        
        // 4. Dijkstra
        while (!st.empty()) {
            auto it = *(st.begin());
            int node = it.second;
            int d = it.first;
            st.erase(it);
            
            for (auto &edge : adj[node]) {
                int adjNode = edge.first;
                int wt = edge.second;
                
                // Relaxation
                if (d + wt < dist[adjNode]) {
                    
                    // If already present, erase old pair
                    if (dist[adjNode] != 1e9) {
                        st.erase({dist[adjNode], adjNode});
                    }
                    
                    dist[adjNode] = d + wt;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        
        return dist;
    }
};
