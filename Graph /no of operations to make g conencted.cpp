leetcode 1319
 class DisjointSet {
public:
 vector<int> parent, size;
    DisjointSet(int n) {
        size.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
          if(connections.size() < n-1) return -1;

        DisjointSet ds(n);
        int extraEdges = 0;

        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            if(ds.findUPar(u) == ds.findUPar(v)) extraEdges++;
            else ds.unionBySize(u, v);
        }

        int connectedComponents = 0;
        for(int i = 0; i<n; i++){
            if(ds.parent[i] == i) connectedComponents++;
        }

        if(extraEdges >= connectedComponents-1) return connectedComponents-1;
        return -1;
    }
};
