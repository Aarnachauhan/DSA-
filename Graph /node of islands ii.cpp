gfg

// User function Template for C++
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

    int findparent(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findparent(parent[node]);
    }

    void unionsize(int u, int v) {
        int pu = findparent(u);
        int pv = findparent(v);

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
   bool isvalid(int r, int c, int n, int m) {
        return (r >= 0 && r < n && c >= 0 && c < m);
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m);
        vector<vector<int>> vis(n,vector<int> (m,0));
        vector<int> ans;
        int cnt=0;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        
        for(auto &op:operators){
            int row=op[0];
            int col=op[1];
            
            //duplicate operation
            if(vis[row][col]==1){
                ans.push_back(cnt);
                continue;
            }
            vis[row][col]=1;
            cnt++;
            
            int nodeno=row*m + col;
            for(int k=0;k<4;k++){
                int nr=row+ dr[k];
                int nc=col+dc[k];
                
                if(isvalid(nr,nc,n,m) && vis[nr][nc]==1){
                    int adjnodeno=nr*m+nc;
                    
                    if(ds.findparent(nodeno)!=ds.findparent(adjnodeno)){
                        cnt--;
                        ds.unionsize(nodeno,adjnodeno);
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
