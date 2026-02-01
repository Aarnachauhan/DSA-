gfg
TC- O(V*E)
//takes more time than dijkstra but good for negative edges.

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code her
        vector<int> d(V,1e8);
        d[src]=0;
        for(int i=0;i<V-1;i++){
            for(auto it: edges){
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                if(d[u]!=1e8 && d[u]+wt<d[v]){
                    d[v]=d[u]+wt;
                    
                }
            }
        }
        //nth iteration to check for negative cycle
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            
           if(d[u]!=1e8 && d[u]+wt<d[v]){
               return {-1};
           }
        }
        
        
        return d;
    }
};
