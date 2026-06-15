gfg

using bfs

class Solution {
  public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        
        //step1 : make adj list
        vector<vector<int>> adj(V);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        //traversal
        vector<vector<int>> ans;
        vector<int> vis(V,0);
        int cnt=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                cnt++;
                
                vector<int> comp;
                
                queue<int> q;
                q.push(i);
                vis[i]=1;
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    comp.push_back(node);
                    //neigh traversal
                    for(auto it:adj[node]){
                        if(!vis[it]){
                            vis[it]=1;
                            q.push(it);
                        }
                    }
                }
                ans.push_back(comp);
            }
        }
        return ans;
    }
};
