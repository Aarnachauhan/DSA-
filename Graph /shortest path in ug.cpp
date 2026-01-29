gfg
tc-o(ElogV + n)
  
  O(n) because of backtracking

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it: edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
            vector<int> dist(n+1,1e9);
            vector<int> parent(n+1);
            
            for(int i=1;i<=n;i++){
                parent[i]=i;
            }
            
            dist[1]=0;
            pq.push({0,1}); //dist,node
            
            while(!pq.empty()){
                int d=pq.top().first;
                int node=pq.top().second;
                pq.pop();
                
                
                for(auto &it:adj[node]){
                    int v=it.first;
                    int wt=it.second;
                    
                    if(d+wt<dist[v]){
                        dist[v]=d+wt;
                        parent[v]=node;
                        pq.push({dist[v],v});
                    }
                }
                
            }
            
            if(dist[n]==1e9) return {-1};
            vector<int> ans;
            int node=n;
            while(parent[node]!=node){
                ans.push_back(node);
                node=parent[node];
            }
            ans.push_back(1);
            ans.push_back(dist[n]);
            reverse(ans.begin(),ans.end());
            
            
            return ans;
            
    }
};
