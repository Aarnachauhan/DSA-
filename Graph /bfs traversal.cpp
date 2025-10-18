gfg 
tc-o(n) + o(2e)
sc-o(3n) = o(n)
as there is list, queue , array

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int n=adj.size();
        int vis[n]={0};
        vis[0]=1;
        queue<int> q;
        q.push(0);
        vector<int>ans;
        while(!q.empty()){ //this loop runs for n times
            int node=q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto it : adj[node]){ //this for loop runs for total degress 
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return ans;
        
        }
};
