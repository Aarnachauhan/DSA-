gfg
Time Complexity: O(E * log E) or O(E * log V) 

Sorting of edges takes O(E*logE) time. 
After sorting, we iterate through all edges and apply the find-union algorithm. The find and union operations can take at most O(logV) time.
So overall complexity is O(E*logE + E*logV) time. 
The value of E can be at most O(V2), so O(logV) and O(logE) are the same. Therefore, the overall time complexity is O(E * logE) or O(E*logV)
Auxiliary Space: O(E+V), where V is the number of vertices and E is the number of edges in the graph.


    
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
