gfg
int findParent(vector<int> &parent, int x) {
    if (parent[x] != x) parent[x] = findParent(parent, parent[x]);
    return parent[x];
}

int kruskalsMST(int V, vector<vector<int>> &edges) {
    sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
        return a[2] < b[2];
    });
    vector<int> parent(V), rank(V, 0);
    for (int i = 0; i < V; i++) parent[i] = i;
    int ans = 0;
    for (auto &e : edges) {
        int px = findParent(parent, e[0]);
        int py = findParent(parent, e[1]);
        if (px != py) {
            if (rank[px] < rank[py]) swap(px, py);
            parent[py] = px;
            if (rank[px] == rank[py]) rank[px]++;
            ans += e[2];
        }
    }
    return ans;
}
