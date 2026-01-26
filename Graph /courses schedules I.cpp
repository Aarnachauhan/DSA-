leetcode 207
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        // Step 1: adjacency list
        vector<vector<int>> adj(numCourses);
        for (auto &it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }
              // Step 2: Calculate indegree of each node
        vector<int> indegree(numCourses, 0);
        for (int u = 0; u < numCourses; u++) {
            for (int v : adj[u]) {
                indegree[v]++;
            }
        }

        // Step 3: Push nodes with indegree 0 into queue
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Step 4: BFS
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (int neigh : adj[node]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }

        if(topo.size()==numCourses) return true;
        return false;
    }
};
