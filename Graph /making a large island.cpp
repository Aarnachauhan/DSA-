lc 827


class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();

        DisjointSet ds(n * n);

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // Connect all existing 1's
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {

                if (grid[row][col] == 0) continue;

                int nodeNo = row * n + col;

                for (int k = 0; k < 4; k++) {
                    int nr = row + dr[k];
                    int nc = col + dc[k];

                    if (nr >= 0 && nr < n &&
                        nc >= 0 && nc < n &&
                        grid[nr][nc] == 1) {

                        int adjNodeNo = nr * n + nc;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }

        int maxi = 0;

        // Try converting every 0 into 1
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {

                if (grid[row][col] == 1) continue;

                unordered_set<int> components;

                for (int k = 0; k < 4; k++) {

                    int nr = row + dr[k];
                    int nc = col + dc[k];

                    if (nr >= 0 && nr < n &&
                        nc >= 0 && nc < n &&
                        grid[nr][nc] == 1) {

                        components.insert(
                            ds.findUPar(nr * n + nc)
                        );
                    }
                }

                int totalSize = 1;

                for (auto parent : components) {
                    totalSize += ds.size[parent];
                }

                maxi = max(maxi, totalSize);
            }
        }

        // Handle all-1s case
        for (int cell = 0; cell < n * n; cell++) {
            maxi = max(maxi,
                       ds.size[ds.findUPar(cell)]);
        }

        return maxi;
    }
};
