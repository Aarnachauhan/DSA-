lc 200
Time complexity:
O(m × n) → We visit each cell once.
Space complexity:
O(min(m, n)) → In the worst case, BFS queue holds all cells of the smallest dimension (like a snake of land).

 class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='0') continue;
                cnt++;
                queue<pair<int,int>>q;
                q.push({i,j});
                grid[i][j]='0';
                
                int drow[]={-1,0,1,0};
                 int dcol[]={0,1,0,-1};
                while(!q.empty()){
                    auto node=q.front();
                    q.pop();
                    int r=node.first;
                    int c=node.second;

                    for(int k=0;k<4;k++){
                        int nrow=r+drow[k];
                        int ncol=c+dcol[k];

                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1'){
                          grid[nrow][ncol]='0';
                          q.push({nrow,ncol});
                        }
                    }
                }
            }
        }
        return cnt;
    }
};
