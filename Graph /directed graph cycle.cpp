gfg
class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }

        // Step 2: Calculate indegree of each node
        vector<int> indegree(V, 0);
        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                indegree[v]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Step 4: BFS
       int cnt=0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;

            for (int neigh : adj[node]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }
        if(cnt==V) return false;
        return true;
    }
};
