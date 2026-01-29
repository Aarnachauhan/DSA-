gfg
tc-o(elogv)
sc-o(e+v)
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int> >> adj(V);
        for(auto &e: edges){
            int u=e[0];
            int v=e[1];
            int wt=e[2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        vector<int> dis(V,1e9);
        dis[src]=0;
        
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;
        //{dist,node}
        
        pq.push({0,src});
        
        //algo:
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            
            pq.pop();
            
            if(d>dis[node])continue;
            
            for(auto &it:adj[node]){
                int ajnode=it.first;
                int ajwt=it.second;
                
                if(dis[node]+ajwt<dis[ajnode]){
                    dis[ajnode]=dis[node]+ajwt;
                    pq.push({dis[ajnode],ajnode});
                }
            }
        }
        return dis;
        
    }
};
